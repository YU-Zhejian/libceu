file(
        GLOB CEU_SOURCES ${CMAKE_CURRENT_LIST_DIR}/*.c
)

if (LIBCEU_BUILD_SHARED)
    add_library(${CEU_LIBRARY_SHARED} SHARED ${CEU_SOURCES})
endif ()

if (LIBCEU_BUILD_STATIC)
    add_library(${CEU_LIBRARY_STATIC} STATIC ${CEU_SOURCES})
    set_static_cmake(${CEU_LIBRARY_STATIC})
endif ()
