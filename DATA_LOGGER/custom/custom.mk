
GEN_CSRCS += $(notdir $(wildcard $(PRJ_DIR)/custom/*.c))
GEN_CSRCS += $(notdir $(wildcard $(PRJ_DIR)/contract/generated/*.c))
GEN_CSRCS += $(notdir $(wildcard $(PRJ_DIR)/sim/*.c))

DEPPATH += --dep-path $(PRJ_DIR)/custom
DEPPATH += --dep-path $(PRJ_DIR)/contract/generated
DEPPATH += --dep-path $(PRJ_DIR)/sim
VPATH += :$(PRJ_DIR)/custom
VPATH += :$(PRJ_DIR)/contract/generated
VPATH += :$(PRJ_DIR)/sim

CFLAGS += "-I$(PRJ_DIR)/custom"
CFLAGS += "-I$(PRJ_DIR)/contract/generated"
CFLAGS += "-I$(PRJ_DIR)/sim"
AFLAGS += "-I$(PRJ_DIR)/custom"
AFLAGS += "-I$(PRJ_DIR)/contract/generated"
AFLAGS += "-I$(PRJ_DIR)/sim"
