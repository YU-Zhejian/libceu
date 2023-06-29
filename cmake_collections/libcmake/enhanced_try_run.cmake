include("${CMAKE_CURRENT_LIST_DIR}/../enable_debug.cmake")
if (DEFINED CPPTETGS_DIST_CMAKE_TEST)
    enable_testing()
endif ()
function(enhanced_try_run)
    set(options STATIC)
    set(oneValueArgs SRC_PATH VARNAME)
    set(multiValueArgs LINK_LIBRARIES COMPILE_DEFS)
    cmake_parse_arguments(ENHANCED_TRY_RUN "${options}" "${oneValueArgs}"
            "${multiValueArgs}" ${ARGN})
    if (ENHANCED_TRY_RUN_STATIC)
        set(TARGET_POSTFIX "STATIC")
    else ()
        set(TARGET_POSTFIX "SHARED")
    endif ()

    if (DEFINED SKIP_ALL_TRY_RUN)
        set(HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX} TRUE CACHE INTERNAL "doc")
        set(HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX} 0 CACHE INTERNAL "doc")
        return()
    endif()

    if (DEFINED CPPTETGS_DIST_CMAKE_TEST)
        set(TARGET_NAME "${ENHANCED_TRY_RUN_VARNAME}_${TARGET_POSTFIX}")
        if (NOT TARGET "${TARGET_NAME}")
            add_executable("${TARGET_NAME}" "${CMAKE_CURRENT_LIST_DIR}/src/${ENHANCED_TRY_RUN_SRC_PATH}")
            message(STATUS "CPPTETGS_DIST_CMAKE: ADDING ${TARGET_NAME}")
            add_test("${TARGET_NAME}" "${TARGET_NAME}")
            if (DEFINED ENHANCED_TRY_RUN_COMPILE_DEFS)
                target_compile_definitions("${TARGET_NAME}" PRIVATE ${ENHANCED_TRY_RUN_COMPILE_DEFS})
            endif ()
            if (DEFINED ENHANCED_TRY_RUN_LINK_LIBRARIES)
                target_link_libraries("${TARGET_NAME}" PRIVATE ${ENHANCED_TRY_RUN_LINK_LIBRARIES})
            endif ()
            if (ENHANCED_TRY_RUN_STATIC)
                set_static_cmake("${TARGET_NAME}")
            endif ()
            set(HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX} TRUE CACHE INTERNAL "doc")
            set(HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX} 0 CACHE INTERNAL "doc")
            return()
        endif ()
    endif ()
    if (NOT DEFINED HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX})
        set(HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX} 127)
    endif ()
    if (NOT HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX} EQUAL 0)
        message(STATUS "CPPTETGS_DIST_CMAKE: Finding and assessing ${TARGET_POSTFIX} ${ENHANCED_TRY_RUN_VARNAME}")

        set(HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX} FALSE CACHE INTERNAL "doc")
        set(HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX} 127 CACHE INTERNAL "doc")
        if (NOT DEFINED ENHANCED_TRY_RUN_LINK_LIBRARIES)
            set(ENHANCED_TRY_RUN_LINK_LIBRARIES "")
        endif ()
        set(ENHANCED_TRY_RUN_COMPILE_DEFS_TRY_RUN "")
        if (DEFINED ENHANCED_TRY_RUN_COMPILE_DEFS)
            foreach (FLAG ENHANCED_TRY_RUN_COMPILE_DEFS)
                set(ENHANCED_TRY_RUN_COMPILE_DEFS_TRY_RUN ${ENHANCED_TRY_RUN_COMPILE_DEFS_TRY_RUN} -D${FLAG})
            endforeach ()
        endif ()
        if (ENHANCED_TRY_RUN_STATIC)
            set(LINK_OPTIONS PRIVATE -static -static-libgcc -static-libstdc++ -static-libgfortran)
        else ()
            set(LINK_OPTIONS "")
        endif ()
        try_run(HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX}
                HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX}
                "${CMAKE_BINARY_DIR}"
                "${CMAKE_CURRENT_LIST_DIR}/src/${ENHANCED_TRY_RUN_SRC_PATH}"
                LINK_OPTIONS ${LINK_OPTIONS}
                LINK_LIBRARIES ${ENHANCED_TRY_RUN_LINK_LIBRARIES}
                COMPILE_DEFINITIONS ${ENHANCED_TRY_RUN_COMPILE_DEFS_TRY_RUN}
                COMPILE_OUTPUT_VARIABLE HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX}_VAR
                RUN_OUTPUT_VARIABLE HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX}_VAR
                )
        if (NOT DEFINED HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX}_VAR)
            set(HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX}_VAR "")
        endif ()
        file(
                WRITE "${CMAKE_BINARY_DIR}/compile_logs/test_${ENHANCED_TRY_RUN_VARNAME}_${TARGET_POSTFIX}_compile.log"
                ${HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX}_VAR}
        )
        file(
                WRITE "${CMAKE_BINARY_DIR}/compile_logs/test_${ENHANCED_TRY_RUN_VARNAME}_${TARGET_POSTFIX}_run.log"
                ${HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX}_VAR}
        )
        if (NOT DEFINED HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX})
            set(HAVE_WORKING_${ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX} 127)
        endif ()
    else ()
        message(DEBUG "MISC_ENHANCED_TRY_COMPILE: Cached static ${ENHANCED_TRY_RUN_VARNAME}")
    endif ()
endfunction()

