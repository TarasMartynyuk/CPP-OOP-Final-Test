//
// Created by Taras Martynyuk on 4/30/2018.
//
#ifndef OOPFINALEXAM_GOODS_H
#define OOPFINALEXAM_GOODS_H
#include <string>
#include <iostream>
#include "date.h"

// data to identify goods
class Goods
{
public:
    Goods (size_t id,
        const std::string& name,
        int price_per_item,
        size_t freshness_period);
    Goods();

    //should pass by value
    size_t id() const;
    void setId (size_t);

    const std::string& name() const;
    void setName (const std::string&);

    int pricePerItem () const;
    void setPricePerItem (int);

    date::days freshnessPeriod() const;
    void setFreshnessPeriod(date::days);

private:
    size_t id_;
    int price_per_item_;
    std::string name_;
    date::days freshness_period_;
};

std::ostream& operator<<(std::ostream& os, const Goods & date);

#endif //OOPFINALEXAM_GOODS_H