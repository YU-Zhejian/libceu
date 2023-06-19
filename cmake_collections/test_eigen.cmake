include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")

enhanced_try_run(VARNAME LIBEIGEN SRC_PATH "test_eigen.cpp")
enhanced_try_run(STATIC VARNAME LIBEIGEN SRC_PATH "test_eigen.cpp")

print_test_status("eigen" LIBEIGEN LIBEIGEN)
