#include "integration.h"
#include <assert.h>
#include <math.h>

double linear(double x) { return x; }

double square(double x) { return x * x; }

double constant(double x) { return 5.0; }

int main() {
  double result;

  result = trapezoidal_rule(linear, 0.0, 1.0, 1000);
  assert(fabs(result - 0.5) < 1e-6);

  result = trapezoidal_rule(square, 0.0, 1.0, 1000);
  assert(fabs(result - 1.0 / 3.0) < 1e-6);

  result = trapezoidal_rule(constant, 0.0, 10.0, 100);
  assert(fabs(result - 50.0) < 1e-6);

  return 0;
}