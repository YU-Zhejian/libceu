cmake_minimum_required(VERSION 3.17)
project(libceu VERSION 0.1 LANGUAGES C CXX)
set(CMAKE_C_STANDARD 99)

include("${CMAKE_CURRENT_LIST_DIR}/dist/cmake_collections/get_highest_cxx_std.cmake")
ceu_get_highest_cxx_std(11 "")

if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/cmake_vars.cmake")
    message(STATUS "Including cmake_vars.cmake")
    include("${CMAKE_CURRENT_LIST_DIR}/cmake_vars.cmake")
endif()

include("${CMAKE_CURRENT_LIST_DIR}/dist/cmake_collections/enable_debug.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/dist/cmake_collections/test_c_helloworld.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/dist/cmake_collections/test_cxx_helloworld.cmake")


if (${HAVE_WORKING_C_HELLOWORLD_RUN_SHARED} EQUAL 0 AND
        ${HAVE_WORKING_CXX_HELLOWORLD_RUN_SHARED} EQUAL 0)
    set(LIBCEU_BUILD_SHARED TRUE)
    message(STATUS "LIBCEU: Will build shared libceu")
else ()
    message(FATAL_ERROR "LIBCEU: Will NOT build shared libceu!")
endif ()

if (${HAVE_WORKING_C_HELLOWORLD_RUN_STATIC} EQUAL 0 AND
        ${HAVE_WORKING_CXX_HELLOWORLD_RUN_STATIC} EQUAL 0)
    set(LIBCEU_BUILD_STATIC TRUE)
    message(STATUS "LIBCEU: Will build static libceu")
else ()
    message(STATUS "LIBCEU: Will NOT build static libceu")
endif ()

include("${CMAKE_CURRENT_LIST_DIR}/cmake/libceu.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/lib/CMakeLists.txt")
if (SHOULD_ENABLE_TEST)
    include("${CMAKE_CURRENT_LIST_DIR}/dist/cmake_collections/test_gtest.cmake")    
    include("${CMAKE_CURRENT_LIST_DIR}/test/CMakeLists.txt")
endif ()
