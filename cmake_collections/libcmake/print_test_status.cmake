#[=======================================================================[
ceu_print_test_status -- Print pretty-formatted test status.

Synopsis: ceu_print_test_status(NAME VARNAME)

Params:
    - `NAME`: Name of the test
    - `VARNAME`: See below.

Requires:
    - `CEU_CM_HAVE_WORKING_${VARNAME}_COMPILE_SHARED`
    - `CEU_CM_HAVE_WORKING_${VARNAME}_RUN_SHARED`
    - `CEU_CM_HAVE_WORKING_${VARNAME}_COMPILE_STATIC`
    - `CEU_CM_HAVE_WORKING_${VARNAME}_RUN_STATIC`

Sets:
    - `CEU_CM_PRINTED_${NAME}`: Indicator that stops redundant printing. Cache level.
#]=======================================================================]
macro(ceu_print_test_status NAME VARNAME)
    if(NOT DEFINED CEU_CM_PRINTED_${NAME})
        set(CEU_CM_PRINTED_${NAME} TRUE CACHE BOOL "")
        message(STATUS "/------------------- Info about ${NAME} -------------------\\")
        message(STATUS "|${NAME} shared: compile=${CEU_CM_HAVE_WORKING_${VARNAME}_COMPILE_SHARED}, run=${CEU_CM_HAVE_WORKING_${VARNAME}_RUN_SHARED}")
        message(STATUS "|${NAME} static: compile=${CEU_CM_HAVE_WORKING_${VARNAME}_COMPILE_STATIC}, run=${CEU_CM_HAVE_WORKING_${VARNAME}_RUN_STATIC}")
        message(STATUS "\\------------------- Info about ${NAME} -------------------/")
    endif()
endmacro()
