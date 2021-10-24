CMAKE_MINIMUM_REQUIRED(VERSION 3.19)

project(cantankerous-fw LANGUAGES C ASM)
add_executable(cantankerous-fw)

set(SdkDir ${CMAKE_CURRENT_SOURCE_DIR}/mcux-sdk)
set(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_EXECUTABLE_SUFFIX_C ".elf")

# Set source files
target_sources(cantankerous-fw PUBLIC
    "${ProjDirPath}/cantankerous-fw.c"
    "${ProjDirPath}/board/clock_config.c"
    "${ProjDirPath}/board/pin_mux.c"
    "${SdkDir}/devices/LPC5514/drivers/fsl_clock.c"
    "${SdkDir}/drivers/common/fsl_common_arm.c"
    "${ProjDirPath}/startup.S"
    "${ProjDirPath}/irq.c"
    "${SdkDir}/devices/LPC5514/system_LPC5514.c"
    "${SdkDir}/drivers/lpc_gpio/fsl_gpio.c"
    "${ProjDirPath}/middleware/usb/device/usb_device_lpcip3511.c"
    "${ProjDirPath}/middleware/usb/phy/usb_phy.c"
)

target_compile_definitions(cantankerous-fw PRIVATE
    "CPU_LPC5514JBD64=1"
    "__STARTUP_CLEAR_BSS"
    "USB_STACK_BM"
    "USB_STACK_USE_DEDICATED_RAM=1"
    "FSL_OSA_BM_TASK_ENABLE=0"
    "FSL_OSA_BM_TIMER_CONFIG=0"
    "SERIAL_PORT_TYPE_UART=1"
    "SDK_DELAY_USE_DWT=1"
    "$<IF:$<CONFIG:Debug>,DEBUG,NDEBUG>"
)

target_include_directories(cantankerous-fw PRIVATE
    "${ProjDirPath}"
    "${SdkDir}/CMSIS/Core/Include"
    "${SdkDir}/devices/LPC5514"
    "${SdkDir}/devices/LPC5514/drivers"
    "${SdkDir}/drivers/common"
    "${SdkDir}/drivers/lpc_gpio"
    "${SdkDir}/drivers/lpc_iocon"
    "${SdkDir}/components/osa"
    "${SdkDir}/components/lists"
    "${ProjDirPath}/middleware/usb/include"
    "${ProjDirPath}/middleware/usb/output/npw/device_config/ip3511hs" # todo - replace with a stripped down config
)

target_compile_options(cantankerous-fw PRIVATE
    -mcpu=cortex-m33 -mthumb
    -march=armv8-m.main+fp+dsp
    -mfloat-abi=hard
    -mfpu=fpv5-sp-d16
    -g3
    -ffunction-sections
    -fdata-sections
    -std=c99
    -fshort-wchar
    -fno-common
    -ffreestanding
    -fverbose-asm
    -flto
    -fno-builtin
    -mno-unaligned-access
)

target_link_options(cantankerous-fw PRIVATE
    -mcpu=cortex-m33 -mthumb
    -march=armv8-m.main+fp+dsp
    -mfloat-abi=hard
    -mfpu=fpv5-sp-d16
    -g3
    -ffunction-sections
    -fdata-sections
    -std=gnu99
    -fshort-wchar
    -fno-common
    -ffreestanding
    -fverbose-asm
    -flto
    -mno-unaligned-access
    -Wl,-check-sections
    -Wl,-fatal-warnings
    -Wl,--gc-sections
    -Wl,--defsym=__stack_size__=0x800
    "-Wl,-Map=$<TARGET_FILE_DIR:cantankerous-fw>/cantankerous-fw.map"
)

target_link_options(cantankerous-fw PRIVATE "-T${ProjDirPath}/LPC5514_flash.ld" -static)

target_link_libraries(cantankerous-fw
    ${SdkDir}/devices/LPC5514/gcc/libpower_hardabi.a
)

# Create bin and hex
# add_custom_target(cantankerous-fw_bin DEPENDS "$<TARGET_FILE_DIR:cantankerous-fw>/cantankerous-fw.bin")
# add_custom_command(OUTPUT "$<TARGET_FILE_DIR:cantankerous-fw>/cantankerous-fw.bin" DEPENDS cantankerous-fw
#         COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:cantankerous-fw> "$<TARGET_FILE_DIR:cantankerous-fw>/cantankerous-fw.bin")
# add_custom_target(cantankerous-fw_hex DEPENDS "$<TARGET_FILE_DIR:cantankerous-fw>/cantankerous-fw.hex")
# add_custom_command(OUTPUT "$<TARGET_FILE_DIR:cantankerous-fw>/cantankerous-fw.hex" DEPENDS cantankerous-fw
#         COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:cantankerous-fw> "$<TARGET_FILE_DIR:cantankerous-fw>/cantankerous-fw.hex")
# add_custom_target(cantankerous-fw_binaries ALL DEPENDS cantankerous-fw DEPENDS cantankerous-fw_bin DEPENDS cantankerous-fw_hex)
#
#
# add_custom_target(cantankerous-fw_pre_build 
#         COMMAND /home/ehntoo/utilities/DAPLink/tools/pre_build_script.py
#         WORKING_DIRECTORY ${BUILD_DIR})
# add_dependencies(cantankerous-fw cantankerous-fw_pre_build)
#
#
#
# add_custom_command(TARGET cantankerous-fw_binaries POST_BUILD
#         COMMAND /home/ehntoo/utilities/DAPLink/tools/post_build_script_gcc.py
#         WORKING_DIRECTORY ${BUILD_DIR})
#
