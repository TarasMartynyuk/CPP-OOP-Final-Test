//
// Created by Taras Martynyuk on 5/10/2018.
//
#include "LinearTrapezium.h"
#include "trapezium_utils.h"

namespace Trapezium
{

LinearTrapezium::LinearTrapezium(const Segment1D& sg,
     double k, double b)
    : segment_(sg), linearFunc(k, b) {}

//region props

const Segment1D& LinearTrapezium::getSegment() const
{
    return segment_;
}

void LinearTrapezium::setSegment(const Segment1D& segment)
{
    segment_ = segment;
}


const LinearFunc& LinearTrapezium::getLinearFunc() const
{
    return linearFunc;
}

void LinearTrapezium::setLinearFunc(const LinearFunc& linearFunc)
{
    LinearTrapezium::linearFunc = linearFunc;
}//endregion

double LinearTrapezium::doArea() const
{
    return slowSimpson(segment_.getA(), segment_.getB(), linearFunc);
}

}


