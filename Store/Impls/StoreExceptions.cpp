//
// Created by Taras Martynyuk on 5/1/2018.
//
#include <sstream>
#include "StoreExceptions.h"
using namespace std;

//region Lack

Lack::Lack(const Goods& gds,
    GoodsSupply::amount_t amount)
    : logic_error(createMessage(gds, amount))
{}

string Lack::createMessage(const Goods& gds, size_t amount)
{
    stringstream ss;
    ss << "the store does not have " << amount << " items of goods: " << gds;
    return ss.str();
}

char const* Lack::what() const noexcept
{
    return logic_error::what();
}
//endregion

//region GoodsNotRegistered

GoodsNotRegistered::GoodsNotRegistered(const Goods& gds)
    : logic_error(createMessage(gds))
{}

string GoodsNotRegistered::createMessage(const Goods& gds){
    stringstream ss;
    ss << "the goods - " << gds << " - are not registered";
    return ss.str();
}

char const* GoodsNotRegistered::what() const noexcept
{
    return logic_error::what();
}
//endregion
