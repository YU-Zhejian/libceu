cmake_minimum_required(VERSION 3.17)
project(libceu VERSION 0.1 LANGUAGES C)
set(CMAKE_C_STANDARD 11)

if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/cmake_vars.cmake")
    message(STATUS "Including cmake_vars.cmake")
    include("${CMAKE_CURRENT_LIST_DIR}/cmake_vars.cmake")
endif ()

include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/enable_debug.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/test_c_helloworld.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/test_cxx_helloworld.cmake")

include("${CMAKE_CURRENT_LIST_DIR}/cmake/libceu.cmake")

