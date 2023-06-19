include("${CMAKE_CURRENT_LIST_DIR}/libcmake/print_test_status.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/libcmake/enhanced_try_run.cmake")

if (NOT DEFINED Threads_FOUND)
    find_package(Threads)
endif ()

if (NOT Threads_FOUND)
    set(HAVE_WORKING_CXX_PTHREAD_RUN_SHARED FALSE CACHE INTERNAL "doc")
    set(HAVE_WORKING_CXX_PTHREAD_COMPILE_SHARED 127 CACHE INTERNAL "doc")
    set(HAVE_WORKING_CXX_PTHREAD_RUN_STATIC FALSE CACHE INTERNAL "doc")
    set(HAVE_WORKING_CXX_PTHREAD_COMPILE_STATIC 127 CACHE INTERNAL "doc")
else ()
    enhanced_try_run(VARNAME CXX_PTHREAD SRC_PATH "test_pthread.cpp" LINK_LIBRARIES Threads::Threads m)
    enhanced_try_run(STATIC VARNAME CXX_PTHREAD SRC_PATH "test_pthread.cpp" LINK_LIBRARIES Threads::Threads m)
endif ()

print_test_status("pthread (cxx)" CXX_PTHREAD "")
