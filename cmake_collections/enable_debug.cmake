#[=======================================================================[
enable_debug.cmake -- C/C++/Fortran set up utilities

Function:
    - Defines several functions.
    - Check whether the CMake variable `ENABLE_DEBUG_CMAKE_WAS_ALREADY_INCLUDED` was set. If so, skip all processes described below. if not, set this variable.
    - Detect C/C++ preprocessor macros. If this is not a C/C++ project, this step would be omitted.
    - Detect whether test should be built. If CMake variable `SHOULD_ENABLE_TEST` was set, would skip this step. Otherwise, will setup test if the CMake variable `CMAKE_BUILD_TYPE` is not `Release`.
    - Detect whether we should build the application with native hardware support. If CMake variable `SHOULD_USE_NATIVE` was not set, would set it to `FALSE`. If this variable was set `TRUE`, would try and set `-march=native` `-mtune=native` `-mtune` flags.
    - Detect build type using CMake variable `CMAKE_BUILD_TYPE`.
        - If `Release`, will supress warnings (`-W0` `-w`), supress debug information (`-g0`) and enable optimization (`-Ofast` `-O3` `-O2`)
        - If `RelWithDebInfo` (Release with Debug Information), will supress warnings, enable debug information (`-g`) and enable optimization.
        - If `Debug` or if is others, will enable all warnings (`-Wall`) and extra warnings (`-Wextra`), enable pedantic mode (`-pedantic` `-Wpedantic`), enable full debug information (`-Og`) (`-g3`) and supress optimization (`-Og`). It will add `IS_DEBUG` to compiler flags (i.e., `-DIS_DEBUG`).
    - Print basic C/C++/Fortran information, including test and native information.
#]=======================================================================]

include(CheckCCompilerFlag)
include(CheckCXXCompilerFlag)
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/detect_c_preprocessor_macros.cmake")

#[=======================================================================[
set_static_cmake -- Mark a target as static.

Synopsis: set_static_cmake(name)

Params:
    - `name`: the name of the target that would be sattis

Notice:
    This function works by adding following lines to link options:
    - `-static`
    - `-static-libgcc`
    - `-static-libstdc++`
    - `-static-libgfortran`
    For those who uses pthreads & openMP on GLibC platforms (i.e., common GNU/Linux EXCLUDING Alpine Linux), this option would lead to segfaults.
#]=======================================================================]
macro(set_static_cmake name)
    set_target_properties("${name}" PROPERTIES LINK_SEARCH_START_STATIC 1)
    set_target_properties("${name}" PROPERTIES LINK_SEARCH_END_STATIC 1)
    target_link_options(
            "${name}" PRIVATE
            -static
            $<$<COMPILE_LANGUAGE:C,CXX>:-static-libgcc>
            $<$<COMPILE_LANGUAGE:CXX>:-static-libstdc++>
            $<$<COMPILE_LANGUAGE:Fortran>:-static-libgfortran>
    )
endmacro()

#[=======================================================================[
global_enhanced_check_compiler_flag -- Check whether one of the flags in a group of flags is available.

Synopsis: global_enhanced_check_compiler_flag(FLAG [[FLAG]...])

Params:
    - `FLAG`: A linker flag.

Notice:
    - This function detects used languages by detecting `CMAKE_C_COMPILER` and `CMAKE_CXX_COMPILER` CMake variable.
    - The options passed to this function is orderd. i.e., it would check whether the first flag is available. If so, the first flag would be added to compile options using CMake builtin function `add_compile_options`. If not, check the second flag until no flags left.

Sets:
    - CMake variable `C_COMPILER_HAVE_${FLAG}`.
#]=======================================================================]
function(global_enhanced_check_compiler_flag)
    foreach (FLAG ${ARGN})
        if (DEFINED CMAKE_C_COMPILER)
            check_c_compiler_flag(${FLAG} C_COMPILER_HAVE_${FLAG})
        else ()
            set(C_COMPILER_HAVE_${FLAG} TRUE)
        endif ()
        if (DEFINED CMAKE_CXX_COMPILER)
            check_cxx_compiler_flag(${FLAG} CXX_COMPILER_HAVE_${FLAG})
        else ()
            set(CXX_COMPILER_HAVE_${FLAG} TRUE)
        endif ()
        if (C_COMPILER_HAVE_${FLAG} AND CXX_COMPILER_HAVE_${FLAG})
            add_compile_options(${FLAG})
            return()
        endif ()
    endforeach ()
endfunction()


function(internal_check_linker_flag_impl_c flag var)
    try_compile(
            var
            "${CMAKE_BINARY_DIR}"
            "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/src/test_helloworld.c"
            LINK_OPTIONS ${flag}
    )
endfunction()

function(internal_check_linker_flag_impl_cxx flag var)
    try_compile(
            var
            "${CMAKE_BINARY_DIR}"
            "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/src/test_helloworld.cpp"
            LINK_OPTIONS ${flag}
    )
endfunction()

function(target_enhanced_check_linker_flag NAME)
    foreach (FLAGNAME ${ARGN})
        if (DEFINED CMAKE_C_COMPILER)
            internal_check_linker_flag_impl_c(${FLAGNAME} C_LINKER_HAVE_${FLAGNAME})
        else ()
            set(C_LINKER_HAVE_${FLAGNAME} TRUE)
        endif ()
        if (DEFINED CMAKE_CXX_COMPILER)
            internal_check_linker_flag_impl_cxx(${FLAGNAME} CXX_LINKER_HAVE_${FLAGNAME})
        else ()
            set(CXX_LINKER_HAVE_${FLAGNAME} TRUE)
        endif ()
        if (C_LINKER_HAVE_${NAME} AND CXX_LINKER_HAVE_${FLAGNAME})
            target_link_options(${NAME} PRIVATE ${FLAGNAME})
            return()
        endif ()
    endforeach ()
endfunction()


if (NOT DEFINED ENABLE_DEBUG_CMAKE_WAS_ALREADY_INCLUDED)
    set(ENABLE_DEBUG_CMAKE_WAS_ALREADY_INCLUDED 1)
    # Detect C/CXX Pre-Processor Macros
    detect_c_preprocessor_macros()

    # Define Test
    if (NOT DEFINED SHOULD_ENABLE_TEST)
        if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
            set(SHOULD_ENABLE_TEST FALSE)
        else ()
            set(SHOULD_ENABLE_TEST TRUE)
        endif ()
    endif ()
    if (NOT DEFINED SHOULD_USE_NATIVE)
        set(SHOULD_USE_NATIVE FALSE)
    endif ()
    if (SHOULD_USE_NATIVE)
        global_enhanced_check_compiler_flag(-march=native -mtune=native -mtune)
    endif ()
    if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release") # Release
        set(TETGS_DEBUG 0)
        set(TETGS_RELEASE 1)
        global_enhanced_check_compiler_flag(-W0 -w)
        global_enhanced_check_compiler_flag(-g0)
        global_enhanced_check_compiler_flag(-Ofast -O3 -O2)
    elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo") # Release with Debug Information
        set(TETGS_DEBUG 0)
        set(TETGS_RELEASE 1)
        global_enhanced_check_compiler_flag(-W0 -w)
        global_enhanced_check_compiler_flag(-Ofast -O3 -O2)
        global_enhanced_check_compiler_flag(-g)
    else () # Debug
        set(TETGS_DEBUG 1)
        set(TETGS_RELEASE 0)
        global_enhanced_check_compiler_flag(-Wall)
        global_enhanced_check_compiler_flag(-Wextra)
        global_enhanced_check_compiler_flag(-Wp64) # Visual Studio 64 bit compatibility
        global_enhanced_check_compiler_flag(-permissive) # Visual Studio
        global_enhanced_check_compiler_flag(-pedantic -Wpedantic)
        global_enhanced_check_compiler_flag(-Og)
        global_enhanced_check_compiler_flag(-g3)
        add_compile_definitions(IS_DEBUG)
    endif ()

    message(STATUS "/------------------- Basic Information -------------------\\")
    message(STATUS "|CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}, CMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}")
    message(STATUS "|CMAKE_SYSTEM=${CMAKE_SYSTEM}")
    message(STATUS "|CMAKE_MAKE_PROGRAM=${CMAKE_MAKE_PROGRAM}")
    message(STATUS "|CMAKE_AR=${CMAKE_AR}")
    message(STATUS "|CMAKE_RANLIB=${CMAKE_RANLIB}")
    message(STATUS "|CMAKE_EXECUTABLE_SUFFIX=${CMAKE_EXECUTABLE_SUFFIX}")
    message(STATUS "|CMAKE_SHARED_LIBRARY_PREFIX=${CMAKE_SHARED_LIBRARY_PREFIX}, CMAKE_SHARED_LIBRARY_SUFFIX=${CMAKE_SHARED_LIBRARY_SUFFIX}")
    message(STATUS "|CMAKE_STATIC_LIBRARY_PREFIX=${CMAKE_STATIC_LIBRARY_PREFIX}, CMAKE_STATIC_LIBRARY_SUFFIX=${CMAKE_STATIC_LIBRARY_SUFFIX}")

    if (DEFINED CMAKE_C_COMPILER)
        message(STATUS "|CMAKE_C_COMPILER=${CMAKE_C_COMPILER} (${CMAKE_C_COMPILER_ABI}) ver. ${CMAKE_C_COMPILER_VERSION} std. ${CMAKE_C_STANDARD}")
        message(STATUS "|CMAKE_C_LINK_EXECUTABLE=${CMAKE_C_LINK_EXECUTABLE}")
    endif ()
    if (DEFINED CMAKE_CXX_COMPILER)
        message(STATUS "|CMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER} (${CMAKE_CXX_COMPILER_ABI}) ver. ${CMAKE_CXX_COMPILER_VERSION} std. ${CMAKE_CXX_STANDARD}")
        message(STATUS "|CMAKE_CXX_LINK_EXECUTABLE=${CMAKE_CXX_LINK_EXECUTABLE}")
    endif ()

    if (DEFINED CMAKE_Fortran_COMPILER)
        message(STATUS "|CMAKE_Fortran_COMPILER=${CMAKE_Fortran_COMPILER} (${CMAKE_Fortran_COMPILER_ABI}) ver. ${CMAKE_Fortran_COMPILER_VERSION}")
        message(STATUS "|CMAKE_Fortran_LINK_EXECUTABLE=${CMAKE_Fortran_LINK_EXECUTABLE}")
    endif ()
    message(STATUS "|CMAKE_SYSTEM_LIBRARY_PATH=${CMAKE_SYSTEM_LIBRARY_PATH}")
    message(STATUS "|CMAKE_SYSTEM_INCLUDE_PATH=${CMAKE_SYSTEM_INCLUDE_PATH}")
    message(STATUS "|CMAKE_SYSTEM_PREFIX_PATH=${CMAKE_SYSTEM_PREFIX_PATH}")

    # This TETGS_DEBUG & TETGS_RELEASE will be written in tetgs.h
    if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
        message(STATUS "|CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -> Release mode was on")
    else ()
        message(STATUS "|CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -> Debug mode was on")
    endif ()
    message(STATUS "|SHOULD_ENABLE_TEST=${SHOULD_ENABLE_TEST}; SHOULD_USE_NATIVE=${SHOULD_USE_NATIVE}")

    message(STATUS "\\------------------- Basic Information -------------------/")

endif ()
