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

Lack::Lack(size_t goods_id,
    GoodsSupply::amount_t amount)
    : logic_error(createMessage(goods_id, amount)) {}

char const* Lack::what() const noexcept
{
    return logic_error::what();
}

string Lack::createMessage(const Goods& gds,
    amount_t amount)
{
    stringstream ss;
    ss << "the store does not have " << amount << " items of goods: " << gds;
    return ss.str();
}

std::string Lack::createMessage(size_t goods_id,
    Lack::amount_t amount)
{
    return "the store does not have " + to_string(amount) +
           " items of goods with id: " + to_string(goods_id);
}

//endregion

//region GoodsNotRegistered

GoodsNotRegistered::GoodsNotRegistered(const Goods& gds)
    : logic_error(createMessage(gds))
{}

GoodsNotRegistered::GoodsNotRegistered(size_t goods_id)
    : logic_error(createMessage(goods_id)) {}

string GoodsNotRegistered::createMessage(const Goods& gds){
    stringstream ss;
    ss << "the goods - " << gds << " - are not registered";
    return ss.str();
}

string GoodsNotRegistered::createMessage(size_t goods_id)
{
    return "the goods with id " + to_string(goods_id) + "are not registered";
}

char const* GoodsNotRegistered::what() const noexcept
{
    return logic_error::what();
}

//endregion
