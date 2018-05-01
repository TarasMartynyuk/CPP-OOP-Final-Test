//
// Created by Taras Martynyuk on 4/30/2018.
//
#include "Goods.h"
using namespace std;

Goods::Goods(size_t id, std::string name)
    : id_(id), name_(name) {}

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

