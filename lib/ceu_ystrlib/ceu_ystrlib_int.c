#include "ceu_ystrlib/ceu_ystrlib_int.h"
#include "ceu_basic/ceu_c_utils.h"
#include "ceu_basic/ceu_fast_macros.h"
#include "ceu_ystrlib/ceu_ystrlib.h"
#include "ceu_ystrlib/ceu_ystrlib_create.h"

static const char BIN_NUMBERS[] = { "01" };
static const char AUG_NUMBERS[] = { "01234567" };
static const char OCT_NUMBERS[] = { "0123456789" };
static const char HEX_NUMBERS[] = { "0123456789ABCDEF" };

ceu_ystr_t* ceu_ystr_from_uint(int raidx, uint64_t src_int)
{
    const char* numbers;
    if (raidx == 2) {
        numbers = BIN_NUMBERS;
    } else if (raidx == 8) {
        numbers = AUG_NUMBERS;
    } else if (raidx == 10) {
        numbers = OCT_NUMBERS;
    } else if (raidx == 16) {
        numbers = HEX_NUMBERS;
    } else {
        ceu_die_with_retv("Illegal raidx", 1);
    }
    char immc[64] = { 0 };
    int current_position = 0;
    while (src_int > 0) {
        immc[current_position] = numbers[src_int % raidx];
        current_position += 1;
        src_int /= raidx;
    }
    char* retc = (char*)ceu_scalloc(current_position + 1, sizeof(char));
    for (int i = 0; i < current_position; i++) {
        retc[i] = immc[current_position - i - 1];
    }
    return ceu_ystr_create_from_cstr_reserve(retc, 0);
}
