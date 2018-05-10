//
// Created by Taras Martynyuk on 5/10/2018.
//
#include <stdexcept>
#include "Segment1D.h"
using namespace std;

Trapezium::Segment1D::Segment1D(double a, double b)
    : a_(0), b_(0)
{
    if (a >= b)
        {throw invalid_argument("a must be less than b"); }

    a_ = a;
    b_ = b;
}

double Trapezium::Segment1D::getA() const
{
    return a_;
}

void Trapezium::Segment1D::setA(double a)
{
    if (a >= b_)
        {throw invalid_argument("a must be less than b"); }
    a_ = a;
}

double Trapezium::Segment1D::getB() const
{
    return b_;
}

void Trapezium::Segment1D::setB(double b)
{
    if (b <= a_)
        {throw invalid_argument("a must be less than b"); }
    b_ = b;
}
