#include <ceu_cstd/ceu_assert.h>
#include <stdio.h>
#include <stdlib.h>

void __cdecl _ceu_assert_impl(const char *message) {
    fputs(message, stderr);
    abort();
}
