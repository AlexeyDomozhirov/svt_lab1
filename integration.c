#include "integration.h"

double trapezoidal_rule(double (*f)(double), double a, double b, int n) {
  if (n <= 0)
    return 0.0;
  int reversed = 0;
  if (b < a) {
    double temp = a;
    a = b;
    b = temp;
    reversed = 1;
  }

  double h = (b - a) / n;
  double sum = (f(a) + f(b)) / 2.0;
  for (int i = 1; i < n; i++) {
    sum += f(a + i * h);
  }
  double result = sum * h;

  return reversed ? -result : result;
}
