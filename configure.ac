#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([libceu], [0.1], [Zhejian.23@intl.zju.edu.cn])
AC_CONFIG_SRCDIR()
AC_CONFIG_HEADERS([config.h])
# Initialize automake
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_FILES([Makefile])
# Initialize GNU Libtool
AM_PROG_AR
LT_INIT

# Definition of functions
AC_DEFUN([CEU_CHECK_FILE_COMPILATION],
    [AC_REQUIRE([AC_PROG_CC])

    dnl Read the content of the specified file
    AS_IF(
        [test -f "${CEU_CHECK_FILE_COMPILATION_FILEPATH}"],
        [
            AC_MSG_CHECKING([compiling ${CEU_CHECK_FILE_COMPILATION_FILEPATH}])
            file_content=`cat "${CEU_CHECK_FILE_COMPILATION_FILEPATH}"`
            AC_LANG_PUSH([C])
            AC_CACHE_VAL([compile_file_result],
            [AC_COMPILE_IFELSE([AC_LANG_SOURCE([], [${file_content}])],
                                [compile_file_result=yes],
                                [compile_file_result=no])])
            AC_LANG_POP([C])
            AS_IF([test "x$compile_file_result" = xyes],
                [AC_MSG_RESULT([yes])
                COMPILE_RESULT="Success"],
                [AC_MSG_RESULT([no])
                COMPILE_RESULT="Failure"])
            AC_SUBST([COMPILE_RESULT])
        ],
        [AC_MSG_ERROR([File ${CEU_CHECK_FILE_COMPILATION_FILEPATH} not found])]
    )
])


# Checks for programs.

# Ensure a C compiler is found
AC_PROG_CC


# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdint.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_VOLATILE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INT8_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset sqrt uname])

AC_OUTPUT
