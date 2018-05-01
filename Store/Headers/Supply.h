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
    using amount_t = size_t;
    // sorts from supplies that will expire sooner
    // to those that will expire later
    struct ExpirationComparator;

    Supply(size_t amount, const Date& date_manufactured,
        const Date& date_expires);
    Supply();

    Date& manufacturingDate();
    const Date& manufacturingDate() const;
    Date& expirationDate();
    const Date& expirationDate() const;

    amount_t& amount();
    const amount_t& amount() const;


private:
    Date date_manufactured_;
    Date date_expires_;
    size_t amount_;
};

struct Supply::ExpirationComparator
{
    bool operator()(const Supply& left, const Supply& right)
    {
        return left.expirationDate() > right.expirationDate();
    }
};

#endif //OOPFINALEXAM_SUPPLY_H
