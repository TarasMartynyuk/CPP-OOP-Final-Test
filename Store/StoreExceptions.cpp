//
// Created by Taras Martynyuk on 5/1/2018.
//
#include <sstream>
#include "Store.h"
using namespace std;

//region Lack

Store::Lack::Lack(const Goods& gds, size_t amount)
    : logic_error(createMessage(gds, amount))
{}

string Store::Lack::createMessage(const Goods& gds, size_t amount)
{
    stringstream ss;
    ss << "the store does not have " << amount << " items of goods: " << gds;
    return ss.str();
}

char const* Store::Lack::what() const noexcept
{
    return logic_error::what();
}
//endregion

//region GoodsNotRegistered

Store::GoodsNotRegistered::GoodsNotRegistered(const Goods& gds)
    : logic_error(createMessage(gds))
{}

string Store::GoodsNotRegistered::createMessage(const Goods& gds){
    stringstream ss;
    ss << "the goods - " << gds << " - are not registered";
    return ss.str();
}

char const* Store::GoodsNotRegistered::what() const noexcept
{
    return logic_error::what();
}
//endregion
