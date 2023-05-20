set(CEU_SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/ceu_users.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/ceu_filesystem.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/ceu_subprocess.cpp"
        )
if (LIBCEU_BUILD_SHARED)
    add_library(ceu_cpputils_shared SHARED ${CEU_SOURCES})
    set_target_properties(
            ceu_cpputils_shared
            PROPERTIES OUTPUT_NAME ceu_cpputils
    )
endif ()

if (LIBCEU_BUILD_STATIC)
    add_library(ceu_cpputils_static STATIC ${CEU_SOURCES})
    set_static_cmake(ceu_cpputils_static)
    set_target_properties(
            ceu_cpputils_static
            PROPERTIES OUTPUT_NAME ceu_cpputils
    )
endif ()
