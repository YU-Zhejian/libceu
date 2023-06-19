find_package(PkgConfig)


function(ceu_get_abspath_from_linker_flag OUTPUT_VARIABLE LINKER_FLAG IS_STATIC)
    if (IS_STATIC)
        set(
                POSSIBLE_LIBRARY_FILENAMES
                "${LINKER_FLAG}${CMAKE_STATIC_LIBRARY_SUFFIX}"
                "${CMAKE_STATIC_LIBRARY_PREFIX}${LINKER_FLAG}${CMAKE_STATIC_LIBRARY_SUFFIX}"
                "lib${LINKER_FLAG}${CMAKE_STATIC_LIBRARY_SUFFIX}"
                "${LINKER_FLAG}.a"
                "${CMAKE_STATIC_LIBRARY_PREFIX}${LINKER_FLAG}.a"
                "lib${LINKER_FLAG}.a"
        )
    else ()
        set(
                POSSIBLE_LIBRARY_FILENAMES
                "${LINKER_FLAG}${CMAKE_SHARED_LIBRARY_SUFFIX}"
                "${CMAKE_SHARED_LIBRARY_PREFIX}${LINKER_FLAG}${CMAKE_SHARED_LIBRARY_SUFFIX}"
                "lib${LINKER_FLAG}${CMAKE_SHARED_LIBRARY_SUFFIX}"
                "${LINKER_FLAG}.so"
                "${CMAKE_SHARED_LIBRARY_PREFIX}${LINKER_FLAG}.so"
                "lib${LINKER_FLAG}.so"
                "${LINKER_FLAG}.dll"
                "${CMAKE_SHARED_LIBRARY_PREFIX}${LINKER_FLAG}.dll"
                "lib${LINKER_FLAG}.dll"
                "${LINKER_FLAG}.dll.a"
                "${CMAKE_SHARED_LIBRARY_PREFIX}${LINKER_FLAG}.dll.a"
                "lib${LINKER_FLAG}.dll.a"
        )
    endif ()
    unset(POSSIBLE_LIBRARY_FILENAME)
    foreach (POSSIBLE_LIBRARY_FILENAME ${POSSIBLE_LIBRARY_FILENAMES})
        unset(${LINKER_FLAG}_THIS_LIBRARY_ABSPATH)
        find_library(${LINKER_FLAG}_THIS_LIBRARY_ABSPATH ${POSSIBLE_LIBRARY_FILENAME} NO_CACHE)
        if (${LINKER_FLAG}_THIS_LIBRARY_ABSPATH)
            message(DEBUG "${LINKER_FLAG}: Finding ${POSSIBLE_LIBRARY_FILENAME} SUCCESS = ${${LINKER_FLAG}_THIS_LIBRARY_ABSPATH}!")
            set(${OUTPUT_VARIABLE} ${${LINKER_FLAG}_THIS_LIBRARY_ABSPATH} PARENT_SCOPE)
            return()
        else ()
            message(DEBUG "${LINKER_FLAG}: Finding ${POSSIBLE_LIBRARY_FILENAME} FAILED!")
        endif ()
    endforeach ()
    set(${OUTPUT_VARIABLE} ${LINKER_FLAG}-NOTFOUND PARENT_SCOPE)
endfunction()

function(ceu_get_linker_flags_from_pkg_config OUTPUT_VARIABLE LIB_NAME IS_STATIC)
    if (PKG_CONFIG_FOUND)
        pkg_check_modules(TMP_LIB_${LIB_NAME} ${LIB_NAME})
        if (TMP_LIB_${LIB_NAME}_FOUND)
            if (NOT ${IS_STATIC} AND TMP_LIB_${LIB_NAME}_LIBRARIES)
                set(${OUTPUT_VARIABLE} ${TMP_LIB_${LIB_NAME}_LIBRARIES} PARENT_SCOPE)
                return()
            elseif (${IS_STATIC} AND TMP_LIB_${LIB_NAME}_STATIC_LIBRARIES)
                set(${OUTPUT_VARIABLE} ${TMP_LIB_${LIB_NAME}_STATIC_LIBRARIES} PARENT_SCOPE)
                return()
            endif ()
        endif ()
    endif ()
    set(${OUTPUT_VARIABLE} ${OUTPUT_VARIABLE}-NOTFOUND PARENT_SCOPE)
endfunction()


function(ceu_get_library_abspath_from_pkg_config OUTPUT_VARIABLE LIB_NAME IS_STATIC)
    ceu_get_linker_flags_from_pkg_config(LINKER_FLAGS "${LIB_NAME}" "${IS_STATIC}")
    if (NOT LINKER_FLAGS)
        set(${OUTPUT_VARIABLE} ${OUTPUT_VARIABLE}-NOTFOUND PARENT_SCOPE)
        return()
    endif ()

    foreach (LINKER_FLAG ${LINKER_FLAGS})
        ceu_get_abspath_from_linker_flag(${LINKER_FLAG}_LIBRARY_ABSPATH ${LINKER_FLAG} ${IS_STATIC})
        if (${LINKER_FLAG}_LIBRARY_ABSPATH)
            list(APPEND THIS_LIBRARY_ABSPATHS ${${LINKER_FLAG}_LIBRARY_ABSPATH})
        else ()
            list(APPEND THIS_LIBRARY_ABSPATHS ${LINKER_FLAG}-NOTFOUND)
        endif ()
    endforeach ()
    set(${OUTPUT_VARIABLE} ${THIS_LIBRARY_ABSPATHS} PARENT_SCOPE)
endfunction()

function(ceu_enhanced_find_library)
    set(options STATIC NO_CACHE)
    set(oneValueArgs OUTPUT_VARIABLE LINKER_FLAG PKGCONFIG_NAME)
    set(multiValueArgs "")
    cmake_parse_arguments(CEU_ENHANCED_FIND_LIBRARY "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if (CEU_ENHANCED_FIND_LIBRARY_NO_CACHE AND DEFINED CEU_ENHANCED_FIND_LIBRARY_OUTPUT_VARIABLE)
        return()
    endif ()

    if (NOT DEFINED CEU_ENHANCED_FIND_LIBRARY_LINKER_FLAG AND NOT DEFINED CEU_ENHANCED_FIND_LIBRARY_PKGCONFIG_NAME)
        message(FATAL_ERROR "You need to define LINKER_FLAG or LIBRARY_PKGCONFIG_NAME")
    endif ()

    if (DEFINED CEU_ENHANCED_FIND_LIBRARY_PKGCONFIG_NAME AND CEU_ENHANCED_FIND_LIBRARY_PKGCONFIG_NAME AND PKG_CONFIG_FOUND)
        ceu_get_library_abspath_from_pkg_config(
                "${CEU_ENHANCED_FIND_LIBRARY_OUTPUT_VARIABLE}_TMP_LIBRARY_ABSPATHS"
                "${CEU_ENHANCED_FIND_LIBRARY_PKGCONFIG_NAME}"
                "${CEU_ENHANCED_FIND_LIBRARY_STATIC}"
        )

    endif ()
    if (DEFINED CEU_ENHANCED_FIND_LIBRARY_LINKER_FLAG AND CEU_ENHANCED_FIND_LIBRARY_LINKER_FLAG)
        ceu_get_abspath_from_linker_flag(
                "${CEU_ENHANCED_FIND_LIBRARY_OUTPUT_VARIABLE}_TMP_LIBRARY_ABSPATHS"
                "${CEU_ENHANCED_FIND_LIBRARY_LINKER_FLAG}"
                "${CEU_ENHANCED_FIND_LIBRARY_STATIC}"
        )
    endif ()
    if (${CEU_ENHANCED_FIND_LIBRARY_OUTPUT_VARIABLE}_TMP_LIBRARY_ABSPATHS)
        if (CEU_ENHANCED_FIND_LIBRARY_NO_CACHE)
            set(${CEU_ENHANCED_FIND_LIBRARY_OUTPUT_VARIABLE} ${${CEU_ENHANCED_FIND_LIBRARY_OUTPUT_VARIABLE}_TMP_LIBRARY_ABSPATHS} PARENT_SCOPE)
        else ()
            set(${CEU_ENHANCED_FIND_LIBRARY_OUTPUT_VARIABLE} ${${CEU_ENHANCED_FIND_LIBRARY_OUTPUT_VARIABLE}_TMP_LIBRARY_ABSPATHS} CACHE INTERNAL "Result of calling ceu_enhanced_find_library(${CEU_ENHANCED_FIND_LIBRARY_OUTPUT_VARIABLE})")
        endif ()
        return()
    endif ()
    set(${CEU_ENHANCED_FIND_LIBRARY_OUTPUT_VARIABLE} ${CEU_ENHANCED_FIND_LIBRARY_OUTPUT_VARIABLE}-NOTFOUND PARENT_SCOPE)
endfunction()
