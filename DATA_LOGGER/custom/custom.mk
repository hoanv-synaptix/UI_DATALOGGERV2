
GEN_CSRCS += $(notdir $(wildcard $(PRJ_DIR)/custom/core/*.c))
GEN_CSRCS += $(notdir $(wildcard $(PRJ_DIR)/custom/components/*.c))
GEN_CSRCS += $(notdir $(wildcard $(PRJ_DIR)/custom/backend/*.c))
GEN_CSRCS += $(notdir $(wildcard $(PRJ_DIR)/custom/controllers/*.c))
GEN_CSRCS += $(notdir $(wildcard $(PRJ_DIR)/custom/tools/*.c))
GEN_CSRCS += cJSON.c cJSON_Utils.c

DEPPATH += --dep-path $(PRJ_DIR)/custom/core
DEPPATH += --dep-path $(PRJ_DIR)/custom/components
DEPPATH += --dep-path $(PRJ_DIR)/custom/backend
DEPPATH += --dep-path $(PRJ_DIR)/custom/controllers
DEPPATH += --dep-path $(PRJ_DIR)/custom/tools
DEPPATH += --dep-path $(PRJ_DIR)/libs/cJSON
VPATH += :$(PRJ_DIR)/custom/core
VPATH += :$(PRJ_DIR)/custom/components
VPATH += :$(PRJ_DIR)/custom/backend
VPATH += :$(PRJ_DIR)/custom/controllers
VPATH += :$(PRJ_DIR)/custom/tools
VPATH += :$(PRJ_DIR)/libs/cJSON

CFLAGS += "-I$(PRJ_DIR)/custom/core"
CFLAGS += "-I$(PRJ_DIR)/custom/components"
CFLAGS += "-I$(PRJ_DIR)/custom/backend"
CFLAGS += "-I$(PRJ_DIR)/custom/controllers"
CFLAGS += "-I$(PRJ_DIR)/custom/config"
CFLAGS += "-I$(PRJ_DIR)/custom/tools"
CFLAGS += "-I$(PRJ_DIR)/libs/cJSON"
AFLAGS += "-I$(PRJ_DIR)/custom/core"
AFLAGS += "-I$(PRJ_DIR)/custom/components"
AFLAGS += "-I$(PRJ_DIR)/custom/backend"
AFLAGS += "-I$(PRJ_DIR)/custom/controllers"
AFLAGS += "-I$(PRJ_DIR)/custom/config"
AFLAGS += "-I$(PRJ_DIR)/custom/tools"
AFLAGS += "-I$(PRJ_DIR)/libs/cJSON"
