
set(
        CEU_AVAILABLE_CXX_STD
        98
        11
        14
        17
        20
)

if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.20")
    list(APPEND CEU_AVAILABLE_CXX_STD 23)
endif ()

list(GET CEU_AVAILABLE_CXX_STD -1 CEU_LATEST_CMAKE_AVAILABLE_CXX_STD)

function(ceu_test_enable_cxx_standard OUTPUT_VARIABLE STANDARD)
    set(OLD_CMAKE_CXX_STANDARD ${CMAKE_CXX_STANDARD})
    set(CMAKE_CXX_STANDARD ${STANDARD})
    try_run(
            CEU_TEST_CMAKE_CXX_STANDARD_${STANDARD}_RUN
            CEU_TEST_CMAKE_CXX_STANDARD_${STANDARD}_COMPILE
            "${CMAKE_BINARY_DIR}"
            "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/src/test_helloworld.cpp"
            RUN_OUTPUT_VARIABLE CEU_TEST_CMAKE_CXX_STANDARD_${STANDARD}_RUN_VAR
            COMPILE_OUTPUT_VARIABLE CEU_TEST_CMAKE_CXX_STANDARD_${STANDARD}_COMPILE_VAR
    )
    if (NOT DEFINED CEU_TEST_CMAKE_CXX_STANDARD_${STANDARD}_RUN)
        set(CEU_TEST_CMAKE_CXX_STANDARD_${STANDARD}_RUN 127)
    endif ()
    file(
            WRITE "${CMAKE_BINARY_DIR}/compile_logs/test_cxx_std_${STANDARD}_compile.log"
            ${CEU_TEST_CMAKE_CXX_STANDARD_${CMAKE_CXX_STANDARD}_COMPILE_VAR}
    )
    file(
            WRITE "${CMAKE_BINARY_DIR}/compile_logs/test_cxx_std_${STANDARD}_run.log"
            ${CEU_TEST_CMAKE_CXX_STANDARD_${STANDARD}_RUN_VAR}
    )
    set(CMAKE_CXX_STANDARD ${OLD_CMAKE_CXX_STANDARD})
    if (${CEU_TEST_CMAKE_CXX_STANDARD_${STANDARD}_RUN} EQUAL 0)
        set(${OUTPUT_VARIABLE} true PARENT_SCOPE)
    else ()
        set(${OUTPUT_VARIABLE} false PARENT_SCOPE)
    endif ()
endfunction()

function(ceu_get_highest_cxx_std LOWER_BOUND UPPER_BOUND)
    if (DEFINED CMAKE_CXX_STANDARD)
        message(STATUS "CMAKE_CXX_STANDARD already defined as ${CMAKE_CXX_STANDARD}!")
        return()
    endif ()
    if (NOT LOWER_BOUND IN_LIST CEU_AVAILABLE_CXX_STD)
        message(FATAL_ERROR "${LOWER_BOUND} not in ${CEU_AVAILABLE_CXX_STD}!")
    endif ()
    if (NOT DEFINED UPPER_BOUND OR NOT UPPER_BOUND IN_LIST CEU_AVAILABLE_CXX_STD)
        message(
                STATUS "UPPER_BOUND=${UPPER_BOUND} not in ${CEU_AVAILABLE_CXX_STD}, will set to ${CEU_LATEST_CMAKE_AVAILABLE_CXX_STD}"
        )
        set(UPPER_BOUND ${CEU_LATEST_CMAKE_AVAILABLE_CXX_STD})
    endif ()
    set(CURRENT_HIGHEST_CXX_STD -1)

    list(GET CEU_AVAILABLE_CXX_STD 1 ITERATING_LOWER_BOUND)
    while (NOT ${ITERATING_LOWER_BOUND} EQUAL ${LOWER_BOUND})
        list(POP_FRONT CEU_AVAILABLE_CXX_STD)
    endwhile ()

    foreach (STANDARD ${CEU_AVAILABLE_CXX_STD})
        message(STATUS "Detecting CXX_${STANDARD}...")
        ceu_test_enable_cxx_standard(IS_AVAILABLE_${STANDARD} ${STANDARD})
        if (IS_AVAILABLE_${STANDARD})
            message(STATUS "Detecting CXX_${STANDARD}...SUCCESS!")
            set(CURRENT_HIGHEST_CXX_STD ${STANDARD})
        else ()
            message(STATUS "Detecting CXX_${STANDARD}...FAILED!")
        endif ()
        if (${STANDARD} EQUAL ${UPPER_BOUND})
            break()
        endif ()
    endforeach ()
    message(STATUS "Set CMAKE_CXX_STANDARD to highest ${CURRENT_HIGHEST_CXX_STD}")
    set(CMAKE_CXX_STANDARD ${CURRENT_HIGHEST_CXX_STD} CACHE INTERNAL "highest CXX compiler standard supported")
endfunction()
