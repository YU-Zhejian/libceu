include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_find.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/test_c_helloworld.cmake")

if (NOT DEFINED LIBDEFLATE_LIBRARY_SHARED)
    ceu_cm_enhanced_find_library(
            OUTPUT_VARIABLE CMAKE_CM_LIBDEFLATE_LIBRARY_SHARED
            PKGCONFIG_NAME libdeflate
            LINKER_FLAG deflate
    )
endif ()

if (NOT DEFINED LIBDEFLATE_LIBRARY_STATIC)
    ceu_cm_enhanced_find_library(
            STATIC
            OUTPUT_VARIABLE CMAKE_CM_LIBDEFLATE_LIBRARY_STATIC
            PKGCONFIG_NAME libdeflate
            LINKER_FLAG deflate
    )
endif ()

ceu_cm_enhanced_try_run(
        VARNAME LIBDEFLATE
        SRC_PATH "${CMAKE_CURRENT_LIST_DIR}/src/test_libdeflate.c"
        LINK_LIBRARIES "${CMAKE_CM_LIBDEFLATE_LIBRARY_SHARED}"
        DEPENDS C_HELLOWORLD
)
ceu_cm_enhanced_try_run(
        STATIC
        VARNAME LIBDEFLATE
        SRC_PATH "${CMAKE_CURRENT_LIST_DIR}/src/test_libdeflate.c"
        LINK_LIBRARIES "${CMAKE_CM_LIBDEFLATE_LIBRARY_STATIC}"
        DEPENDS C_HELLOWORLD
)

ceu_cm_print_test_status("libdeflate" LIBDEFLATE)
