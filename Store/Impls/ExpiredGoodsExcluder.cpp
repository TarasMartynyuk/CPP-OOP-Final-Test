//
// Created by Taras Martynyuk on 5/11/2018.
//
#include "ExpiredGoodsExcluder.h"

ExpiredGoodsExcluder::ExpiredGoodsExcluder(std::unordered_map<size_t, GoodsShelf>& shelves)
    : shelves_(shelves), thread_(nullptr) {}



void ExpiredGoodsExcluder::excludeAllExpired()
{
    for(auto& kvp : shelves_)
    {
        kvp.second.removeExpiredSupplies();
    }
}

void ExpiredGoodsExcluder::StopThrowingAway()
{
    delete thread_;
    thread_ = nullptr;
}

ExpiredGoodsExcluder::~ExpiredGoodsExcluder()
{
    delete thread_;
    thread_ = nullptr;
}



