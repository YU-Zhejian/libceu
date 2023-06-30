include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")

enhanced_try_run(VARNAME C_HELLOWORLD SRC_PATH "test_helloworld.c")
enhanced_try_run(STATIC VARNAME C_HELLOWORLD SRC_PATH "test_helloworld.c")

ceu_print_test_status("helloworld (c)" C_HELLOWORLD)
