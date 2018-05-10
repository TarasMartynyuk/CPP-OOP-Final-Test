//
// Created by Taras Martynyuk on 5/10/2018.
//
#ifndef OOPFINALEXAM_LINEARTRAPEZIUM_H
#define OOPFINALEXAM_LINEARTRAPEZIUM_H
#include <cmath>
#include "LinearFunc.h"
#include "Trapezium.h"
#include "Segment1D.h"

namespace Trapezium
{

class LinearTrapezium : public Trapezium
{
public:
    LinearTrapezium(const Segment1D&, double k, double b);

public:
    const Segment1D& getSegment() const;
    void setSegment(const Segment1D& segment);

    const LinearFunc& getLinearFunc() const;
    void setLinearFunc(const LinearFunc& linearFunc);

private:
    Segment1D segment_;
    LinearFunc linearFunc;

    virtual double doArea() const override;
};

} //Trapezium
#endif //OOPFINALEXAM_LINEARTRAPEZIUM_H
