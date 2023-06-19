include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_find.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")

ceu_enhanced_find_library(OUTPUT_VARIABLE LIBZ_LIBRARY_SHARED PKGCONFIG_NAME zlib LINKER_FLAG z)
ceu_enhanced_find_library(STATIC OUTPUT_VARIABLE LIBZ_LIBRARY_STATIC PKGCONFIG_NAME zlib LINKER_FLAG z)

if (LIBZ_LIBRARY_SHARED)
    enhanced_try_run(VARNAME LIBZ SRC_PATH "test_libz.c" LINK_LIBRARIES "${LIBZ_LIBRARY_SHARED}")
else ()
    set(HAVE_WORKING_LIBZ_RUN_SHARED 127 CACHE INTERNAL "doc")
    set(HAVE_WORKING_LIBZ_COMPILE_SHARED FALSE CACHE INTERNAL "doc")
endif ()
if (LIBZ_LIBRARY_STATIC)
    enhanced_try_run(STATIC VARNAME LIBZ SRC_PATH "test_libz.c" LINK_LIBRARIES "${LIBZ_LIBRARY_STATIC}")
else ()
    set(HAVE_WORKING_LIBZ_RUN_STATIC 127 CACHE INTERNAL "doc")
    set(HAVE_WORKING_LIBZ_COMPILE_STATIC FALSE CACHE INTERNAL "doc")
endif ()

print_test_status("libz" LIBZ LIBZ)
