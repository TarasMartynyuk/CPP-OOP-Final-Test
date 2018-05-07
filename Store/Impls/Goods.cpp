//
// Created by Taras Martynyuk on 4/30/2018.
//
#include "Goods.h"
#include <iostream>
using namespace std;

Goods::Goods(size_t id, std::string name, size_t price_per_item)
    : id_(id), name_(name), price_per_item_(price_per_item) {}

Goods::Goods()
    : id_(0), name_(), price_per_item_(0) {}

//region props

const size_t& Goods::id() const
{
    return  id_;
}

size_t& Goods::id()
{
    return id_;
}

const string& Goods::name() const
{
    return name_;
}

std::string& Goods::name()
{
    return name_;
}

size_t& Goods::pricePerItem()
{
    return price_per_item_;
}

const size_t& Goods::pricePerItem() const
{
    return price_per_item_;
}
//endregion

ostream& operator<<(ostream& os, const Goods& gds)
{
    os << "{ id : " << gds.id()
        << " name : " << gds.name()
        << " price : " << gds.pricePerItem()
        << " }";
    return os;
}
