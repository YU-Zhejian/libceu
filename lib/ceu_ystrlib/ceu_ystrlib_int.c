#include "ceu_ystrlib/ceu_ystrlib_int.h"
#include "ceu_basic/ceu_c_utils.h"
#include "ceu_ystrlib/ceu_ystrlib_convert.h"

static const char NULL_NUMBERS[] = { "0" };
static const char BIN_NUMBERS[] = { "01" };
static const char AUG_NUMBERS[] = { "01234567" };
static const char OCT_NUMBERS[] = { "0123456789" };
static const char HEX_NUMBERS[] = { "0123456789ABCDEF" };

ceu_ystr_t* ceu_ystr_from_uint(int base, ceu_uint64_t src_int)
{
    const char* numbers;
    char immc[64] = { 0 };
    ceu_size_t current_position = 0;
    char* retc;
    int i;
    if (base == 2) {
        numbers = BIN_NUMBERS;
    } else if (base == 8) {
        numbers = AUG_NUMBERS;
    } else if (base == 10) {
        numbers = OCT_NUMBERS;
    } else if (base == 16) {
        numbers = HEX_NUMBERS;
    } else {
        numbers = NULL_NUMBERS; // Stupid MSVC
        ceu_die_with_retv("Illegal raidx", 1);
    }
    if (src_int == 0) {
        immc[current_position] = '0';
        current_position += 1;
    }
    while (src_int > 0) {
        immc[current_position] = numbers[src_int % base];
        current_position += 1;
        src_int /= base;
    }
    retc = (char*)ceu_scalloc(current_position + 1, sizeof(char));
    for (i = 0; i < current_position; i++) {
        retc[i] = immc[current_position - i - 1];
    }
    return ceu_ystr_create_from_cstr_reserve(retc, 0);
}
