macro(print_test_status name VARNAME LIBNAME)
    if (NOT DEFINED PRINTED_${name} AND NOT DEFINED CPPTETGS_DIST_CMAKE_TEST)
        set(PRINTED_${name} 1)
        if (DEFINED ${LIBNAME}_LIBRARY_SHARED AND DEFINED ${LIBNAME}_LIBRARY_SHARED)
            message(STATUS "/------------------- Info about ${name} -------------------\\")
            message(STATUS "|${name} shared: ${${LIBNAME}_LIBRARY_SHARED} compile=${HAVE_WORKING_${VARNAME}_COMPILE_SHARED}, run=${HAVE_WORKING_${VARNAME}_RUN_SHARED}")
            message(STATUS "|${name} static: ${${LIBNAME}_LIBRARY_STATIC} compile=${HAVE_WORKING_${VARNAME}_COMPILE_STATIC}, run=${HAVE_WORKING_${VARNAME}_RUN_STATIC}")
            message(STATUS "\\------------------- Info about ${name} -------------------/")
        elseif (DEFINED HAVE_WORKING_${VARNAME}_COMPILE_SHARED)
            message(STATUS "/------------------- Info about ${name} -------------------\\")
            message(STATUS "|${name} shared: compile=${HAVE_WORKING_${VARNAME}_COMPILE_SHARED}, run=${HAVE_WORKING_${VARNAME}_RUN_SHARED}")
            message(STATUS "|${name} static: compile=${HAVE_WORKING_${VARNAME}_COMPILE_STATIC}, run=${HAVE_WORKING_${VARNAME}_RUN_STATIC}")
            message(STATUS "\\------------------- Info about ${name} -------------------/")
        endif ()
    endif ()
endmacro()