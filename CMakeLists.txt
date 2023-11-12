cmake_minimum_required(VERSION 3.11)
project(libceu VERSION 0.1 LANGUAGES C)

# CMake STDLib
include(CheckLanguage)
include(CheckIncludeFile)
include(CheckIncludeFileCXX)
include(CheckSymbolExists)
include(GNUInstallDirs)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_LIBDIR}")


# Inclusion of custom variables
if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/cmake_vars.cmake")
    message(STATUS "Including cmake_vars.cmake")
    include("${CMAKE_CURRENT_LIST_DIR}/cmake_vars.cmake")
endif ()

# Enable C++ compiler if possible
if(NOT DEFINED CMAKE_C_STANDARD)
    set(CMAKE_C_STANDARD 11)
endif()
set(CMAKE_C_STANDARD_REQUIRED TRUE)
check_language(CXX)
if (CMAKE_CXX_COMPILER)
    if(NOT DEFINED CMAKE_CXX_STANDARD)
        set(CMAKE_CXX_STANDARD 11)
    endif()
    set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
    enable_language(CXX)
endif ()

# Include link option optimizer
include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/enable_debug.cmake")

# Check C Functions
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
        "include/ceu_basic/libceu_stddef.h.in"
        "include/ceu_basic/libceu_stddef.h"
)

include("${CMAKE_CURRENT_LIST_DIR}/cmake/libceu.cmake")

file(GLOB CEU_INCLUSIONS "${CMAKE_CURRENT_LIST_DIR}/include/ceu_*")
install(DIRECTORY ${CEU_INCLUSIONS} TYPE INCLUDE)

include_directories("${CMAKE_CURRENT_LIST_DIR}/include_priv/")
include_directories("${CMAKE_CURRENT_BINARY_DIR}/include/")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/lib/")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/bin/")
if (CEU_CM_SHOULD_ENABLE_TEST)
    enable_testing()
    add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/test/")
endif ()
