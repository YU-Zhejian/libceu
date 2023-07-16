project("ceu_test" LANGUAGES C)

enable_testing()

if (LIBCEU_BUILD_SHARED)
    set(CEU_TEST_BUILD_SHARED TRUE)
    message(STATUS "${PROJECT_NAME}: Will build shared ${PROJECT_NAME}")
else ()
    set(CEU_TEST_BUILD_SHARED FALSE)
    message(STATUS "${PROJECT_NAME}: Will NOT build shared ${PROJECT_NAME}")
endif ()
if (LIBCEU_BUILD_STATIC)
    set(CEU_TEST_BUILD_STATIC TRUE)
    message(STATUS "${PROJECT_NAME}: Will build static ${PROJECT_NAME}")
else ()
    set(CEU_TEST_BUILD_STATIC FALSE)
    message(STATUS "${PROJECT_NAME}: Will NOT build static ${PROJECT_NAME}")
endif ()

set(CEU_TEST_LIBRARY_SHARED ${CEU_LIBRARY_SHARED})
set(CEU_TEST_LIBRARY_STATIC ${CEU_LIBRARY_STATIC})

macro(ceu_add_test test_name source_name)
    if (CEU_TEST_BUILD_SHARED)
        add_executable("test_ceu_${test_name}_shared" "${source_name}")
        target_link_libraries("test_ceu_${test_name}_shared" ${CEU_TEST_LIBRARY_SHARED})
        add_test(NAME "test_ceu_${test_name}_shared" COMMAND "test_ceu_${test_name}_shared")
        message(STATUS "CEU: Adding test test_ceu_${test_name}_shared")
    endif ()
    if (CEU_TEST_BUILD_STATIC)
        add_executable("test_ceu_${test_name}_static" "${source_name}")
        target_link_libraries("test_ceu_${test_name}_static" ${CEU_TEST_LIBRARY_STATIC})
        ceu_cm_set_static_target("test_ceu_${test_name}_static")
        add_test(NAME "test_ceu_${test_name}_static" COMMAND "test_ceu_${test_name}_static")
        message(STATUS "CEU: Adding test test_ceu_${test_name}_static")
    endif ()
endmacro()


ceu_add_test("ceu_cstd_stdio_printf_core" "${CMAKE_CURRENT_LIST_DIR}/ceu_cstd/ceu_stdio/test_printf_core.c")


