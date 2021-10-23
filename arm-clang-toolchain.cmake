set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(triple armv8m-none-eabi)

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_COMPILER_TARGET ${triple})
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_COMPILER_TARGET ${triple})
set(CMAKE_ASM_COMPILER clang)
set(CMAKE_ASM_COMPILER_TARGET ${triple})
set(CMAKE_AR llvm-ar)

set(CMAKE_C_FLAGS "-Oz -nostdlib")
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS})
set(CMAKE_ASM_FLAGS "-D_start=main")

# Do not try to compile for the host
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Set up the sysroot to point at an arm-none-eabi toolchain
execute_process(
  COMMAND arm-none-eabi-gcc --print-sysroot
  OUTPUT_VARIABLE CMAKE_SYSROOT
  OUTPUT_STRIP_TRAILING_WHITESPACE
)
