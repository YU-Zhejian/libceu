#include "ceu_ystrlib/ceu_ystrlib_create.h"
#include "ceu_basic/ceu_c_utils.h"
#include "ceu_basic/ceu_fast_macros.h"
#include "ceu_ystrlib/ceu_ystrlib_convert.h"

ceu_ystr_t* ceu_ystr_create_empty(void)
{
    return ceu_ystr_create_sized(CEU_YSTR_DEFAULT_SIZE);
}

ceu_ystr_t* ceu_ystr_create_sized(ceu_size_t reserved_length)
{
    ceu_ystr_t* ceu_ystr = (ceu_ystr_t*)ceu_smalloc(sizeof(ceu_ystr_t));
    ceu_ystr->buff_length = reserved_length + 1;
    ceu_ystr->buff = (char*)ceu_scalloc(ceu_ystr->buff_length, sizeof(char));
    ceu_ystr->consumed_length = 0;
    return ceu_ystr;
}

void ceu_ystr_guarantee(ceu_ystr_t* ystr, ceu_size_t new_buffer_size)
{
	ceu_size_t i;
    if (ystr->buff_length >= new_buffer_size) {
        return; // Do nothing if the buffer is long enough.
    }
    ystr->buff_length = new_buffer_size;

    ystr->buff = (char*)ceu_sreallocarray(ystr->buff, ystr->buff_length, sizeof(char));
    for (i = ystr->consumed_length; i < ystr->buff_length; i++) {
        ystr->buff[i] = CEU_STRING_ENDING;
    }
}

ceu_ystr_t* ceu_ystr_copy(const ceu_ystr_t* ystr)
{
    return ceu_ystr_create_from_cstr_reserve(ystr->buff, ystr->buff_length - ystr->consumed_length - 1);
}
