#include <stdio.h>
#include "quadraticroots.h"

int main(void)
{

    struct QuadraticRootsResult result_int = findroots(1, -3, -7);
    struct QuadraticRootsResult result_float = findroots(-7.5, -0.5, 4.5);
    struct QuadraticRootsResult result_double = findroots(1.000067000000000000000001, -5.12824626293649241749834217491, 6.02376416127641286417461287612716);
    if (result_int.norealroots == '1')
    {
        printf("The equation has no real roots.\n");
    }
    else
    {
        printf("x1 = %lf, x2 = %lf\n", result_int.x1, result_int.x2);
    }
    if (result_float.norealroots == '1')
    {
        printf("The equation has no real roots.\n");
    }
    else
    {
        printf("x1 = %lf, x2 = %lf\n", result_float.x1, result_float.x2);
    }
    if (result_double.norealroots == '1')
    {
        printf("The equation has no real roots.\n");
    }
    else
    {
        printf("x1 = %lf, x2 = %lf\n", result_double.x1, result_double.x2);
    }

    return 0;
}