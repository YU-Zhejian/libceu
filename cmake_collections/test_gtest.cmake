# include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")
# include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_find.cmake")
# include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")
# include("${CMAKE_CURRENT_LIST_DIR}/test_cxx_stdthread.cmake")

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
