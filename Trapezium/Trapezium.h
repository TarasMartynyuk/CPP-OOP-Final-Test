//
// Created by Taras Martynyuk on 5/2/2018.
//

#ifndef OOPFINALEXAM_TRAPEZIUM_H
#define OOPFINALEXAM_TRAPEZIUM_H


class Trapezium
{
public:
    int area() { return doArea(); }
private:
    virtual int doArea() = 0;
};


#endif //OOPFINALEXAM_TRAPEZIUM_H
