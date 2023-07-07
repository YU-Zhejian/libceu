# TODO: Refactor this sh*t.
include("${CMAKE_CURRENT_LIST_DIR}/../enable_debug.cmake")

if (DEFINED CEU_CM_ADD_ETR_AS_TESTS)
    enable_testing()
endif ()

function(ceu_cm_enhanced_try_run)
    # Parse args
    set(options STATIC)
    set(oneValueArgs SRC_PATH VARNAME)
    set(multiValueArgs LINK_LIBRARIES COMPILE_DEFS DEPENDS)
    cmake_parse_arguments(
            CEU_CM_ENHANCED_TRY_RUN
            "${options}"
            "${oneValueArgs}"
            "${multiValueArgs}"
            ${ARGN}
    )

    if (CEU_CM_ENHANCED_TRY_RUN_STATIC)
        set(TARGET_POSTFIX "STATIC")
    else ()
        set(TARGET_POSTFIX "SHARED")
    endif ()

    # Unconditional skip
    if (DEFINED SKIP_ALL_TRY_RUN)
        set(
                CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX} TRUE
                CACHE INTERNAL
                "SKIP_ALL_TRY_RUN was set, skip all tests."
        )
        set(
                CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX} 0
                CACHE INTERNAL
                "SKIP_ALL_TRY_RUN was set, skip all tests."
        )
        return()
    endif ()

    # Add as test and evaluate later.
    if (DEFINED CEU_CM_ADD_ETR_AS_TESTS)
        set(TARGET_NAME CEU_CM_"${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_${TARGET_POSTFIX}")

        if (NOT TARGET "${TARGET_NAME}")
            add_executable("${TARGET_NAME}" "${CEU_CM_ENHANCED_TRY_RUN_SRC_PATH}")
            message(STATUS "CEU_CM: Adding test ${TARGET_NAME}")
            add_test("${TARGET_NAME}" "${TARGET_NAME}")

            if (DEFINED CEU_CM_ENHANCED_TRY_RUN_COMPILE_DEFS)
                target_compile_definitions("${TARGET_NAME}" PRIVATE ${CEU_CM_ENHANCED_TRY_RUN_COMPILE_DEFS})
            endif ()

            if (DEFINED CEU_CM_ENHANCED_TRY_RUN_LINK_LIBRARIES)
                target_link_libraries("${TARGET_NAME}" PRIVATE ${CEU_CM_ENHANCED_TRY_RUN_LINK_LIBRARIES})
            endif ()

            if (CEU_CM_ENHANCED_TRY_RUN_STATIC)
                ceu_cm_set_static_target("${TARGET_NAME}")
            endif ()

            set(CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX} TRUE CACHE INTERNAL "doc")
            set(CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX} 0 CACHE INTERNAL "doc")
            return()
        endif ()
    endif ()

    # Start processing
    if (NOT DEFINED CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX})
        message(STATUS "CEU_CM: Finding and assessing ${TARGET_POSTFIX} ${CEU_CM_ENHANCED_TRY_RUN_VARNAME}")

        set(
                CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX} FALSE
                CACHE INTERNAL
                "Default to fail."
        )
        set(
                CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX} 127
                CACHE INTERNAL
                "Default to fail."
        )
        if (DEFINED CEU_CM_ENHANCED_TRY_RUN_DEPENDS)
            foreach (DEPENDENT_VARNAME ${CEU_CM_ENHANCED_TRY_RUN_DEPENDS})
                if (DEFINED CEU_CM_HAVE_WORKING_${DEPENDENT_VARNAME}_RUN_${TARGET_POSTFIX})
                    if (NOT ${CEU_CM_HAVE_WORKING_${DEPENDENT_VARNAME}_RUN_${TARGET_POSTFIX}} EQUAL 0)
                        set(
                                CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX} FALSE
                                CACHE INTERNAL
                                "Dependency CEU_CM_HAVE_WORKING_${DEPENDENT_VARNAME}_RUN_${TARGET_POSTFIX} failed."
                        )
                        set(
                                CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX} 127
                                CACHE INTERNAL
                                "Dependency CEU_CM_HAVE_WORKING_${DEPENDENT_VARNAME}_RUN_${TARGET_POSTFIX} failed."
                        )
                        return()
                    endif ()
                else ()
                    set(
                            CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX} FALSE
                            CACHE INTERNAL
                            "Dependency CEU_CM_HAVE_WORKING_${DEPENDENT_VARNAME}_RUN_${TARGET_POSTFIX} undefined."
                    )
                    set(
                            CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX} 127
                            CACHE INTERNAL
                            "Dependency CEU_CM_HAVE_WORKING_${DEPENDENT_VARNAME}_RUN_${TARGET_POSTFIX} undefined."
                    )
                    return()
                endif ()
            endforeach ()
        endif ()

        if (DEFINED CEU_CM_ENHANCED_TRY_RUN_LINK_LIBRARIES)
            foreach (CEU_CM_ENHANCED_TRY_RUN_LINK_LIBRARY ${CEU_CM_ENHANCED_TRY_RUN_LINK_LIBRARIES})
                if (CEU_CM_ENHANCED_TRY_RUN_LINK_LIBRARY EQUAL "")
                    continue()
                elseif (NOT CEU_CM_ENHANCED_TRY_RUN_LINK_LIBRARY)
                    set(
                            CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX} FALSE
                            CACHE INTERNAL
                            "Dependency ${CEU_CM_ENHANCED_TRY_RUN_LINK_LIBRARY} not found."
                    )
                    set(
                            CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX} 127
                            CACHE INTERNAL
                            "Dependency ${CEU_CM_ENHANCED_TRY_RUN_LINK_LIBRARY} not found."
                    )
                    return()
                endif ()
            endforeach ()
        else ()
            set(CEU_CM_ENHANCED_TRY_RUN_LINK_LIBRARIES "")
        endif ()

        set(CEU_CM_ENHANCED_TRY_RUN_COMPILE_DEFS_TRY_RUN "")

        if (DEFINED CEU_CM_ENHANCED_TRY_RUN_COMPILE_DEFS)
            foreach (FLAG ${CEU_CM_ENHANCED_TRY_RUN_COMPILE_DEFS})
                set(CEU_CM_ENHANCED_TRY_RUN_COMPILE_DEFS_TRY_RUN ${CEU_CM_ENHANCED_TRY_RUN_COMPILE_DEFS_TRY_RUN} -D${FLAG})
            endforeach ()
        endif ()

        if (CEU_CM_ENHANCED_TRY_RUN_STATIC AND NOT BORLAND) # Borland compiler does not support such functions
            set(LINK_OPTIONS PRIVATE -static -static-libgcc -static-libstdc++ -static-libgfortran)
        else ()
            set(LINK_OPTIONS "")
        endif ()

        if (CMAKE_VERSION GREATER_EQUAL 3.14)
            try_run(
                    CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX}
                    CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX}
                    "${CMAKE_BINARY_DIR}/CEU_TRC"
                    "${CEU_CM_ENHANCED_TRY_RUN_SRC_PATH}"
                    LINK_OPTIONS ${LINK_OPTIONS}
                    LINK_LIBRARIES ${CEU_CM_ENHANCED_TRY_RUN_LINK_LIBRARIES}
                    COMPILE_DEFINITIONS ${CEU_CM_ENHANCED_TRY_RUN_COMPILE_DEFS_TRY_RUN}
                    COMPILE_OUTPUT_VARIABLE CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX}_VAR
                    RUN_OUTPUT_VARIABLE CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX}_VAR
            )
        else ()
            try_run(
                    CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX}
                    CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX}
                    "${CMAKE_BINARY_DIR}/CEU_TRC"
                    "${CEU_CM_ENHANCED_TRY_RUN_SRC_PATH}"
                    # LINK_OPTIONS ${LINK_OPTIONS}
                    LINK_LIBRARIES ${CEU_CM_ENHANCED_TRY_RUN_LINK_LIBRARIES}
                    COMPILE_DEFINITIONS ${CEU_CM_ENHANCED_TRY_RUN_COMPILE_DEFS_TRY_RUN}
                    COMPILE_OUTPUT_VARIABLE CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX}_VAR
                    RUN_OUTPUT_VARIABLE CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX}_VAR
            )
        endif ()

        if (NOT DEFINED CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX}_VAR)
            set(CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX}_VAR "")
        endif ()

        file(
                WRITE "${CMAKE_BINARY_DIR}/compile_logs/test_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_${TARGET_POSTFIX}_compile.log"
                ${CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX}_VAR}
        )
        file(
                WRITE "${CMAKE_BINARY_DIR}/compile_logs/test_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_${TARGET_POSTFIX}_run.log"
                ${CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX}_VAR}
        )
        unset(CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_COMPILE_${TARGET_POSTFIX}_VAR)
        unset(CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX}_VAR)

        if (NOT DEFINED CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX})
            set(
                    CEU_CM_HAVE_WORKING_${CEU_CM_ENHANCED_TRY_RUN_VARNAME}_RUN_${TARGET_POSTFIX} 127
                    CACHE INTERNAL
                    "Compilation failed."
            )
        endif ()
    else ()
        message(DEBUG "MISC_ENHANCED_TRY_COMPILE: Cached static ${CEU_CM_ENHANCED_TRY_RUN_VARNAME}")
    endif ()
endfunction()
