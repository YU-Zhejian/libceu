/*!
 * @file ceu_assert.h
 * @brief Provides definition of #ceu_assert.
 */
#ifndef CEU_ASSERT_H
#define CEU_ASSERT_H

#ifdef CEU_UNDER_DOXYGEN

/*!
 * @def CEU_NDEBUG
 * @brief TODO
 */
#define CEU_NDEBUG /* defined externally */
/*!
 * @def ceu_assert
 * @brief TODO
 */
#define ceu_assert(test) /* behaviour defined by CEU_NDEBUG */
#endif

#include <ceu_basic/ceu_fast_macros.h>
#include <ceu_cstd/ceu_stdnoreturn.h>

CEU_BEGIN_C_DECLS

ceu_noreturn void _ceu_assert_impl CEU_PARAMS((const char* message));

CEU_END_C_DECLS

#endif // CEU_ASSERT_H

#ifdef ceu_assert
#undef ceu_assert
#endif

#ifdef CEU_NDEBUG
#define ceu_assert(...) ((void)0)
#else
#ifndef CEU_IS_TESTING_WHETHER_ASSERT_WORKS
#define ceu_assert(test) \
    (test) == 0 ? (void)0 : _ceu_assert_impl("Assertion failed on " __FILE__ ":" CEU_STR(__LINE__) " " CEU_VAL(test))
#else
#define ceu_assert(test) \
    (test) == 0 ? "" : "Assertion failed on TEST_FILE:" CEU_VAL(0) " " CEU_VAL(test)
#endif
#endif
