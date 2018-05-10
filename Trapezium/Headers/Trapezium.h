 //
// Created by Taras Martynyuk on 5/2/2018.
//
#ifndef OOPFINALEXAM_TRAPEZIUM_H
#define OOPFINALEXAM_TRAPEZIUM_H
namespace Trapezium
{

class Trapezium
{
public:
    double area() const
        { return doArea(); }

    virtual ~Trapezium() = default;

private:
    virtual double doArea() const = 0;

};

} //Trapezium
#endif //OOPFINALEXAM_TRAPEZIUM_H
