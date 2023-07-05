include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/test_c_helloworld.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/test_libm.cmake")

if (NOT DEFINED OpenMP_C_FOUND)
    find_package(OpenMP)
endif ()

enhanced_try_run(
        VARNAME C_OPENMP
        SRC_PATH "${CMAKE_CURRENT_LIST_DIR}/src/test_openmp.c"
        DEPENDS C_HELLOWORLD
        LINK_LIBRARIES OpenMP::OpenMP_C "${CEU_CM_LIBM_SHARED}"
)

enhanced_try_run(
        STATIC
        VARNAME C_OPENMP
        SRC_PATH "${CMAKE_CURRENT_LIST_DIR}/src/test_openmp.c"
        DEPENDS C_HELLOWORLD
        LINK_LIBRARIES OpenMP::OpenMP_C "${CEU_CM_LIBM_STATIC}"
)

ceu_print_test_status("openmp (c)" C_OPENMP)
