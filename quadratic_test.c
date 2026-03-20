#include "quadratic.h"
#include <assert.h>
#include <math.h>
int main() {
  double roots[2];
  int n;

  n = solve_quadratic(0.0, 1.0, 1.0, roots);
  assert(n == 0);

  n = solve_quadratic(1.0, 0.0, -1.0, roots);
  assert(n == 2);
  assert(fabs(roots[0] + 1.0) < 1e-10);
  assert(fabs(roots[1] - 1.0) < 1e-10);

  n = solve_quadratic(1.0, 0.0, 0.0, roots);
  assert(n == 1);
  assert(fabs(roots[0]) < 1e-10);

  n = solve_quadratic(1.0, 0.0, 1.0, roots);
  assert(n == 0);

  n = solve_quadratic(1.0, 0.0, -1e-7, roots);
  assert(n == 2);
  assert(fabs(roots[0] + 3.16227766e-4) < 1e-4);
  assert(fabs(roots[1] - 3.16227766e-4) < 1e-4);

  n = solve_quadratic(1.0, -1e10, -1.0, roots);
  assert(n == 2);
  assert(fabs(roots[0] + 1e-10) < 1e-8);
  assert(fabs(roots[1] - 1e10) < 1e-10);

  n = solve_quadratic(1.0, 0.0, -1e-8, roots);
  assert(n == 1);
  assert(fabs(roots[0]) < 1e-7);

  return 0;
}