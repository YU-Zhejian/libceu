#include <stdio.h>
#include "ceu_check/ceu_check_all.h"
#include "ceu_check/ceu_c_utils.h"

int main(void){
	char* s = get_full_info();
	printf("%s", s);
	ceu_free_non_null(s);
	return 0;
}
