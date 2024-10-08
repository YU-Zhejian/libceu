cmake_minimum_required(VERSION 3.11)
project(
    libceu
    VERSION 0.1
    LANGUAGES C)

# CMake STDLib
include(CheckLanguage)
include(CheckIncludeFile)
include(CheckIncludeFileCXX)
include(CheckSymbolExists)
include(GNUInstallDirs)
include(CPack)

set(CMAKE_INSTALL_RPATH "\$ORIGIN/../lib:${CMAKE_INSTALL_FULL_LIBDIR}")
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VENDOR "YU ZJ")

file(REMOVE_RECURSE "${CMAKE_BINARY_DIR}/compile_logs")

if(CMAKE_VERSION GREATER_EQUAL 3.12)
    add_compile_definitions(CEU_CM_UNDER_CMAKE)
else()
    add_compile_options("-DCEU_CM_UNDER_CMAKE")
endif()

if(MSVC)
    if(CMAKE_VERSION GREATER_EQUAL 3.12)
        add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    else()
        add_compile_options("-D_CRT_SECURE_NO_WARNINGS")
    endif()
endif()

# Inclusion of custom variables
if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/cmake_vars.cmake")
    message(STATUS "Including cmake_vars.cmake")
    include("${CMAKE_CURRENT_LIST_DIR}/cmake_vars.cmake")
endif()

# Enable C++ compiler if possible
if(NOT DEFINED CMAKE_C_STANDARD)
    set(CMAKE_C_STANDARD 99)
endif()
set(CMAKE_C_STANDARD_REQUIRED TRUE)
check_language(CXX)
if(CMAKE_CXX_COMPILER)
    if(NOT DEFINED CMAKE_CXX_STANDARD)
        set(CMAKE_CXX_STANDARD 98)
    endif()
    set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
    enable_language(CXX)
endif()

# Include link option optimizer
include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/enable_debug.cmake")

# Check C Functions
include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/test_c_helloworld.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/test_buildin_types.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/test_link.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/test_c89.cmake")
if(CMAKE_CXX_COMPILER)
    include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/test_cxx_helloworld.cmake")
    include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/test_cxx98.cmake")
endif()

include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/test_c_bool.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/test_c_noreturn.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake_collections/test_c___attribute__.cmake")

check_include_file("stdnoreturn.h" CEU_HAVE_INCLUDE_STDNORETURN_H)
check_include_file("cygwin/version.h" CEU_HAVE_INCLUDE_CYGWIN_VERSION_H)
check_include_file("sys/utsname.h" CEU_HAVE_INCLUDE_SYS_UTSNAME_H)
check_include_file("_mingw.h" CEU_HAVE_INCLUDE__MINGW_H)

configure_file("${CMAKE_CURRENT_LIST_DIR}/include_priv/ceu_basic/libceu_stddef_cmake.h.in"
               "${CMAKE_CURRENT_BINARY_DIR}/include/ceu_basic/libceu_stddef_cmake.h")

include("${CMAKE_CURRENT_LIST_DIR}/cmake/libceu.cmake")

file(GLOB CEU_INCLUSIONS "${CMAKE_CURRENT_LIST_DIR}/include/ceu_*")
install(DIRECTORY ${CEU_INCLUSIONS} TYPE INCLUDE)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/include/ceu_basic/libceu_stddef_cmake.h"
        DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ceu_basic/")
install(DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/cmake_collections"
        DESTINATION "${CMAKE_INSTALL_FULL_DATAROOTDIR}/libceu-${PROJECT_VERSION}")

include_directories("${CMAKE_CURRENT_LIST_DIR}/include/")
include_directories("${CMAKE_CURRENT_LIST_DIR}/include_priv/")
include_directories("${CMAKE_CURRENT_BINARY_DIR}/include/")

if("${CEU_CM_HAVE_WORKING_C_HELLOWORLD_RUN_SHARED}" EQUAL 0 AND CEU_CM_TRY_COMP_LINK_SHARED)
    set(LIBCEU_BUILD_SHARED
        TRUE
        CACHE INTERNAL "")
    message(STATUS "${PROJECT_NAME}: Will build shared ${PROJECT_NAME} (C)")
else()
    set(LIBCEU_BUILD_SHARED
        FALSE
        CACHE INTERNAL "")
    message(STATUS "${PROJECT_NAME}: Will NOT build shared ${PROJECT_NAME} (C)")
endif()

if("${CEU_CM_HAVE_WORKING_C_HELLOWORLD_RUN_STATIC}" EQUAL 0 AND CEU_CM_TRY_COMP_LINK_STATIC)
    set(LIBCEU_BUILD_STATIC
        TRUE
        CACHE INTERNAL "")
    message(STATUS "${PROJECT_NAME}: Will build static ${PROJECT_NAME} (C)")
else()
    set(LIBCEU_BUILD_STATIC
        FALSE
        CACHE INTERNAL "")
    message(STATUS "${PROJECT_NAME}: Will NOT build static ${PROJECT_NAME} (C)")
endif()
if(DEFINED CMAKE_CXX_COMPILER)
    if("${CEU_CM_HAVE_WORKING_CXX_HELLOWORLD_RUN_SHARED}" EQUAL 0 AND ${CEU_CM_TRY_COMP_LINK_SHARED})
        set(LIBCEU_BUILD_SHARED_CXX
            TRUE
            CACHE INTERNAL "")
        message(STATUS "${PROJECT_NAME}: Will build shared ${PROJECT_NAME} (CXX)")
    else()
        set(LIBCEU_BUILD_SHARED_CXX
            FALSE
            CACHE INTERNAL "Check for CEU_CM_HAVE_WORKING_CXX_HELLOWORLD_RUN_SHARED failed")
        message(STATUS "${PROJECT_NAME}: Will NOT build shared ${PROJECT_NAME} (CXX)")
    endif()

    if("${CEU_CM_HAVE_WORKING_CXX_HELLOWORLD_RUN_STATIC}" EQUAL 0 AND ${CEU_CM_TRY_COMP_LINK_STATIC})
        set(LIBCEU_BUILD_STATIC_CXX
            TRUE
            CACHE INTERNAL "")
        message(STATUS "${PROJECT_NAME}: Will build static ${PROJECT_NAME} (CXX)")
    else()
        set(LIBCEU_BUILD_STATIC_CXX
            FALSE
            CACHE INTERNAL "Check for CEU_CM_HAVE_WORKING_CXX_HELLOWORLD_RUN_STATIC failed")
        message(STATUS "${PROJECT_NAME}: Will NOT build static ${PROJECT_NAME} (CXX)")
    endif()
else()
    set(LIBCEU_BUILD_SHARED_CXX
        FALSE
        CACHE INTERNAL "CMake CXX compiler undefined")
    set(LIBCEU_BUILD_STATIC_CXX
        FALSE
        CACHE INTERNAL "CMake CXX compiler undefined")
endif()

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/lib/")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/bin/")
if(CEU_CM_SHOULD_ENABLE_TEST)
    message("libceu: Will perform test")
    add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/test/")
endif()
