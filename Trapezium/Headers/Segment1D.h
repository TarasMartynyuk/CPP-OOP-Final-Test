//
// Created by Taras Martynyuk on 5/10/2018.
//
#ifndef OOPFINALEXAM_SEGMENT1D_H
#define OOPFINALEXAM_SEGMENT1D_H

namespace Trapezium
{


class Segment1D
{
public:
    Segment1D(double a,
        double b);

    double getA() const;
    void setA(double a);

    double getB() const;
    void setB(double b);

private:
    double a_;
    double b_;
};

}
#endif //OOPFINALEXAM_SEGMENT1D_H
