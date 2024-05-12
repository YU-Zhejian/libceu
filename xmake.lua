includes("@builtin/check")

-- project
set_project("libceu")

-- set xmake minimum version
set_xmakever("2.8.2")

-- set project version
set_version("0.0.1")

add_includedirs("include")
add_includedirs("include_priv")
add_includedirs("xmake-build/build")  -- FIXME: Non-portable code here

add_defines("CEU_CM_IS_DEBUG=1")
add_defines("CEU_CM_UNDER_XMAKE=1")
add_configfiles("include/ceu_basic/libceu_stddef_xmake.h.in", { filename = "ceu_basic/libceu_stddef_xmake.h" })

configvar_check_sizeof("CEU_CM_TYPE_C_SIZE", "char")
configvar_check_sizeof("CEU_CM_TYPE_UC_SIZE", "unsigned char")
configvar_check_sizeof("CEU_CM_TYPE_SC_SIZE", "signed char")
configvar_check_sizeof("CEU_CM_TYPE_SH_SIZE", "short")
configvar_check_sizeof("CEU_CM_TYPE_SHI_SIZE", "short int")
configvar_check_sizeof("CEU_CM_TYPE_SSH_SIZE", "signed short")
configvar_check_sizeof("CEU_CM_TYPE_SSHI_SIZE", "signed short int")
configvar_check_sizeof("CEU_CM_TYPE_USH_SIZE", "unsigned short")
configvar_check_sizeof("CEU_CM_TYPE_USHI_SIZE", "unsigned short int")
configvar_check_sizeof("CEU_CM_TYPE_I_SIZE", "int")
configvar_check_sizeof("CEU_CM_TYPE_S_SIZE", "signed")
configvar_check_sizeof("CEU_CM_TYPE_SI_SIZE", "signed int")
configvar_check_sizeof("CEU_CM_TYPE_U_SIZE", "unsigned")
configvar_check_sizeof("CEU_CM_TYPE_UI_SIZE", "unsigned int")
configvar_check_sizeof("CEU_CM_TYPE_L_SIZE", "long")
configvar_check_sizeof("CEU_CM_TYPE_LI_SIZE", "long int")
configvar_check_sizeof("CEU_CM_TYPE_SL_SIZE", "signed long")
configvar_check_sizeof("CEU_CM_TYPE_SLI_SIZE", "signed long int")
configvar_check_sizeof("CEU_CM_TYPE_UL_SIZE", "unsigned long")
configvar_check_sizeof("CEU_CM_TYPE_ULI_SIZE", "unsigned long int")
configvar_check_sizeof("CEU_CM_TYPE_LL_SIZE", "long long")
configvar_check_sizeof("CEU_CM_TYPE_LLI_SIZE", "long long int")
configvar_check_sizeof("CEU_CM_TYPE_SLL_SIZE", "signed long long")
configvar_check_sizeof("CEU_CM_TYPE_SLLI_SIZE", "signed long long int")
configvar_check_sizeof("CEU_CM_TYPE_ULL_SIZE", "unsigned long long")
configvar_check_sizeof("CEU_CM_TYPE_ULLI_SIZE", "unsigned long long int")
-- Following two methods are from https://en.cppreference.com/w/c/types/ptrdiff_t and https://en.cppreference.com/w/c/types/size_t
-- The correct implementation should use '%zu',
-- but it seems that Visual Studio 2010 does not support such.
configvar_check_csnippets(
	"CEU_CM_TYPE_SIZE_T_SIZE",
	'printf("%d", sizeof(sizeof(int))); return 0;',
	{ output = true, number = true, includes = {"stdio.h"} }
)
-- configvar_check_csnippets(
-- 	"CEU_CM_TYPE_PTRDIFF_T_SIZE",
-- 	'int numbers[100]; printf("%zu", sizeof(sizeof(&numbers[18]-&numbers[23]))); return 0;',
-- 	{ output = true, number = true, includes("stdio.h")  }
-- )

configvar_check_cincludes("CEU_HAVE_INCLUDE_STDBOOL_H", "stdbool.h")
configvar_check_cincludes("CEU_HAVE_INCLUDE_STDNORETURN_H", "stdnoreturn.h")
configvar_check_cincludes("CEU_HAVE_INCLUDE_CYGWIN_VERSION_H", "cygwin/version.h")
configvar_check_cincludes("CEU_HAVE_INCLUDE_SYS_UTSNAME_H", "sys/utsname.h")

set_languages("c++11")

target("ceu_shared")
set_kind("shared")
add_files("lib/*/*.c", "lib/*/*/*.c")
target_end()

-- FIXME: Not fully static, contains links to libc.
target("ceu_static")
set_kind("static")
add_files("lib/*/*.c", "lib/*/*/*.c")
target_end()

target("ceu_exe_shared")
set_kind("binary")
add_files("bin/*.c")
add_deps("ceu_shared")
target_end()

target("ceu_exe_static")
set_kind("binary")
add_files("bin/*.c")
add_deps("ceu_static")
target_end()

