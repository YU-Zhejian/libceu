include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/test_c_helloworld.cmake")

ceu_cm_enhanced_try_run(VARNAME C__BOOL SRC_PATH "${CMAKE_CURRENT_LIST_DIR}/src/test_c__bool.c" DEPENDS C_HELLOWORLD)

ceu_cm_enhanced_try_run(
    STATIC
    VARNAME
    C__BOOL
    SRC_PATH
    "${CMAKE_CURRENT_LIST_DIR}/src/test_c__bool.c"
    DEPENDS
    C_HELLOWORLD)

ceu_cm_enhanced_try_run(VARNAME C_BOOL SRC_PATH "${CMAKE_CURRENT_LIST_DIR}/src/test_c_bool.c" DEPENDS C_HELLOWORLD)

ceu_cm_enhanced_try_run(
    STATIC
    VARNAME
    C_BOOL
    SRC_PATH
    "${CMAKE_CURRENT_LIST_DIR}/src/test_c_bool.c"
    DEPENDS
    C_HELLOWORLD)
if(NOT DEFINED "${CMAKE_CURRENT_LIST_FILE}_INCLUDED")
    set("${CMAKE_CURRENT_LIST_FILE}_INCLUDED"
        TRUE
        CACHE BOOL "This file was included")
    ceu_cm_print_test_status("_Bool (c)" C__BOOL)
    ceu_cm_print_test_status("bool (c)" C_BOOL)
endif()
