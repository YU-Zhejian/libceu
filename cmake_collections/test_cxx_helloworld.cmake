include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")

enhanced_try_run(VARNAME CXX_HELLOWORLD SRC_PATH "test_helloworld.cpp")
enhanced_try_run(STATIC VARNAME CXX_HELLOWORLD SRC_PATH "test_helloworld.cpp")

ceu_print_test_status("helloworld (cxx)" CXX_HELLOWORLD)
