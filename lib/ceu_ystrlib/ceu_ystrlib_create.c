#include "ceu_ystrlib/ceu_ystrlib.h"
#include "ceu_c_utils.h"
#include "ceu_cstd/ceu_string.h"

ceu_ystr_t* ceu_ystr_create_empty(){
	ceu_ystr_t* ceu_ystr = (ceu_ystr_t*) ceu_smalloc(sizeof(ceu_ystr));
	ceu_ystr->buff = (char*)ceu_scalloc(1, sizeof(char));
	ceu_ystr->consumed_length = 0;
	ceu_ystr->buff_length = 1;
	return ceu_ystr;
}
ceu_ystr_t* ceu_ystr_create_sized(size_t reserved_length){
	ceu_ystr_t* ceu_ystr = (ceu_ystr_t*) ceu_smalloc(sizeof(ceu_ystr));
	ceu_ystr->buff_length = reserved_length + 1;
	ceu_ystr->buff = (char*)ceu_scalloc(ceu_ystr->buff_length, sizeof(char));
	ceu_ystr->consumed_length = 0;
	return ceu_ystr;

}
ceu_ystr_t* ceu_ystr_create_from_cstr(char* cstr, size_t reserved_length){
	ceu_ystr_t* ceu_ystr = (ceu_ystr_t*) ceu_smalloc(sizeof(ceu_ystr));
	size_t sl = ceu_strlen(cstr);
	ceu_ystr->buff_length = sl + reserved_length + 1;
	ceu_ystr->buff = (char*)ceu_scalloc(ceu_ystr->buff_length, sizeof(char));
	ceu_ystr->consumed_length = sl;
	ceu_strncpy(ceu_ystr->buff, cstr, sl);
	return ceu_ystr;
}

