#!/usr/bin/env python3
import csv
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "contract" / "register_map.csv"
OUT_DIR = ROOT / "contract" / "generated"
OUT_H = OUT_DIR / "ui_register_map.h"
OUT_C = OUT_DIR / "ui_register_map.c"

VALID_ACCESS = {"UI_WRITE", "BACKEND_WRITE", "RW"}
VALID_DOMAINS = {"wifi", "mqtt", "modbus", "dashboard", "system"}
VALID_TYPES = {"uint8", "int32", "bool", "string"}
MACRO_RE = re.compile(r"^REG_[A-Z0-9_]+$")
HEX_RE = re.compile(r"^0x[0-9A-Fa-f]{4}$")


def fail(message: str) -> None:
    print(f"register map error: {message}", file=sys.stderr)
    raise SystemExit(1)


def parse_uint(text: str, line: int, field: str) -> int:
    if not text:
        return 0
    try:
        value = int(text, 10)
    except ValueError:
        fail(f"line {line}: {field} must be a decimal integer, got {text!r}")
    if value < 0:
        fail(f"line {line}: {field} must be >= 0")
    return value


def parse_scale(text: str, line: int) -> str:
    value = text.strip() or "1.0"
    try:
        float(value)
    except ValueError:
        fail(f"line {line}: Scale must be a number, got {text!r}")
    if "." not in value and "e" not in value.lower():
        value = f"{value}.0"
    return value


def c_string(text: str) -> str:
    return text.replace("\\", "\\\\").replace("\"", "\\\"")


def load_rows() -> list[dict[str, str]]:
    if not SOURCE.exists():
        fail(f"missing source file: {SOURCE}")

    with SOURCE.open("r", encoding="utf-8-sig", newline="") as f:
        rows = list(csv.DictReader(f))

    if not rows:
        fail("register_map.csv has no rows")

    required = {
        "Address", "Macro", "Domain", "Access", "ValueType", "Scale",
        "Unit", "MaxLen", "Persist", "Owner", "Description",
    }
    missing = required - set(rows[0].keys())
    if missing:
        fail(f"missing columns: {', '.join(sorted(missing))}")

    seen_addr: dict[int, str] = {}
    seen_macro: set[str] = set()

    for index, row in enumerate(rows, start=2):
        if None in row:
            fail(f"line {index}: unexpected extra columns, quote text fields that contain commas")

        address = row.get("Address", "").strip()
        macro = row.get("Macro", "").strip()
        domain = row.get("Domain", "").strip()
        access = row.get("Access", "").strip()
        value_type = row.get("ValueType", "").strip()
        max_len_text = row.get("MaxLen", "").strip()

        if not HEX_RE.match(address):
            fail(f"line {index}: Address must be 0xNNNN, got {address!r}")
        if not MACRO_RE.match(macro):
            fail(f"line {index}: Macro must match REG_[A-Z0-9_]+, got {macro!r}")
        if domain not in VALID_DOMAINS:
            fail(f"line {index}: Domain must be one of {sorted(VALID_DOMAINS)}, got {domain!r}")
        if access not in VALID_ACCESS:
            fail(f"line {index}: Access must be one of {sorted(VALID_ACCESS)}, got {access!r}")
        if value_type not in VALID_TYPES:
            fail(f"line {index}: ValueType must be one of {sorted(VALID_TYPES)}, got {value_type!r}")

        max_len = parse_uint(max_len_text, index, "MaxLen")
        if value_type == "string" and max_len <= 0:
            fail(f"line {index}: string registers require MaxLen > 0")
        if value_type != "string" and max_len != 0:
            fail(f"line {index}: non-string registers must use MaxLen 0 or blank")

        addr_int = int(address, 16)
        if addr_int in seen_addr:
            fail(f"line {index}: duplicate address {address} also used by {seen_addr[addr_int]}")
        if macro in seen_macro:
            fail(f"line {index}: duplicate macro {macro}")

        seen_addr[addr_int] = macro
        seen_macro.add(macro)
        row["_scale_c"] = parse_scale(row.get("Scale", ""), index)
        row["_max_len"] = str(max_len)

    return rows


def generate_header(rows: list[dict[str, str]]) -> str:
    lines = [
        "#ifndef __UI_REGISTER_MAP_H_",
        "#define __UI_REGISTER_MAP_H_",
        "",
        "#include <stddef.h>",
        "#include <stdint.h>",
        "#include \"ui_register_types.h\"",
        "",
        "/* AUTO-GENERATED FILE. DO NOT MODIFY.",
        " * Source: contract/register_map.csv",
        " * Regenerate with: python tools/gen_ui_register_map.py",
        " */",
        "",
    ]

    for row in rows:
        desc = row["Description"].replace("*/", "")
        lines.append(f"#define {row['Macro']:<32} {row['Address']}U /* {desc} */")

    lines.extend([
        "",
        "extern const ui_register_desc_t g_ui_register_map[];",
        "extern const size_t g_ui_register_map_count;",
        "",
        "const ui_register_desc_t *ui_register_map_find(uint16_t address);",
        "",
        "#endif",
        "",
    ])
    return "\n".join(lines)


def generate_source(rows: list[dict[str, str]]) -> str:
    lines = [
        "#include \"ui_register_map.h\"",
        "",
        "const ui_register_desc_t g_ui_register_map[] = {",
    ]

    for row in rows:
        unit = c_string(row["Unit"].strip())
        lines.append(
            "    {"
            f"{row['Macro']}, "
            f"\"{row['Macro']}\", "
            f"UI_REGISTER_DOMAIN_{row['Domain'].upper()}, "
            f"UI_REGISTER_ACCESS_{row['Access']}, "
            f"UI_REGISTER_TYPE_{row['ValueType'].upper()}, "
            f"{row['_scale_c']}f, "
            f"\"{unit}\", "
            f"{row['_max_len']}U"
            "},"
        )

    lines.extend([
        "};",
        "",
        "const size_t g_ui_register_map_count = sizeof(g_ui_register_map) / sizeof(g_ui_register_map[0]);",
        "",
        "const ui_register_desc_t *ui_register_map_find(uint16_t address)",
        "{",
        "    size_t i;",
        "",
        "    for (i = 0; i < g_ui_register_map_count; ++i) {",
        "        if (g_ui_register_map[i].address == address) return &g_ui_register_map[i];",
        "    }",
        "    return NULL;",
        "}",
        "",
    ])
    return "\n".join(lines)


def main() -> int:
    rows = load_rows()
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    OUT_H.write_text(generate_header(rows), encoding="utf-8", newline="\n")
    OUT_C.write_text(generate_source(rows), encoding="utf-8", newline="\n")
    print(f"generated {OUT_H.relative_to(ROOT)}")
    print(f"generated {OUT_C.relative_to(ROOT)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
