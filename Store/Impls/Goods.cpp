//
// Created by Taras Martynyuk on 4/30/2018.
//
#include "Goods.h"
#include <iostream>
using namespace std;

Goods::Goods (size_t id,
    const string& name,
    int price_per_item,
    size_t freshness_period)
    : id_(id), name_(name),
      price_per_item_(price_per_item),
      freshness_period_(freshness_period)
      {}

Goods::Goods()
    : id_(0), name_(), price_per_item_(0) {}

//region props

void Goods::setId (size_t id)
    { id_ = id; }

size_t Goods::id() const
    { return id_; }

const string& Goods::name() const
    { return name_; }

void Goods::setName (const std::string& name)
    { name_ = name; }

int Goods::pricePerItem () const
    { return price_per_item_; }

void Goods::setPricePerItem (int price)
{
    if( price <= 0)
        { throw invalid_argument("price must be > 0"); }
    price_per_item_ = price;
}

date::days Goods::freshnessPeriod() const
    { return freshness_period_; }

void Goods::setFreshnessPeriod(date::days freshness_period)
    { freshness_period_ = freshness_period; }

//endregion

ostream& operator<<(ostream& os, const Goods& gds)
{
    os << "{ id : " << gds.id()
        << " name : " << gds.name()
        << " price : " << gds.pricePerItem()
        << " }";
    return os;
}
