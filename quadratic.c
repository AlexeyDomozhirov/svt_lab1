#include "quadratic.h"
#include <math.h>

int solve_quadratic(double a, double b, double c, double roots[2]) {
  if (a == 0.0) {
    return 0;
  }

  double d = b * b - 4.0 * a * c;
  if (d < 0.0) {
    return 0;
  }
  if (fabs(d) < 1e-7) {
    roots[0] = -b / (2.0 * a);
    return 1;
  }
  double sqrt_d = sqrt(d);
  roots[0] = (-b - sqrt_d) / (2.0 * a);
  roots[1] = (-b + sqrt_d) / (2.0 * a);

  if (roots[0] > roots[1]) {
    double temp = roots[0];
    roots[0] = roots[1];
    roots[1] = temp;
  }
  return 2;
}