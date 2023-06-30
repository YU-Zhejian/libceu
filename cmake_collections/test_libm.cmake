# Would firstly test whether C program runs without libm.

include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")

enhanced_try_run(VARNAME C_NO_LIBM SRC_PATH "test_libm.c")
enhanced_try_run(STATIC VARNAME C_NO_LIBM SRC_PATH "test_libm.c")
ceu_print_test_status("libm: no -lm (c)" C_NO_LIBM)

if(NOT DEFINED LIBM_LIBRARY_SHARED)
    ceu_enhanced_find_library(OUTPUT_VARIABLE LIBM_LIBRARY_SHARED LINKER_FLAG m)
endif()

if(NOT DEFINED LIBM_LIBRARY_STATIC)
    ceu_enhanced_find_library(STATIC OUTPUT_VARIABLE LIBM_LIBRARY_STATIC LINKER_FLAG m)
endif()

enhanced_try_run(VARNAME C_WITH_LIBM SRC_PATH "test_libm.c" LINK_LIBRARIES ${LIBM_LIBRARY_SHARED})
enhanced_try_run(STATIC VARNAME C_WITH_LIBM SRC_PATH "test_libm.c" LINK_LIBRARIES ${LIBM_LIBRARY_STATIC})
ceu_print_test_status("libm: with -lm (c)" C_WITH_LIBM)
