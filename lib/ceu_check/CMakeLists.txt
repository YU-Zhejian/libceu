file(
        GLOB CEU_SOURCES ${CMAKE_CURRENT_LIST_DIR}/*.c ${CMAKE_CURRENT_LIST_DIR}/*.cpp
)

if (LIBCEU_BUILD_SHARED)
    add_library(ceu_check_shared SHARED ${CEU_SOURCES})
    set_target_properties(
            ceu_check_shared
            PROPERTIES OUTPUT_NAME ceu_check
    )
endif ()

if (LIBCEU_BUILD_STATIC)
    add_library(ceu_check_static STATIC ${CEU_SOURCES})
    set_static_cmake(ceu_cpputils_static)
    set_target_properties(
            ceu_check_static
            PROPERTIES OUTPUT_NAME ceu_check
    )
endif ()
