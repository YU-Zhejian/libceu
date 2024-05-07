#define CEU_IS_TESTING_WHETHER_ASSERT_WORKS
#include <ceu_cstd/ceu_assert.h>
#include <minunit.h>


MU_TEST(basic_true_false) {

}

void test_nop(void){
#define CEU_NDEBUG // NOLINT
#include <ceu_cstd/ceu_assert.h> // NOLINT
    ceu_assert(0);
    ceu_assert(1);
}

void test_op(void){
#undef CEU_NDEBUG // NOLINT
#include <ceu_cstd/ceu_assert.h> // NOLINT
    ceu_assert(0);
    ceu_assert(1);
}

int main(void){
    test_nop();
    test_op(); // Should abort here!
}
