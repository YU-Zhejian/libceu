#include <stdlib.h>

// TODO: Refactor to use ystrlib

#include "ceu_basic/ceu_c_utils.h"
#include "ceu_basic/ceu_fast_macros.h"
#include "ceu_cstd/ceu_stdint.h"
#include "ceu_cstd/ceu_stdio/ceu_printf_core.h"
#include "ceu_cstd/ceu_string.h"
#include "ceu_ystrlib/ceu_ystrlib_convert.h"
#include "ceu_ystrlib/ceu_ystrlib_gc.h"
#include "ceu_ystrlib/ceu_ystrlib_int.h"
#include <ceu_cstd/ceu_stddef.h>

// TODO: Here warns a -Wunused-but-set-parameter.
static void clear_ceu_printf_flags_t(ceu_printf_flags_t pf)
{
    pf.CEU_PRINTF_FLAG_MINUS = false;
    pf.CEU_PRINTF_FLAG_PLUS = false;
    pf.CEU_PRINTF_FLAG_SHARP = false;
    pf.CEU_PRINTF_FLAG_SPACE = false;
    pf.CEU_PRINTF_FLAG_ZERO = false;
}

/*!
 * Next position if current position is not line ending, otherwise report line endings.
 *
 * This function is safe but inefficient, as it would measure buffer length to prevent overflow all the time.
 *
 * @param buff The string as buffer.
 * @param pos Position to peek.
 * @return As described.
 */
static char ceu_buff_peek(const char* buff, ceu_size_t pos)
{
    ceu_size_t buff_len = ceu_strlen(buff);
    if (pos >= buff_len) {
        return CEU_STRING_ENDING;
    }
    return buff[pos + 1];
}

static ceu_size_t ceu_printf_append_str_to_buff(char* buff, ceu_size_t current_buffer_position, const char* arg)
{
    int current_arg_position = 0;
    while (arg[current_arg_position] != CEU_STRING_ENDING) {
        buff[current_buffer_position] = arg[current_arg_position];
        current_arg_position += 1;
        current_buffer_position += 1;
    }
    return current_buffer_position;
}

/*!
 * Pad blanks and add symbol.
 * @param converted_str
 * @param arg_numeric_sign_char
 * @param dest_length Length of the string after being padded.
 * @param ceu_printf_flag_minus If this is set to true, the result of the conversion is left-justified
 * within the field (by default it is right-justified)
 * @param padding_char
 */
static char* ceu_printf_pad_blanks(const char* converted_str, char arg_numeric_sign_char, ceu_size_t dest_length,
    bool ceu_printf_flag_minus, char padding_char)
{
    ceu_size_t current_length = ceu_strlen(converted_str);
    char* imm_str = CEU_NULL;
    char* return_str;

    if (arg_numeric_sign_char != CEU_STRING_ENDING) {
        current_length += 1;
    }
    imm_str = (char*)ceu_scalloc(current_length + 1, sizeof(char));
    if (arg_numeric_sign_char != CEU_STRING_ENDING) {
        imm_str[0] = arg_numeric_sign_char;
        ceu_printf_append_str_to_buff(imm_str, 1, converted_str);
    } else {
        ceu_printf_append_str_to_buff(imm_str, 0, converted_str);
    }
    if (current_length >= dest_length) {
        return imm_str;
    } // FIXME: Wrong! If padding_char = ' ', will add sign and pad; '0'
    // otherwise.
    return_str = (char*)ceu_scalloc(dest_length + 1, sizeof(char));
    if (ceu_printf_flag_minus) {
        ceu_printf_append_str_to_buff(return_str, 0, imm_str);
        while (current_length < dest_length) {
            current_length += 1;
            return_str[current_length] = padding_char;
        }
    } else {
        ceu_size_t i;
        for (i = 0; i < dest_length - current_length; i++) {
            return_str[i] = padding_char;
        }
        ceu_printf_append_str_to_buff(return_str, dest_length - current_length, imm_str);
    }
    ceu_free_non_null(imm_str);
    return return_str;
}
ceu_printf_ret_t ceu_vsnprintf_core(char* buff, ceu_size_t max_print_n_char, const char* fmt, va_list* args)
{
    ceu_printf_ret_t rett;
    int current_state;
    int minimum_field_width;
    int precision;
    int length;
    char current_char;
    char next_char;
    ceu_printf_flags_t pf;
    ceu_uint64_t arg_uint; // Value of the argument if it is unsigned int.
    ceu_int64_t arg_int; // Value of the argument if it is signed int.
    long double arg_dbl; // Value of the argument if it is float or double.
    void* arg_pointer; // Value of the argument if it is a pointer.
    char* arg_str; // Value of the argument if it is a string.
    char* converted_str; // Value of string that is converted from integer
    char* converted_padded_str;
    char arg_numeric_sign_char; // Sign of the numeric, should be ' ' (see flags),
                                // '+', '-' or CEU_STRING_ENDING (disabled)
    char padding_char; // Padding char, should be ' ' or '0'
    bool arg_int_is_negative;
    ceu_ystr_t* converted_ystr; // Temporary stage for integers.

    rett.current_buffer_position = 0;
    rett.current_fmt_position = 0;
    current_state = CEU_PRINTF_PARSING_COMMON_CHAR;
    // pf = {0}; // FIXME: { 0 } have error on Microoft Visual Studio 2010.
    minimum_field_width = 0;
    precision = 0;
    length = -1;
    current_char = fmt[rett.current_fmt_position];
    next_char = ceu_buff_peek(fmt, rett.current_fmt_position);

    arg_uint = 0;
    arg_int = 0;
    arg_dbl = 0.0;
    arg_pointer = CEU_NULL;
    arg_str = CEU_NULL;
    converted_str = CEU_NULL;
    converted_padded_str = CEU_NULL;
    arg_numeric_sign_char = CEU_STRING_ENDING;
    padding_char = ' ';
    arg_int_is_negative = false;

    while (current_char != CEU_STRING_ENDING) {
        switch (current_state) {
        case CEU_PRINTF_PARSING_COMMON_CHAR:
            if (current_char == '%') {
                switch (next_char) {
                case CEU_STRING_ENDING: // Pre-mature termination of % formats
                    abort(); // TODO: Except
                    break;
                case '%': // Ordinary %%
                    buff[rett.current_buffer_position] = '%';
                    rett.current_fmt_position += 1;
                    rett.current_buffer_position += 1;
                    break;
                default: // Start parsing flags
                    current_state = CEU_PRINTF_PARSING_FLAGS;

                    clear_ceu_printf_flags_t(pf);
                    minimum_field_width = 0;
                    precision = 0;
                    length = -1;
                    arg_int_is_negative = false;
                    arg_uint = 0;
                    arg_int = 0;
                    arg_dbl = 0.0;
                    arg_pointer = CEU_NULL;
                    arg_str = CEU_NULL;
                    converted_str = CEU_NULL;
                    arg_numeric_sign_char = CEU_STRING_ENDING, padding_char = ' ';
                    converted_padded_str = CEU_NULL;
                    break;
                }
            } else {
                if (rett.current_buffer_position == max_print_n_char) {
                    goto overflow;
                }
                buff[rett.current_buffer_position] = current_char;
                rett.current_buffer_position += 1;
                current_state = CEU_PRINTF_PARSING_COMMON_CHAR;
            }
            rett.current_fmt_position += 1;
            break;
        case CEU_PRINTF_PARSING_FLAGS:
            switch (current_char) {
            case '-':
                pf.CEU_PRINTF_FLAG_MINUS = true;
                break;
            case '+':
                pf.CEU_PRINTF_FLAG_PLUS = true;
                break;
            case ' ':
                pf.CEU_PRINTF_FLAG_SPACE = true;
                break;
            case '#':
                pf.CEU_PRINTF_FLAG_SHARP = true;
                break;
            case '0':
                pf.CEU_PRINTF_FLAG_ZERO = true;
                break;
            default:
                current_state = CEU_PRINTF_PARSING_MINIMUM_FIELD_WIDTH;
                rett.current_fmt_position -= 1;
                break;
            };
            rett.current_fmt_position += 1;
            break;
        case CEU_PRINTF_PARSING_MINIMUM_FIELD_WIDTH:
            if (current_char == '*') {
                // TODO: Not implemented
                current_state = CEU_PRINTF_PARSING_PRECISION_PENDING_DOT;
            } else if (('0' < current_char) && (current_char < '9')) {
                minimum_field_width *= 10;
                minimum_field_width += current_char - '0';
            } else if (current_char == '.') {
                current_state = CEU_PRINTF_PARSING_PRECISION_AFTER_DOT;
            } else {
                // No dot -- CEU_PARSING_PRECISION skipped!
                // See next section for skipping this section
                current_state = CEU_PRINTF_PARSING_PRECISION_PENDING_DOT;
                rett.current_fmt_position -= 1;
            }
            rett.current_fmt_position += 1;
            break;
        case CEU_PRINTF_PARSING_PRECISION_PENDING_DOT:
            if (current_char == '*') {
                // TODO: Not implemented
                current_state = CEU_PRINTF_PARSING_LENGTH;
            } else if (current_char == '.') {
                current_state = CEU_PRINTF_PARSING_PRECISION_AFTER_DOT;
            } else {
                // No dot -- CEU_PARSING_PRECISION skipped!
                current_state = CEU_PRINTF_PARSING_LENGTH;
                rett.current_fmt_position -= 1;
            }
            rett.current_fmt_position += 1;
            break;
        case CEU_PRINTF_PARSING_PRECISION_AFTER_DOT:
            if (('0' < current_char) && (current_char < '9')) {
                precision *= 10;
                precision += current_char - '0';
            } else {
                current_state = CEU_PRINTF_PARSING_LENGTH;
                rett.current_fmt_position -= 1;
            }
            rett.current_fmt_position += 1;
            break;
        case CEU_PRINTF_PARSING_LENGTH:
            switch (current_char) {
            case 'h':
                if (next_char == 'h') {
                    length = CEU_PRINTF_LENGTH_hh;
                    rett.current_fmt_position += 1;
                } else {
                    length = CEU_PRINTF_LENGTH_h;
                }
                break;
            case 'l':
                if (next_char == 'l') {
                    length = CEU_PRINTF_LENGTH_ll;
                    rett.current_fmt_position += 1;
                } else {
                    length = CEU_PRINTF_LENGTH_l;
                }
                break;
            case 'L':
                length = CEU_PRINTF_LENGTH_L;
                break;
            case 'j':
                length = CEU_PRINTF_LENGTH_j;
                break;
            case 'z':
                length = CEU_PRINTF_LENGTH_z;
                break;
            case 't':
                length = CEU_PRINTF_LENGTH_t;
                break;
            default:
                rett.current_fmt_position -= 1;
                break;
            }
            current_state = CEU_PRINTF_PARSING_CONVENTION;
            rett.current_fmt_position += 1;
            break;
        case CEU_PRINTF_PARSING_CONVENTION:
            switch (current_char) {
            case 'd': // fallthrough
            case 'i':
                switch (length) {
                case -1: // Default int
                    arg_int = va_arg(*args, int);
                    break;
                case CEU_PRINTF_LENGTH_hh:
                    arg_int = (signed char)va_arg(*args, int);
                    break;
                case CEU_PRINTF_LENGTH_h:
                    arg_int = (short)va_arg(*args, int);
                    break;
                case CEU_PRINTF_LENGTH_l:
                    arg_int = va_arg(*args, long int);
                    break;
                case CEU_PRINTF_LENGTH_ll:
                    arg_int = va_arg(*args, long long int);
                    break;
                case CEU_PRINTF_LENGTH_j:
                    arg_int = va_arg(*args, ceu_uintmax_t);
                    break;
                case CEU_PRINTF_LENGTH_z:
                    arg_int = va_arg(*args, ceu_size_t);
                    break;
                // FIXME: Support tenporarily dropped
                // case CEU_PRINTF_LENGTH_t:
                //     arg_int = va_arg(*args, ptrdiff_t);
                //     break;
                default:
                    abort();
                    break;
                }
                // Requires precision and min_field_width!
                if (arg_int < 0) {
                    arg_int_is_negative = true;
                    arg_int = -arg_int;
                }

                converted_ystr = ceu_ystr_from_uint(10, arg_int);
                converted_str = ceu_ystr_to_cstr(converted_ystr);
                ceu_ystr_destroy(converted_ystr);
                if (pf.CEU_PRINTF_FLAG_SHARP) {
                    // Undefined behaviour
                }
                if (pf.CEU_PRINTF_FLAG_ZERO) {
                    if (pf.CEU_PRINTF_FLAG_MINUS) {
                        // CEU_PRINTF_FLAG_ZERO is ignored
                        padding_char = ' ';
                    } else {
                        padding_char = '0';
                    }
                }
                if ((pf.CEU_PRINTF_FLAG_SPACE) && (!arg_int_is_negative) && (!pf.CEU_PRINTF_FLAG_PLUS)) {
                    arg_numeric_sign_char = ' ';
                } else if (arg_int_is_negative) {
                    arg_numeric_sign_char = '-';
                } else if (pf.CEU_PRINTF_FLAG_PLUS) {
                    arg_numeric_sign_char = '+';
                } else {
                    arg_numeric_sign_char = CEU_STRING_ENDING;
                }
                converted_padded_str = ceu_printf_pad_blanks(converted_str, arg_numeric_sign_char, minimum_field_width,
                    pf.CEU_PRINTF_FLAG_MINUS, padding_char);

                rett.current_buffer_position = ceu_printf_append_str_to_buff(buff, rett.current_buffer_position, converted_padded_str);
                ceu_free_non_null(converted_str);
                ceu_free_non_null(converted_padded_str);
                break;
            case 's':
                arg_str = va_arg(*args, char*);
                switch (length) {
                case CEU_PRINTF_LENGTH_l: // Default wchar_t
                                          // TODO: not implemented, so fallthrough
                case -1: // Default char
                    rett.current_buffer_position = ceu_printf_append_str_to_buff(buff, rett.current_buffer_position, arg_str);
                    break;
                default:
                    abort();
                    break;
                }
            default:
                break;
            }
            current_state = CEU_PRINTF_PARSING_COMMON_CHAR;
            rett.current_fmt_position += 1;
        default:
            break; // unlikely
        }
        current_char = fmt[rett.current_fmt_position];
        next_char = ceu_buff_peek(fmt, rett.current_fmt_position);
    }
    return rett;
overflow:
    rett.current_buffer_position = -1;
    return rett;
}

ceu_printf_ret_t ceu_snprintf_core(char* buff, ceu_size_t max_print_n_char, const char* fmt, ...)
{
    ceu_printf_ret_t retv;
    va_list(args);
    va_start(args, fmt);
    retv = ceu_vsnprintf_core(buff, max_print_n_char, fmt, &args);
    va_end(args);
    return retv;
}
