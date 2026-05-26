cmake_minimum_required(VERSION 3.22)
# Enable CMake support for ASM and C languages
enable_language(C ASM)

add_library(libraries STATIC)

# set(TINYUSB_DIR ${CMAKE_SOURCE_DIR}/libs/tinyusb)

# include(${TINYUSB_DIR}/src/CMakeLists.txt)

# tinyusb_sources_get(TINYUSB_SOURCES)

# file(GLOB TUSB_NETWORKING_SOURCES
#     ${TINYUSB_DIR}/lib/networking/*.c
# )

# file(GLOB TUSB_STM32_SOURCES ${TINYUSB_DIR}/src/portable/st/stm32_fsdev/*.c
#                          ${TINYUSB_DIR}/src/portable/st/typec/*.c
#                          ../TUSB/usb_descriptors.c)

# add_library(tinyusb STATIC 
#             ${TINYUSB_SOURCES}
#             ${TUSB_NETWORKING_SOURCES}
#             ${TUSB_STM32_SOURCES}
#             )

# target_include_directories(tinyusb PUBLIC 
#     ${TINYUSB_DIR}/src
#     ${TINYUSB_DIR}/src/common
#     ${TINYUSB_DIR}/src/device
#     ${TINYUSB_DIR}/src/class
#     ${TINYUSB_DIR}/src/host
#     ${TINYUSB_DIR}/hw
#     ${TINYUSB_DIR}/lib/networking
#     ../TUSB
# )

# target_compile_definitions(tinyusb PUBLIC
#     # Add user defined symbols
#     CFG_TUSB_MCU=OPT_MCU_STM32H7
#     CFG_TUSB_OS=OPT_OS_FREERTOS
#     CFG_TUSB_DEBUG=3
# )

set(LIB_SRC "cJSON/cJSON.c"
            "cJSON/cJSON_Utils.c"
            "littlefs/lfs_util.c"
            "littlefs/lfs.c"
            "nanoMODBUS/nanomodbus.c"
            "stm32-dp83848/dp83848.c")

target_sources(libraries PRIVATE
    ${LIB_SRC}
)

target_include_directories(libraries PUBLIC
    cJSON 
    littlefs
    nanoMODBUS
    stm32-dp83848
)


target_link_libraries(libraries PUBLIC
    stm32cubemx
)