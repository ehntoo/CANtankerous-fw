set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_LINKER arm-none-eabi-gcc-ld)
set(CMAKE_AR arm-none-eabi-gcc-ar)

set(CMAKE_C_FLAGS "-Os -fwhole-program --specs=nosys.specs --specs=nano.specs")
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS})
set(CMAKE_LD_FLAGS "-Wl,--print-memory-usage")

# Do not try to compile for the host
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
