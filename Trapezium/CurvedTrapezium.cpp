//
// Created by Taras Martynyuk on 5/10/2018.
//
#include "CurvedTrapezium.h"
#include "trapezium_utils.h"

namespace Trapezium
{

CurvedTrapezium::CurvedTrapezium(
    const std::function<double(double)>& f,
    Segment1D segment)
    : not_necessarily_linear_func(f),
    segment_(segment)
{}

const std::function<double(double)>& CurvedTrapezium::getNotNecessarilyLinearFunc() const
{
    return not_necessarily_linear_func;
}

void CurvedTrapezium::setNotNecessarilyLinearFunc(
    const std::function<double(double)>& f)
{
    CurvedTrapezium::not_necessarily_linear_func = f;
}

const Segment1D& CurvedTrapezium::getSegment() const
{
    return segment_;
}

void CurvedTrapezium::setSegment(const Segment1D& segment)
{
    segment_ = segment;
}

double CurvedTrapezium::doArea() const
{
    return slowSimpson(segment_.getA(), segment_.getB(), not_necessarily_linear_func);
}

}