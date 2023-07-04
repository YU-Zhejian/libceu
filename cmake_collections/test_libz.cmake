# Search for zlib <https://www.zlib.net>
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_find.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")

if (NOT DEFINED LIBZ_LIBRARY_SHARED)
    ceu_enhanced_find_library(OUTPUT_VARIABLE LIBZ_LIBRARY_SHARED PKGCONFIG_NAME zlib LINKER_FLAG z)
endif ()

if (NOT DEFINED LIBZ_LIBRARY_STATIC)
    ceu_enhanced_find_library(STATIC OUTPUT_VARIABLE LIBZ_LIBRARY_STATIC PKGCONFIG_NAME zlib LINKER_FLAG z)
endif ()

enhanced_try_run(
    VARNAME LIBZ
    SRC_PATH "test_libz.c"
    LINK_LIBRARIES "${LIBZ_LIBRARY_SHARED}"
    DEPENDS C_HELLOWORLD
)
enhanced_try_run(
    STATIC
    VARNAME LIBZ
    SRC_PATH "test_libz.c"
    LINK_LIBRARIES "${LIBZ_LIBRARY_STATIC}"
    DEPENDS C_HELLOWORLD
)

ceu_print_test_status("libz" LIBZ)
