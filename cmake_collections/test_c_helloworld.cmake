include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")

enhanced_try_run(VARNAME C_HELLOWORLD SRC_PATH "test_helloworld.c")
enhanced_try_run(STATIC VARNAME C_HELLOWORLD SRC_PATH "test_helloworld.c")
if (CMAKE_HOST_WIN32)
    set(CEU_CM_HAVE_WORKING_C_HELLOWORLD_COMPILE_SHARED FALSE CACHE INTERNAL "Force fail for shared compilations on Windows")
    set(CEU_CM_HAVE_WORKING_C_HELLOWORLD_RUN_SHARED 127 CACHE INTERNAL "Force fail for shared compilations on Windows")
endif ()
ceu_print_test_status("helloworld (c)" C_HELLOWORLD)
