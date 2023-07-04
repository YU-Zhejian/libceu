include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_find.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")

if(NOT DEFINED LIBBZ2_LIBRARY_SHARED)
    ceu_enhanced_find_library(OUTPUT_VARIABLE LIBBZ2_LIBRARY_SHARED LINKER_FLAG bz2)
endif()

if (NOT DEFINED LIBBZ2_LIBRARY_STATIC)
    ceu_enhanced_find_library(STATIC OUTPUT_VARIABLE LIBBZ2_LIBRARY_STATIC LINKER_FLAG bz2)
endif()

enhanced_try_run(
    VARNAME LIBBZ2
    SRC_PATH "test_libbz2.c"
    LINK_LIBRARIES "${LIBBZ2_LIBRARY_SHARED}"
    DEPENDS C_HELLOWORLD
)
enhanced_try_run(
    STATIC
    VARNAME LIBBZ2
    SRC_PATH "test_libbz2.c"
    LINK_LIBRARIES "${LIBBZ2_LIBRARY_STATIC}"
    DEPENDS C_HELLOWORLD
)

ceu_print_test_status("libbz2" LIBBZ2)
