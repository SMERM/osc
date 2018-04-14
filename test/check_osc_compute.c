#include <stdlib.h>
#include <check.h>
#include "../src/osc.h"

START_TEST (check_osc_compute_zero_zero)
{
  Osc par = {0,1,0};
  Sample out;
  Sample *osc_compute(Sample*,Osc*);

  osc_compute(&out,&par);
  ck_assert_double_eq_tol(out.value,1.0, 1e-10);
  ck_assert_double_eq_tol(out.time,0.0, 1e-10);
}
END_TEST

START_TEST (check_osc_compute_zero_one)
{
  Osc par = {0,1,0};
  Sample out ={1.0,0.0};
  Sample *osc_compute(Sample*,Osc*);

  osc_compute(&out,&par);
  ck_assert_double_eq_tol(out.value,1.0, 1e-10);
  ck_assert_double_eq_tol(out.time,1.0, 1e-10);
}
END_TEST

START_TEST (check_osc_compute_zero_zero_phadd)
{
  Osc par = {0,1,1};
  Sample out;
  Sample *osc_compute(Sample*,Osc*);

  osc_compute(&out,&par);
  ck_assert_double_eq_tol(out.value,1.0, 1e-10);
  ck_assert_double_eq_tol(out.time,0.0, 1e-10);
}
END_TEST

START_TEST (check_osc_compute_zero_one_phadd)
{
  Osc par = {0,1,1};
  Sample out ={1.0,0.0};
  Sample *osc_compute(Sample*,Osc*);

  osc_compute(&out,&par);
  ck_assert_double_eq_tol(out.value,1.0, 1e-10);
  ck_assert_double_eq_tol(out.time,1.0, 1e-10);
}
END_TEST

Suite * osc_compute_suite(void)
{
    Suite *s;
    TCase *tc_zz, *tc_zo;
    TCase *tc_phadd;

    s = suite_create("osc_compute");

    /* zero zero test case */
    tc_zz = tcase_create("Zero Zero");
    tc_zo = tcase_create("Zero One");

    tcase_add_test(tc_zz, check_osc_compute_zero_zero);
    tcase_add_test(tc_zo, check_osc_compute_zero_one);
    suite_add_tcase(s, tc_zz);
    suite_add_tcase(s, tc_zo);


    /* phadd multiple test */
    tc_phadd = tcase_create("Phadd");

    tcase_add_test(tc_phadd, check_osc_compute_zero_zero_phadd);
    tcase_add_test(tc_phadd, check_osc_compute_zero_one_phadd);
    suite_add_tcase(s, tc_phadd);

    return s;
 }

 int main(void)
 {
     int number_failed;
     Suite *s;
     SRunner *sr;

     s = osc_compute_suite();
     sr = srunner_create(s);

     srunner_run_all(sr, CK_VERBOSE);
     number_failed = srunner_ntests_failed(sr);
     srunner_free(sr);
     return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
 }
