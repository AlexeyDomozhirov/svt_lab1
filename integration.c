#include "integration.h"
#include <math.h>

double trapezoidal_rule(double (*f)(double), double a, double b, int n) {
  double h = (b - a) / n;
  double sum = (f(a) + f(b)) / 2.0;
  for (int i = 1; i < n; i++) {
    sum += f(a + i * h);
  }
  return sum * h;
}