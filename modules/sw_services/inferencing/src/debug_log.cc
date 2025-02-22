// Copyright 2021 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.

#include "xcore_printf.h"

// Implementation of DebugLog that needs to be defined for the
//  Tensorflow Lite Micro Runtime
__attribute__((weak))
extern "C" void DebugLog(const char *s) {
  xcore_utils_printf("%s", s);
}
