if (NOT DEFINED GIT_ADAPTER_WAS_ALREADY_INCLUDED)
    set(GIT_ADAPTER_WAS_ALREADY_INCLUDED 1 CACHE BOOL "doc")
    set(GIT_COMMIT_HASH "Do not have Git VCS" CACHE BOOL "doc")
    set(GIT_COMMIT_DATE "Do not have Git VCS" CACHE BOOL "doc")
    set(GIT_COMMIT_MESSAGE "Do not have Git VCS" CACHE BOOL "doc")

    find_package(Git)
    if (GIT_FOUND)
        execute_process(
                COMMAND "${GIT_EXECUTABLE}" log -1 --pretty=format:%H
                OUTPUT_VARIABLE GIT_COMMIT_HASH
                OUTPUT_STRIP_TRAILING_WHITESPACE
                ERROR_QUIET
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        )
        execute_process(
                COMMAND "${GIT_EXECUTABLE}" log -1 --pretty=format:%aD
                OUTPUT_VARIABLE GIT_COMMIT_DATE
                OUTPUT_STRIP_TRAILING_WHITESPACE
                ERROR_QUIET
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        )
        execute_process(
                COMMAND "${GIT_EXECUTABLE}" log -1 --pretty=format:%s
                OUTPUT_VARIABLE GIT_COMMIT_MESSAGE
                OUTPUT_STRIP_TRAILING_WHITESPACE
                ERROR_QUIET
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        )
    else ()
        message(WARNING "Git executable not found.")
    endif ()
    message(STATUS "/------------------- Finding and assessing git -------------------\\")
    message(STATUS "|git executable found at ${GIT_EXECUTABLE}")
    message(STATUS "|On Git commit ${GIT_COMMIT_MESSAGE} (${GIT_COMMIT_HASH}) at ${GIT_COMMIT_DATE}")
    message(STATUS "\\------------------- Finding and assessing git -------------------/")
endif ()
