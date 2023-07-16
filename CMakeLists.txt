cmake_minimum_required(VERSION 3.11)
set(CMAKE_C_STANDARD 11)
project(libceu VERSION 0.1 LANGUAGES C)

include(CheckLanguage)
include(CheckIncludeFile)
include(CheckIncludeFileCXX)
check_language(CXX)
if (CMAKE_CXX_COMPILER)
    set(CMAKE_CXX_STANDARD 11)
    enable_language(CXX)
endif ()

if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/cmake_vars.cmake")
    message(STATUS "Including cmake_vars.cmake")
    include("${CMAKE_CURRENT_LIST_DIR}/cmake_vars.cmake")
endif ()

include("CheckSymbolExists")
include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/enable_debug.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/test_c_helloworld.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/test_c__bool.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/test_c_inline.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/test_c__Noreturn.cmake")

if (CMAKE_CXX_COMPILER)
    include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/test_cxx_helloworld.cmake")
endif ()

check_symbol_exists(snprintf "stdio.h" CEU_HAVE_SNPRINTF)
check_symbol_exists(strncpy_s "string.h" CEU_HAVE_STRNCPY_S)
check_symbol_exists(_snprintf "stdio.h" CEU_HAVE__SNPRINTF)

check_include_file("stdbool.h" CEU_HAVE_INCLUDE_STDBOOL_H)
check_include_file("VersionHelpers.h" CEU_HAVE_INCLUDE_VERSIONHELPERS_H)

configure_file(
        "${CMAKE_CURRENT_LIST_DIR}/include/libceu_stddef.h.in"
        "${CMAKE_CURRENT_LIST_DIR}/include/libceu_stddef.h"
)

include("${CMAKE_CURRENT_LIST_DIR}/cmake/libceu.cmake")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/lib/")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/bin/")
