include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_find.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")

ceu_enhanced_find_library(OUTPUT_VARIABLE LIBBZ2_LIBRARY_SHARED PKGCONFIG_NAME bzip2 LINKER_FLAG bz2)
ceu_enhanced_find_library(STATIC OUTPUT_VARIABLE LIBBZ2_LIBRARY_STATIC PKGCONFIG_NAME bzip2 LINKER_FLAG bz2)

if (LIBBZ2_LIBRARY_SHARED)
    enhanced_try_run(VARNAME LIBBZ2 SRC_PATH "test_libbz2.c" LINK_LIBRARIES "${LIBBZ2_LIBRARY_SHARED}")
else ()
    set(HAVE_WORKING_LIBBZ2_RUN_SHARED 127 CACHE INTERNAL "doc")
    set(HAVE_WORKING_LIBBZ2_COMPILE_SHARED FALSE CACHE INTERNAL "doc")
endif ()
if (LIBBZ2_LIBRARY_STATIC)
    enhanced_try_run(STATIC VARNAME LIBBZ2 SRC_PATH "test_libbz2.c" LINK_LIBRARIES "${LIBBZ2_LIBRARY_STATIC}")
else ()
    set(HAVE_WORKING_LIBBZ2_RUN_STATIC 127 CACHE INTERNAL "doc")
    set(HAVE_WORKING_LIBBZ2_COMPILE_STATIC FALSE CACHE INTERNAL "doc")
endif ()

print_test_status("libbz2" LIBBZ2 LIBBZ2)