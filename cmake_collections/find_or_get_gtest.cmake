function(ceu_cm_find_or_get_gtest)
    set(options "")
    set(
        oneValueArgs 
        POLICY
        GIT_REPOSITORY 
        GIT_TAG
    )
    set(multiValueArgs "")
    cmake_parse_arguments(
        CEU_CM_FIND_OR_GET_GTEST
        "${options}"
        "${oneValueArgs}"
        "${multiValueArgs}"
        ${ARGN}
    )

    if(CEU_CM_FIND_OR_GET_GTEST_POLICY EQUAL "Download")
        include(FetchContent)
        if(NOT DEFINED CEU_CM_FIND_OR_GET_GTEST_GIT_REPOSITORY)
            set(CEU_CM_FIND_OR_GET_GTEST_GIT_REPOSITORY "https://github.com/google/googletest.git")
        endif()
        if(NOT DEFINED CEU_CM_FIND_OR_GET_GTEST_GIT_TAG)
            set(CEU_CM_FIND_OR_GET_GTEST_GIT_TAG "703bd9caab50b139428cea1aaff9974ebee5742e")
        endif()

        FetchContent_Declare(
            googletest
            GIT_REPOSITORY "${CEU_CM_FIND_OR_GET_GTEST_GIT_REPOSITORY}"
            GIT_TAG "${CEU_CM_FIND_OR_GET_GTEST_GIT_TAG}"
        )

        # For Windows: Prevent overriding the parent project's compiler/linker settings
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(googletest)
    elseif(CEU_CM_FIND_OR_GET_GTEST_POLICY EQUAL "Local")
        set(A A)
    elseif(CEU_CM_FIND_OR_GET_GTEST_POLICY EQUAL "System")
        set(A A)
    else()
        message(FATAL_ERROR "CEU_CM_FIND_OR_GET_GTEST_POLICY ${CEU_CM_FIND_OR_GET_GTEST_POLICY} INVALID!")
    endif()
endfunction()
