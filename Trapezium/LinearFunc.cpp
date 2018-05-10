//
// Created by Taras Martynyuk on 5/10/2018.
//
#include "LinearFunc.h"

namespace Trapezium
{

double LinearFunc::getK() const
{
    return k_;
}

void LinearFunc::setK(double k)
{
    k_ = k;
}

double LinearFunc::getB() const
{
    return b_;
}

void LinearFunc::setB(double b)
{
    b_ = b;
}

double LinearFunc::operator()(double x)
{
    return k_ * x + b_;
}

LinearFunc::LinearFunc(double k, double b)
    : k_(k), b_(b)
{}

}