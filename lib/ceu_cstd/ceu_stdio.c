#include "ceu_cstd/ceu_stdio.h"
#include "ceu_cstd/ceu_stdio/ceu_printf_core.h"

// FIXME: This definition is incorrect.
size_t ceu_snprintf(char* buff, size_t max_print_n_char, const char* fmt, ...)
{
    va_list(args);
    va_start(args, fmt);
    ceu_printf_ret_t retv = ceu_vsnprintf_core(buff, max_print_n_char, fmt, &args);
    va_end(args);
    return retv.current_buffer_position;
}