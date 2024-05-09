#include "quadratic_equation.h"

#include <math.h>

Roots solve_equation(double a, double b, double c) {
    Roots roots;
    double discriminant = b * b - 4 * a * c;

    if (a == 0) {
        if (b == 0) {
            roots.root1 = roots.root2 = NAN;
            roots.rootCount = 0;
        } else {
            roots.root1 = -c / b;
            roots.root2 = roots.root1;
            roots.rootCount = 1;
        }
    } else {
        if (discriminant < 0) {
            roots.root1 = roots.root2 = NAN;
            roots.rootCount = 0;
        } else if (discriminant == 0) {
            roots.root1 = -b / (2 * a);
            roots.root2 = roots.root1;
            roots.rootCount = 1;
        } else {
            roots.root1 = (-b - sqrt(discriminant)) / (2 * a);
            roots.root2 = (-b + sqrt(discriminant)) / (2 * a);
            roots.rootCount = 2;
        }
    }

    return roots;
}