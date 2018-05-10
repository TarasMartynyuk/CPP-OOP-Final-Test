//
// Created by Taras Martynyuk on 5/10/2018.
//
#ifndef OOPFINALEXAM_CURVEDTRAPEZIUM_H
#define OOPFINALEXAM_CURVEDTRAPEZIUM_H
#include "Trapezium.h"
#include "Segment1D.h"
#include <functional>

namespace Trapezium
{

class CurvedTrapezium : public Trapezium
{
public:
    CurvedTrapezium(const std::function<double(double)>& not_necessarily_linear_func,
            Segment1D segment_);

    const std::function<double(double)>& getNotNecessarilyLinearFunc() const;
    void setNotNecessarilyLinearFunc(const std::function<double(double)>& f);

    const Segment1D& getSegment() const;
    void setSegment(const Segment1D& segment);

private:
    Segment1D segment_;
    std::function<double(double)> not_necessarily_linear_func;

    virtual double doArea() const override;
};

}
#endif //OOPFINALEXAM_CURVEDTRAPEZIUM_H
