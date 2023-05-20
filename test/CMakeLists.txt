enable_testing()

if (
    LIBCEU_BUILD_SHARED AND 
    DEFINED HAVE_WORKING_GTEST_RUN_SHARED 
    AND ${HAVE_WORKING_GTEST_RUN_SHARED} EQUAL 0
    )
    set(LIBCEU_TEST_BUILD_SHARED TRUE)
    message(STATUS "LIBCEU: Will build shared test")
else ()
    set(LIBCEU_TEST_BUILD_SHARED FALSE)
    message(STATUS "LIBCEU: Will NOT build shared test")
endif ()
if (
LIBCEU_BUILD_STATIC AND 
DEFINED HAVE_WORKING_GTEST_RUN_SHARED 
AND ${HAVE_WORKING_GTEST_RUN_STATIC} EQUAL 0)
    set(LIBCEU_TEST_BUILD_STATIC TRUE
    )
    message(STATUS "LIBCEU: Will build static test")
else ()
    set(LIBCEU_TEST_BUILD_STATIC FALSE)
    message(STATUS "LIBCEU: Will NOT build static test")
endif ()


set(LIBCEU_TEST_LIBRARY_SHARED ${CEU_CPPUTILS_LIBRARY_SHARED} ${CEU_CHECK_LIBRARY_SHARED} "${GTEST_MAIN_LIBRARY_SHARED}")
set(LIBCEU_TEST_LIBRARY_STATIC ${CEU_CPPUTILS_LIBRARY_STATIC} ${CEU_CHECK_LIBRARY_STATIC} "${GTEST_MAIN_LIBRARY_STATIC}")

macro(libceu_add_test source_name)
    if (LIBCEU_TEST_BUILD_SHARED)
        add_executable("test_libceu_${source_name}_shared" "${CMAKE_CURRENT_LIST_DIR}/test_${source_name}.cpp")
        target_link_libraries("test_libceu_${source_name}_shared" ${LIBCEU_TEST_LIBRARY_SHARED})
        add_test(NAME "test_libceu_${source_name}_shared" COMMAND "test_libceu_${source_name}_shared")
        message(STATUS "LIBCEU: Adding test test_libceu_${source_name}_shared")
    endif ()
    if (LIBCEU_TEST_BUILD_STATIC)
        add_executable("test_libceu_${source_name}_static" "${CMAKE_CURRENT_LIST_DIR}/test_${source_name}.cpp")
        target_link_libraries("test_libceu_${source_name}_static" ${LIBCEU_TEST_LIBRARY_STATIC})
        set_static_cmake("test_libceu_${source_name}_static")
        add_test(NAME "test_libceu_${source_name}_static" COMMAND "test_libceu_${source_name}_static")
        message(STATUS "LIBCEU: Adding test test_libceu_${source_name}_static")
    endif ()
endmacro()

macro(libceu_add_plain_test source_filename)
    if (LIBCEU_BUILD_SHARED)
        get_filename_component(TEST_SOURCE_NAME ${source_filename} NAME_WE)
        add_executable("test_libceu_${TEST_SOURCE_NAME}_shared" "${CMAKE_CURRENT_LIST_DIR}/test_${source_filename}")
        target_link_libraries("test_libceu_${TEST_SOURCE_NAME}_shared" ${CEU_CHECK_LIBRARY_SHARED})
        add_test(NAME "test_libceu_${TEST_SOURCE_NAME}_shared" COMMAND "test_libceu_${TEST_SOURCE_NAME}_shared")
        message(STATUS "LIBCEU: Adding test test_libceu_${TEST_SOURCE_NAME}_shared")
    endif ()
    if (LIBCEU_BUILD_STATIC)
        add_executable("test_libceu_${TEST_SOURCE_NAME}_static" "${CMAKE_CURRENT_LIST_DIR}/test_${source_filename}")
        target_link_libraries("test_libceu_${TEST_SOURCE_NAME}_static" ${CEU_CHECK_LIBRARY_STATIC})
        set_static_cmake("test_libceu_${TEST_SOURCE_NAME}_static")
        add_test(NAME "test_libceu_${TEST_SOURCE_NAME}_static" COMMAND "test_libceu_${TEST_SOURCE_NAME}_static")
        message(STATUS "LIBCEU: Adding test test_libceu_${TEST_SOURCE_NAME}_static")
    endif ()
endmacro()

libceu_add_test("ceu_filesystem")
libceu_add_plain_test("ceu_check_c.c")
libceu_add_plain_test("ceu_check_cxx.cpp")
