include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/test_cxx_helloworld.cmake")

if (NOT DEFINED Threads_FOUND)
    find_package(Threads)
endif ()

enhanced_try_run(
        VARNAME CXX_STDTHREAD
        SRC_PATH "${CMAKE_CURRENT_LIST_DIR}/src/test_stdthread.cpp"
        LINK_LIBRARIES Threads::Threads "${CEU_CM_LIBM_SHARED}"
        DEPENDS CXX_HELLOWORLD
)
enhanced_try_run(
        STATIC VARNAME CXX_STDTHREAD
        SRC_PATH "${CMAKE_CURRENT_LIST_DIR}/src/test_stdthread.cpp"
        LINK_LIBRARIES Threads::Threads "${CEU_CM_LIBM_SHARED}"
        DEPENDS CXX_HELLOWORLD
)


ceu_print_test_status("stdthread (cxx)" CXX_STDTHREAD)
