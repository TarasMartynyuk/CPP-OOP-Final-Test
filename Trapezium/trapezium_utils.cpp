//
// Created by Taras Martynyuk on 5/10/2018.
//
#include <cmath>
#include "trapezium_utils.h"

namespace Trapezium
{

double slowSimpson(const double a,
    const double b,
    const std::function<double(double)>& f,
    const double eps)
{
    int n = 2;
    double h = (b - a) * 0.5;
    double ss = 0;
    double s = h * (f(a) + f(a + h) + f(b));
    do
    {
        ss = s;
        n *= 2;
        h /= 2;
        s = f(a) + 4 * f(a + h) + f(b);
        for (int i = 2; i < n; i = i + 2)
        {
            s = s + 2 * f(a + i * h) + 4 * f(a + (i + 1) * h);
        }
        s = s * h;
    }
    while (fabs(s - ss) > eps);

    return s / 3;
}
}