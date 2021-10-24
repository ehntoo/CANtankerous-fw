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

set(CMAKE_C_FLAGS "-nostdlib")
set(CMAKE_C_FLAGS_DEBUG "-Og")
set(CMAKE_C_FLAGS_RELEASE "-O3")
set(CMAKE_C_FLAGS_MINSIZEREL "-Oz")

# Do not try to compile for the host
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Set up the sysroot to point at an arm-none-eabi toolchain
execute_process(
  COMMAND arm-none-eabi-gcc --print-sysroot
  OUTPUT_VARIABLE CMAKE_SYSROOT
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--defsym=_start=main")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L${CMAKE_SYSROOT}/../lib/gcc/arm-none-eabi/10.3.1/thumb/v8-m.main+fp/hard")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L ${CMAKE_SYSROOT}/lib/thumb/v8-m.main+fp/hard")
#
# execute_process(
#   COMMAND arm-none-eabi-gcc --print-libgcc-file-name ${CMAKE_C_FLAGS}
#   OUTPUT_VARIABLE CMAKE_EXE_LINKER_FLAGS
#   OUTPUT_STRIP_TRAILING_WHITESPACE
# )
