include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")

if (NOT DEFINED OpenMP_C_FOUND)
    find_package(OpenMP)
endif ()

if (NOT OpenMP_C_FOUND)
    set(HAVE_WORKING_C_OPENMP_RUN_SHARED FALSE CACHE INTERNAL "doc")
    set(HAVE_WORKING_C_OPENMP_COMPILE_SHARED 127 CACHE INTERNAL "doc")
    set(HAVE_WORKING_C_OPENMP_RUN_STATIC FALSE CACHE INTERNAL "doc")
    set(HAVE_WORKING_C_OPENMP_COMPILE_STATIC 127 CACHE INTERNAL "doc")
else ()
    enhanced_try_run(VARNAME C_OPENMP SRC_PATH "test_openmp.c" LINK_LIBRARIES OpenMP::OpenMP_C m)
    enhanced_try_run(STATIC VARNAME C_OPENMP SRC_PATH "test_openmp.c" LINK_LIBRARIES OpenMP::OpenMP_C m)
endif ()

ceu_print_test_status("openmp (c)" C_OPENMP)
