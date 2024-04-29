#include "ceu_ystrlib/ceu_ystrlib_gc.h"
#include "ceu_basic/ceu_c_utils.h"
#include "ceu_basic/ceu_fast_macros.h"
#include "ceu_cstd/ceu_string.h"
#include "ceu_ystrlib/ceu_ystrlib_convert.h"

void ceu_ystr_destroy(ceu_ystr_t* ystr)
{
    ceu_free_non_null(ystr->buff);
    ystr->consumed_length = 0;
    ystr->buff_length = 0;
    ceu_free_non_null(ystr);
}

void ceu_ystr_clear(ceu_ystr_t* ystr)
{
    ceu_memset(ystr->buff, 0, ystr->consumed_length);
    ystr->consumed_length = 0;
    // Buffer length should be unchanged.
}

void ceu_ystr_clean(ceu_ystr_t* ystr)
{
    ystr->buff_length = DEFAULT_CEU_YSTR_SIZE + 1;
    ystr->buff = (char*)ceu_sreallocarray(ystr->buff, ystr->buff_length, sizeof(char));
    ceu_memset(ystr->buff, 0, ystr->consumed_length);
    ystr->consumed_length = 0;
}
void ceu_ystr_shrink(ceu_ystr_t* ystr, size_t new_buffer_size)
{
    if (ystr->buff_length <= new_buffer_size) {
        return; // Do nothing if the buffer is short enough.
    }
    ystr->buff_length = new_buffer_size;
    ystr->consumed_length = CEU_MIN(new_buffer_size - 1, ystr->consumed_length);
    ystr->buff = (char*)ceu_sreallocarray(ystr->buff, ystr->buff_length, sizeof(char));
    ystr->buff[ystr->consumed_length] = CEU_STRING_ENDING;
}
