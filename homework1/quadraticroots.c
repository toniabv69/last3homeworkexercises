#include <stdio.h>
#include <math.h>
#include "quadraticroots.h"

struct QuadraticRootsResult findroots(double a, double b, double c)
{
    struct QuadraticRootsResult result;
    result.norealroots = '0';
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
    {
        result.norealroots = '1';
    }
    else
    {
        result.x1 = ((-1 * b) - sqrtl(discriminant)) / (2 * a);
        result.x2 = ((-1 * b) + sqrtl(discriminant)) / (2 * a);
        result.norealroots = '0';
    }
    return result;
}