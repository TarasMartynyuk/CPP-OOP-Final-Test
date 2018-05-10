//
// Created by Taras Martynyuk on 5/10/2018.
//
#ifndef OOPFINALEXAM_UTILS_H
#define OOPFINALEXAM_UTILS_H
#include <functional>

namespace Trapezium
{

double slowSimpson(
    double a,
    double b,
    const std::function<double(double)>& ,
    double eps = 0.0001);

}

#endif //OOPFINALEXAM_UTILS_H
