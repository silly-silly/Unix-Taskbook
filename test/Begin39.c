#include "ut1.h"
#include <math.h>

// Solve a quadratic equation A·x2 + B·x + C = 0 with given coefficients A, B, C
// (A and the discriminant of the equation are positive).
// Output the smaller equation root and then the larger one.
// Roots of the quadratic equation may be found by formula

// x1, 2 = (−B ± sqrt(D))/(2·A),

// where D = B^2 − 4·A·C is a discriminant.

int main(int argc, char *argv[])
{
    double a, b, c;
    GetD(&a);
    GetD(&b);
    GetD(&c);
    double sqrtd = sqrt(b * b - 4 * a * c);
    PutD((-b - sqrtd) / (2 * a));  //a=-1 6 -> -3
    PutD((-b + sqrtd) / (2 * a));  // 12  -> -6
}
