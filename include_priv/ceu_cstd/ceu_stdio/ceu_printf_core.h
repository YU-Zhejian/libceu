#ifndef CEU_CSTD_STDIO_PRINTF_CORE_H
#define CEU_CSTD_STDIO_PRINTF_CORE_H

#include <ceu_basic/ceu_fast_macros.h>
#include <ceu_cstd/ceu_stdbool.h>
#include <ceu_cstd/ceu_stddef.h> // ceu_size_t
#include <stdarg.h>

enum CEU_PRINTF_STATE_MACHINE {
    CEU_PRINTF_PARSING_COMMON_CHAR = 0,
    CEU_PRINTF_PARSING_FLAGS = 1,
    CEU_PRINTF_PARSING_MINIMUM_FIELD_WIDTH = 2,
    CEU_PRINTF_PARSING_PRECISION_PENDING_DOT = 3,
    CEU_PRINTF_PARSING_PRECISION_AFTER_DOT = 4,
    CEU_PRINTF_PARSING_LENGTH = 5,
    CEU_PRINTF_PARSING_CONVENTION = 6
};

enum CEU_PRINTF_LENGTH {
    CEU_PRINTF_LENGTH_h = 0,
    CEU_PRINTF_LENGTH_hh = 1,
    CEU_PRINTF_LENGTH_l = 2,
    CEU_PRINTF_LENGTH_ll = 3,
    CEU_PRINTF_LENGTH_j = 4,
    CEU_PRINTF_LENGTH_z = 5,
    CEU_PRINTF_LENGTH_t = 6,
    CEU_PRINTF_LENGTH_L = 7,
};

typedef struct
{
    /// -: the result of the conversion is left-justified within the field (by
    /// default it is right-justified)
    ceu_bool CEU_PRINTF_FLAG_MINUS;
    /// +: the sign of signed conversions is always prepended to the result of
    /// the conversion (by default the result is preceded by minus only when it
    /// is negative)
    ceu_bool CEU_PRINTF_FLAG_PLUS;
    /// space: if the result of a signed conversion does not start with a sign
    /// character, or is empty, space is prepended to the result. It is ignored
    /// if + flag is present.
    ceu_bool CEU_PRINTF_FLAG_SPACE;
    /// # : alternative form of the conversion is performed.
    /// See the table below for exact effects otherwise the behavior is
    /// undefined.
    ceu_bool CEU_PRINTF_FLAG_SHARP;
    /// 0 : for integer and floating point number conversions,
    /// leading zeros are used to pad the field instead of space characters.
    /// For integer numbers it is ignored if the precision is explicitly
    /// specified. For other conversions using this flag results in undefined
    /// behavior. It is ignored if - flag is present.
    ceu_bool CEU_PRINTF_FLAG_ZERO;
} ceu_printf_flags_t;

typedef struct
{
    ceu_size_t current_buffer_position;
    ceu_size_t current_fmt_position;
} ceu_printf_ret_t;

CEU_BEGIN_C_DECLS
ceu_printf_ret_t ceu_vsnprintf_core(char* buff, ceu_size_t max_print_n_char, const char* fmt, va_list* args);

ceu_printf_ret_t ceu_snprintf_core(char* buff, ceu_size_t max_print_n_char, const char* fmt, ...);

CEU_END_C_DECLS

#endif // CEU_CSTD_STDIO_PRINTF_CORE_H
