#include <check.h>

#include "quadratic_equation.h"

START_TEST(test1) {
    Roots roots = solve_equation(1, -5, 4);
    ck_assert_int_eq(roots.rootCount, 2);
    ck_assert_double_eq(roots.root1, 1.0);
    ck_assert_double_eq(roots.root2, 4.0);
}
END_TEST

START_TEST(test2) {
    Roots roots = solve_equation(2, 5, -3);
    ck_assert_int_eq(roots.rootCount, 2);
    ck_assert_double_eq(roots.root1, -3.0);
    ck_assert_double_eq(roots.root2, 0.5);
}
END_TEST

START_TEST(test3) {
    Roots roots = solve_equation(4, 21, 5);
    ck_assert_int_eq(roots.rootCount, 2);
    ck_assert_double_eq(roots.root1, -5.0);
    ck_assert_double_eq(roots.root2, -0.25);
}
END_TEST

START_TEST(test4) {
    Roots roots = solve_equation(1, -1, -56);
    ck_assert_int_eq(roots.rootCount, 2);
    ck_assert_double_eq(roots.root1, -7.0);
    ck_assert_double_eq(roots.root2, 8);
}
END_TEST

START_TEST(test5) {
    Roots roots = solve_equation(3, 0, -27);
    ck_assert_int_eq(roots.rootCount, 2);
    ck_assert_double_eq(roots.root1, -3.0);
    ck_assert_double_eq(roots.root2, 3.0);
}
END_TEST

START_TEST(test6) {
    Roots roots = solve_equation(-1, 1, 0);
    ck_assert_int_eq(roots.rootCount, 2);
    ck_assert_double_eq(roots.root1, 1);
    ck_assert_double_eq(roots.root2, 0);
}
END_TEST

START_TEST(test7) {
    Roots roots = solve_equation(1, 6, 9);
    ck_assert_int_eq(roots.rootCount, 1);
    ck_assert_double_eq(roots.root1, -3);
}
END_TEST

START_TEST(test8) {
    Roots roots = solve_equation(2, 4, 7);
    ck_assert_int_eq(roots.rootCount, 0);
}
END_TEST

START_TEST(test9) {
    Roots roots = solve_equation(0, 3, -9);
    ck_assert_int_eq(roots.rootCount, 1);
    ck_assert_double_eq(roots.root1, 3);
}
END_TEST

START_TEST(test10) {
    Roots roots = solve_equation(0, 6, -24);
    ck_assert_int_eq(roots.rootCount, 1);
    ck_assert_double_eq(roots.root1, 4);
}
END_TEST

int main() {
    Suite *s = suite_create("Quadratic equation suite");
    TCase *tc = tcase_create("Quadratic equation test case");
    SRunner *runner = srunner_create(s);

    suite_add_tcase(s, tc);
    tcase_add_test(tc, test1);
    tcase_add_test(tc, test2);
    tcase_add_test(tc, test3);
    tcase_add_test(tc, test4);
    tcase_add_test(tc, test5);
    tcase_add_test(tc, test6);
    tcase_add_test(tc, test7);
    tcase_add_test(tc, test8);
    tcase_add_test(tc, test9);
    tcase_add_test(tc, test10);

    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);

    return 0;
}
