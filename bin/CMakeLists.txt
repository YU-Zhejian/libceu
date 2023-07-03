file(
        GLOB CEU_EXE_SOURCES_C ${CMAKE_CURRENT_LIST_DIR}/*.c
)

file(
        GLOB CEU_EXE_SOURCES_CXX ${CMAKE_CURRENT_LIST_DIR}/*.c ${CMAKE_CURRENT_LIST_DIR}/*.cpp
)


if (LIBCEU_BUILD_SHARED)
    add_executable(ceu_exe_shared ${CEU_EXE_SOURCES_C})
    target_link_libraries(ceu_exe_shared PUBLIC "${CEU_LIBRARY_SHARED}")
endif ()

if (LIBCEU_BUILD_STATIC)
    add_executable(ceu_exe_static ${CEU_EXE_SOURCES_C})
    set_static_cmake(ceu_exe_static)
    target_link_libraries(ceu_exe_static PUBLIC "${CEU_LIBRARY_STATIC}")
endif ()


if (LIBCEU_BUILD_SHARED_CXX)
    add_executable(ceu_exe_shared_cxx ${CEU_EXE_SOURCES_CXX})
    target_link_libraries(ceu_exe_shared_cxx PUBLIC "${CEU_LIBRARY_SHARED_CXX}")
endif ()

if (LIBCEU_BUILD_STATIC_CXX)
    add_executable(ceu_exe_static_cxx ${CEU_EXE_SOURCES_CXX})
    set_static_cmake(ceu_exe_static_cxx)
    target_link_libraries(ceu_exe_static_cxx PUBLIC "${CEU_LIBRARY_STATIC_CXX}")
endif ()
