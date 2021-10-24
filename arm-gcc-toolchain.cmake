set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-gcc-ar)

set(CMAKE_C_FLAGS "-fwhole-program --specs=nosys.specs --specs=nano.specs")
set(CMAKE_C_FLAGS_DEBUG "-Og")
set(CMAKE_C_FLAGS_RELEASE "-O3")
set(CMAKE_C_FLAGS_MINSIZEREL "-Os")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--print-memory-usage")

# Do not try to compile for the host
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
