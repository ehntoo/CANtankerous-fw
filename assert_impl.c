#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "cmsis_compiler.h"

// Convenience structure that we can store items in
//  to print out later when we add logging.
typedef struct sAssertInfo {
  uint32_t pc;
  uint32_t lr;
  uint32_t line;
  // I don't suggest actually using these, but they
  // are included for the examples.
  char file[256];
  char msg[256];
} sAssertInfo;

sAssertInfo g_assert_info;

void __assert_func(const char *file,
                   int line,
                   const char *func,
                   const char *failedexpr) {
    snprintf(g_assert_info.msg, sizeof(g_assert_info.msg),
            "ASSERT: %s at %s\n", failedexpr, func);
    strncpy(g_assert_info.file, file, sizeof(g_assert_info.file));
    g_assert_info.line = line;

    __BKPT(1);
    while(1) {};
}
