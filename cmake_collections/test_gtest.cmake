include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_find.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/test_cxx_stdthread.cmake")

ceu_cm_enhanced_find_library(
        OUTPUT_VARIABLE CEU_CM_GTEST_LIBRARY_SHARED
        PKGCONFIG_NAME gtest
        LINKER_FLAG gtest
)
ceu_cm_enhanced_find_library(
        STATIC
        OUTPUT_VARIABLE CEU_CM_GTEST_LIBRARY_STATIC
        PKGCONFIG_NAME gtest
        LINKER_FLAG gtest
)

ceu_cm_enhanced_find_library(
        OUTPUT_VARIABLE CEU_CM_GTEST_MAIN_LIBRARY_SHARED
        PKGCONFIG_NAME gtest_main
        LINKER_FLAG gtest_main
)
ceu_cm_enhanced_find_library(
        STATIC
        OUTPUT_VARIABLE CEU_CM_GTEST_MAIN_LIBRARY_STATIC
        PKGCONFIG_NAME gtest_main
        LINKER_FLAG gtest_main
)

set(CEU_CM_GTEST_MAIN_LIBRARY_SHARED ${CEU_CM_GTEST_MAIN_LIBRARY_SHARED} ${CEU_CM_GTEST_LIBRARY_SHARED} Threads::Threads)
set(CEU_CM_GTEST_MAIN_LIBRARY_STATIC ${CEU_CM_GTEST_MAIN_LIBRARY_STATIC} ${CEU_CM_GTEST_LIBRARY_STATIC} Threads::Threads)

ceu_cm_enhanced_try_run(
        VARNAME GTEST
        SRC_PATH "${CMAKE_CURRENT_LIST_DIR}/src/test_gtest.cpp"
        LINK_LIBRARIES ${CEU_CM_GTEST_MAIN_LIBRARY_SHARED}
        DEPENDS CXX_STDTHREAD
)
ceu_cm_enhanced_try_run(
        STATIC
        VARNAME GTEST
        SRC_PATH "${CMAKE_CURRENT_LIST_DIR}/src/test_gtest.cpp"
        LINK_LIBRARIES ${CEU_CM_GTEST_MAIN_LIBRARY_STATIC}
        DEPENDS CXX_STDTHREAD
)

ceu_cm_print_test_status("gtest (cxx)" GTEST "GTEST_MAIN")
