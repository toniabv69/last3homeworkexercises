#ifndef QUADRATICROOTS_H
#define QUADRATICROOTS_H

struct QuadraticRootsResult
{
    double x1;
    double x2;
    char norealroots;
};

struct QuadraticRootsResult findroots(double a, double b, double c);

#endif