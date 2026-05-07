#include "quadratic.h"
#include <assert.h>
#include <math.h>

void test_linear_no_solutions() {
  double roots[2];
  int n = solve_quadratic(0.0, 0.0, 1.0, roots);
  assert(n == 0);
}

void test_two_distinct_roots() {
  double roots[2];
  int n = solve_quadratic(1.0, 0.0, -1.0, roots);
  assert(n == 2);
  assert(fabs(roots[0] + 1.0) < 1e-10);
  assert(fabs(roots[1] - 1.0) < 1e-10);
}

void test_one_root_zero() {
  double roots[2];
  int n = solve_quadratic(1.0, 0.0, 0.0, roots);
  assert(n == 1);
  assert(fabs(roots[0]) < 1e-10);
}

void test_no_real_roots() {
  double roots[2];
  int n = solve_quadratic(1.0, 0.0, 1.0, roots);
  assert(n == 0);
}

void test_small_roots() {
  double roots[2];
  int n = solve_quadratic(1.0, 0.0, -1e-7, roots);
  assert(n == 2);
  assert(fabs(roots[0] + 3e-4) < 1e-4);
  assert(fabs(roots[1] - 3e-4) < 1e-4);
}

void test_large_coefficients() {
  double roots[2];
  int n = solve_quadratic(1.0, -1e10, -1.0, roots);
  assert(n == 2);
  assert(fabs(roots[0] + 1e-10) < 1e-11);
  assert(fabs(roots[1] - 1e10) < 1e-11);
}

void test_discriminant_near_zero() {
  double roots[2];
  int n = solve_quadratic(1.0, 0.0, -1e-8, roots);
  assert(n == 1);
  assert(fabs(roots[0]) < 1e-7);
}

int main() {
  test_linear_no_solutions();
  test_two_distinct_roots();
  test_one_root_zero();
  test_no_real_roots();
  test_small_roots();
  test_large_coefficients();
  test_discriminant_near_zero();
  return 0;
}
