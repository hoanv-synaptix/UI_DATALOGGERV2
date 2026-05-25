function(ui_parse_generated_csources list_file base_dir out_var)
    if(NOT EXISTS "${list_file}")
        message(FATAL_ERROR "Missing generated source list: ${list_file}")
    endif()

    file(STRINGS "${list_file}" _generated_lines)
    set(_result)

    foreach(_line IN LISTS _generated_lines)
        if(_line MATCHES "GEN_CSRCS[ \t]*\\+=")
            string(REGEX REPLACE ".*GEN_CSRCS[ \t]*\\+=[ \t]*" "" _items "${_line}")
            separate_arguments(_items UNIX_COMMAND "${_items}")
            foreach(_item IN LISTS _items)
                if(_item MATCHES "\\.c$")
                    list(APPEND _result "${base_dir}/${_item}")
                endif()
            endforeach()
        endif()
    endforeach()

    set(${out_var} "${_result}" PARENT_SCOPE)
endfunction()

set(UI_GENERATED_CORE_SRCS
    "ui/generated/events_init.c"
    "ui/generated/gui_guider.c"
    "ui/generated/setup_scr_scr_base.c"
    "ui/generated/setup_scr_scr_booting.c"
    "ui/generated/widgets_init.c"
)

ui_parse_generated_csources(
    "${CMAKE_CURRENT_LIST_DIR}/images/images_list.mk"
    "ui/generated/images"
    UI_GENERATED_IMAGE_SRCS
)

ui_parse_generated_csources(
    "${CMAKE_CURRENT_LIST_DIR}/images/lottie_list.mk"
    "ui/generated/images"
    UI_GENERATED_LOTTIE_SRCS
)

ui_parse_generated_csources(
    "${CMAKE_CURRENT_LIST_DIR}/guider_fonts/fonts_list.mk"
    "ui/generated/guider_fonts"
    UI_GENERATED_FONT_SRCS
)

set(UI_GENERATED_CUSTOM_FONT_SRCS)
