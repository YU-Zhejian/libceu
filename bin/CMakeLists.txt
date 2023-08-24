file(
        GLOB CEU_EXE_SOURCES_C ${CMAKE_CURRENT_LIST_DIR}/*.c
)

file(
        GLOB CEU_EXE_SOURCES_CXX ${CMAKE_CURRENT_LIST_DIR}/*.c ${CMAKE_CURRENT_LIST_DIR}/*.cpp
)


if (LIBCEU_BUILD_SHARED)
    add_executable(ceu_exe_shared ${CEU_EXE_SOURCES_C})
    install(TARGETS ceu_exe_shared TYPE RUNTIME)
    target_link_libraries(ceu_exe_shared PUBLIC "${CEU_LIBRARY_SHARED}")
endif ()

if (LIBCEU_BUILD_STATIC)
    add_executable(ceu_exe_static ${CEU_EXE_SOURCES_C})
    install(TARGETS ceu_exe_static TYPE RUNTIME)
    ceu_cm_set_static_target(ceu_exe_static)
    target_link_libraries(ceu_exe_static PUBLIC "${CEU_LIBRARY_STATIC}")
endif ()


if (LIBCEU_BUILD_SHARED_CXX)
    add_executable(ceu_exe_shared_cxx ${CEU_EXE_SOURCES_CXX})
    install(TARGETS ceu_exe_shared_cxx TYPE RUNTIME)
    target_link_libraries(ceu_exe_shared_cxx PUBLIC "${CEU_LIBRARY_SHARED_CXX}")
endif ()

if (LIBCEU_BUILD_STATIC_CXX)
    add_executable(ceu_exe_static_cxx ${CEU_EXE_SOURCES_CXX})
    install(TARGETS ceu_exe_static_cxx TYPE RUNTIME)
    ceu_cm_set_static_target(ceu_exe_static_cxx)
    target_link_libraries(ceu_exe_static_cxx PUBLIC "${CEU_LIBRARY_STATIC_CXX}")
endif ()
