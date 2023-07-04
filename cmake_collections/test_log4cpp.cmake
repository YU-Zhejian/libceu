# Search for log4cpp <https://log4cpp.sourceforge.net>
include("${CMAKE_CURRENT_LIST_DIR}/test_cxx_stdthread.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_find.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")

if (NOT DEFINED LOG4CPP_LIBRARY_SHARED)
    ceu_enhanced_find_library(
        OUTPUT_VARIABLE LOG4CPP_LIBRARY_SHARED
        PKGCONFIG_NAME log4cpp
        LINKER_FLAG log4cpp
    )
endif()

if(NOT DEFINED LOG4CPP_LIBRARY_STATIC)
    ceu_enhanced_find_library(
        STATIC
        OUTPUT_VARIABLE LOG4CPP_LIBRARY_STATIC
        PKGCONFIG_NAME log4cpp
        LINKER_FLAG log4cpp
    )
endif()

enhanced_try_run(
    VARNAME LOG4CPP
    SRC_PATH "test_log4cpp.cpp"
    LINK_LIBRARIES ${LOG4CPP_LIBRARY_SHARED} Threads::Threads
    DEPENDS CXX_STDTHREAD
)

enhanced_try_run(
    STATIC
    VARNAME LOG4CPP
    SRC_PATH "test_log4cpp.cpp"
    LINK_LIBRARIES ${LOG4CPP_LIBRARY_SATTIC} Threads::Threads
    DEPENDS CXX_STDTHREAD
)

ceu_print_test_status("log4cpp" LOG4CPP)
