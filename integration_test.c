#include "integration.h"
#include <assert.h>

double linear(double x) { return x; }
double square(double x) { return x * x; }
double constant(double x) { return 5.0; }

// Отдельные тесты
void test_linear() {
  double result = trapezoidal_rule(linear, 0.0, 1.0, 1000);
  assert(fabs(result - 0.5) < 1e-6);
}

void test_square() {
  double result = trapezoidal_rule(square, 0.0, 1.0, 1000);
  assert(fabs(result - 1.0 / 3.0) < 1e-6);
}

void test_constant() {
  double result = trapezoidal_rule(constant, 0.0, 10.0, 100);
  assert(fabs(result - 50.0) < 1e-6);
}

void test_regression() {
  double result = trapezoidal_rule(linear, 1.0, 0.0, 1000);
  assert(fabs(result + 0.5) < 1e-6);
}

void test_invalid_n() {
  double result = trapezoidal_rule(linear, 0.0, 1.0, 0);
  assert(result == 0.0);
}

int main() {
  test_linear();
  test_square();
  test_constant();
  test_regression();
  test_invalid_n();

  return 0;
}
