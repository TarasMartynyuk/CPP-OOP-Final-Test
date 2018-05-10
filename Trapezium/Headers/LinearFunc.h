//
// Created by Taras Martynyuk on 5/10/2018.
//

#ifndef OOPFINALEXAM_LINEARFUNC_H
#define OOPFINALEXAM_LINEARFUNC_H

namespace Trapezium
{

class LinearFunc
{
public:
    double operator() (double x);

public:
    LinearFunc(double k,
        double b);

    double getK() const;
    void setK(double k);

    double getB() const;
    void setB(double b);

private:
    double k_;
    double b_;
};

}


#endif //OOPFINALEXAM_LINEARFUNC_H
