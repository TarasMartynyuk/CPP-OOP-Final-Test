//
// Created by Taras Martynyuk on 4/30/2018.
//
#ifndef OOPFINALEXAM_GOODS_H
#define OOPFINALEXAM_GOODS_H
#include <string>
#include <iostream>

// data to identify goods
class Goods
{
public:
    Goods(size_t id, std::string name, size_t price_per_item);
//    Goods() = default;
    Goods();

    size_t& id();
    const size_t& id() const;
    std::string& name();
    const std::string& name() const;
    size_t& pricePerItem();
    const size_t& pricePerItem() const;

private:
    size_t id_;
    size_t price_per_item_;
    std::string name_;
};

std::ostream& operator<<(std::ostream& os, const Goods & date);

#endif //OOPFINALEXAM_GOODS_H