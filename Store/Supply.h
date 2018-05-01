//
// Created by Taras Martynyuk on 5/1/2018.
//
#ifndef OOPFINALEXAM_SUPPLY_H
#define OOPFINALEXAM_SUPPLY_H
#include "Date.h"

// a supply of goods - a package that was "included" to a store
// during some delivery
class Supply
{
public:
    Supply(size_t amount, const Date& date_manufactured,
        const Date& date_expires);

    Supply();

    Date& dateManufactured();
    const Date& dateManufactured() const;
    Date& dateExpires();
    const Date& dateExpires() const;

    size_t& amount();
    const size_t& amount() const;


private:
    Date date_manufactured_;
    Date date_expires_;
    size_t amount_;
};

#endif //OOPFINALEXAM_SUPPLY_H
