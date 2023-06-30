//
// Created by yuzj on 6/20/23.
//

#ifndef LIBCEU_CEU_H
#define LIBCEU_CEU_H
#define compile_time_libceu_version "0.1"

inline char* run_time_libceu_version(void){
	return compile_time_libceu_version;
}
#endif //LIBCEU_CEU_H
