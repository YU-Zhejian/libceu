file(GLOB CEU_LIBRARY_SOURCES_C ${CMAKE_CURRENT_LIST_DIR}/*.c ${CMAKE_CURRENT_LIST_DIR}/*/*.c
     ${CMAKE_CURRENT_LIST_DIR}/ceu_cstd/*/*.c ${CMAKE_CURRENT_LIST_DIR}/ceu_check/c/*.c)

file(GLOB CEU_LIBRARY_SOURCES_CXX ${CMAKE_CURRENT_LIST_DIR}/*.c ${CMAKE_CURRENT_LIST_DIR}/*/*.c
     ${CMAKE_CURRENT_LIST_DIR}/ceu_cstd/*/*.c ${CMAKE_CURRENT_LIST_DIR}/ceu_check/cxx/*.cpp)

if("${CEU_CM_HAVE_WORKING_C_HELLOWORLD_RUN_SHARED}" EQUAL 0)
    set(LIBCEU_BUILD_SHARED
        TRUE
        CACHE BOOL "")
    message(STATUS "${PROJECT_NAME}: Will build shared ${PROJECT_NAME} (C)")
else()
    set(LIBCEU_BUILD_SHARED
        FALSE
        CACHE BOOL "")
    message(STATUS "${PROJECT_NAME}: Will NOT build shared ${PROJECT_NAME} (C)")
endif()

if("${CEU_CM_HAVE_WORKING_C_HELLOWORLD_RUN_STATIC}" EQUAL 0)
    set(LIBCEU_BUILD_STATIC
        TRUE
        CACHE BOOL "")
    message(STATUS "${PROJECT_NAME}: Will build static ${PROJECT_NAME} (C)")
else()
    set(LIBCEU_BUILD_STATIC
        FALSE
        CACHE BOOL "")
    message(STATUS "${PROJECT_NAME}: Will NOT build static ${PROJECT_NAME} (C)")
endif()

if(LIBCEU_BUILD_SHARED)
    add_library(${CEU_LIBRARY_SHARED} SHARED ${CEU_LIBRARY_SOURCES_C})
    install(TARGETS ${CEU_LIBRARY_SHARED} TYPE LIBRARY)
endif()

if(LIBCEU_BUILD_STATIC)
    add_library(${CEU_LIBRARY_STATIC} STATIC ${CEU_LIBRARY_SOURCES_C})
    install(TARGETS ${CEU_LIBRARY_STATIC} TYPE LIBRARY)
    ceu_cm_set_static_target(${CEU_LIBRARY_STATIC})
endif()

if(DEFINED CMAKE_CXX_COMPILER)
    if("${CEU_CM_HAVE_WORKING_CXX_HELLOWORLD_RUN_SHARED}" EQUAL 0)
        set(LIBCEU_BUILD_SHARED_CXX
            TRUE
            CACHE BOOL "")
        message(STATUS "${PROJECT_NAME}: Will build shared ${PROJECT_NAME} (CXX)")
    else()
        set(LIBCEU_BUILD_SHARED_CXX
            FALSE
            CACHE BOOL "Check for CEU_CM_HAVE_WORKING_CXX_HELLOWORLD_RUN_SHARED failed")
        message(STATUS "${PROJECT_NAME}: Will NOT build shared ${PROJECT_NAME} (CXX)")
    endif()

    if("${CEU_CM_HAVE_WORKING_CXX_HELLOWORLD_RUN_STATIC}" EQUAL 0)
        set(LIBCEU_BUILD_STATIC_CXX
            TRUE
            CACHE BOOL "")
        message(STATUS "${PROJECT_NAME}: Will build static ${PROJECT_NAME} (CXX)")
    else()
        set(LIBCEU_BUILD_STATIC_CXX
            FALSE
            CACHE BOOL "Check for CEU_CM_HAVE_WORKING_CXX_HELLOWORLD_RUN_STATIC failed")
        message(STATUS "${PROJECT_NAME}: Will NOT build static ${PROJECT_NAME} (CXX)")
    endif()

    if(LIBCEU_BUILD_SHARED_CXX)
        add_library(${CEU_LIBRARY_SHARED_CXX} SHARED ${CEU_LIBRARY_SOURCES_CXX})
        install(TARGETS ${CEU_LIBRARY_SHARED_CXX} TYPE LIBRARY)
    endif()

    if(LIBCEU_BUILD_STATIC_CXX)
        add_library(${CEU_LIBRARY_STATIC_CXX} STATIC ${CEU_LIBRARY_SOURCES_CXX})
        install(TARGETS ${CEU_LIBRARY_STATIC_CXX} TYPE LIBRARY)
        ceu_cm_set_static_target(${CEU_LIBRARY_STATIC_CXX})
    endif()
else()
    set(LIBCEU_BUILD_SHARED_CXX
        FALSE
        CACHE BOOL "CMake CXX compiler undefined")
    set(LIBCEU_BUILD_STATIC_CXX
        FALSE
        CACHE BOOL "CMake CXX compiler undefined")
endif()
