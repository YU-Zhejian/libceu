include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")

ceu_cm_enhanced_try_run(
        VARNAME FORTRAN_HELLOWORLD
        SRC_PATH "${CMAKE_CURRENT_LIST_DIR}/src/test_helloworld.f90"
)
ceu_cm_enhanced_try_run(
        STATIC
        VARNAME FORTRAN_HELLOWORLD
        SRC_PATH "${CMAKE_CURRENT_LIST_DIR}/src/test_helloworld.f90"
)

ceu_cm_print_test_status("helloworld (fortran)" FORTRAN_HELLOWORLD)
