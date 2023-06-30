# TODO: Refactor this piece of sh*t

include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_find.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/test_cxx_stdthread.cmake")
ceu_enhanced_find_library(OUTPUT_VARIABLE GTEST_LIBRARY_SHARED PKGCONFIG_NAME gtest LINKER_FLAG gtest)
ceu_enhanced_find_library(STATIC OUTPUT_VARIABLE GTEST_LIBRARY_STATIC PKGCONFIG_NAME gtest LINKER_FLAG gtest)

ceu_enhanced_find_library(OUTPUT_VARIABLE GTEST_MAIN_LIBRARY_SHARED PKGCONFIG_NAME gtest_main LINKER_FLAG gtest_main)
ceu_enhanced_find_library(STATIC OUTPUT_VARIABLE GTEST_MAIN_LIBRARY_STATIC PKGCONFIG_NAME gtest_main LINKER_FLAG gtest_main)

set(GTEST_MAIN_LIBRARY_SHARED ${GTEST_MAIN_LIBRARY_SHARED} ${GTEST_LIBRARY_SHARED} Threads::Threads)
set(GTEST_MAIN_LIBRARY_SHARED ${GTEST_MAIN_LIBRARY_STATIC} ${GTEST_LIBRARY_STATIC} Threads::Threads)

if (GTEST_MAIN_LIBRARY_SHARED)
    enhanced_try_run(VARNAME GTEST SRC_PATH "test_gtest.cpp" LINK_LIBRARIES "${GTEST_MAIN_LIBRARY_SHARED}")
else ()
    set(HAVE_WORKING_GTEST_COMPILE_SHARED FALSE CACHE BOOL "doc")
    set(HAVE_WORKING_GTEST_RUN_SHARED 127 CACHE BOOL "doc")
endif ()
if (GTEST_MAIN_LIBRARY_STATIC)
    enhanced_try_run(STATIC VARNAME GTEST SRC_PATH "test_gtest.cpp" LINK_LIBRARIES "${GTEST_MAIN_LIBRARY_STATIC}")
else ()
    set(HAVE_WORKING_GTEST_COMPILE_STATIC FALSE CACHE BOOL "doc")
    set(HAVE_WORKING_GTEST_RUN_STATIC 127 CACHE BOOL "doc")
endif ()

ceu_print_test_status("gtest (cxx)" GTEST "GTEST_MAIN")
