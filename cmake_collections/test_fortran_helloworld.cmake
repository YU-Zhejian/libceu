include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")

enhanced_try_run(VARNAME FORTRAN_HELLOWORLD SRC_PATH "test_helloworld.f90")
enhanced_try_run(STATIC VARNAME FORTRAN_HELLOWORLD SRC_PATH "test_helloworld.f90")

print_test_status("helloworld (fortran)" FORTRAN_HELLOWORLD "")
