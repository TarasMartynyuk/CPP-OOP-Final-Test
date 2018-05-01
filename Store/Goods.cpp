//
// Created by Taras Martynyuk on 4/30/2018.
//
#include "Goods.h"
using namespace std;

Goods::Goods(size_t id, std::string name, DateTime dateManufactured, DateTime dateExpires)
    : id_(id), name_(name), date_manufactured_(dateManufactured), date_expires_(dateExpires) {}

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

const DateTime& Goods::dateManufactured() const
{
    return date_manufactured_;
}

DateTime& Goods::dateManufactured()
{
    return date_manufactured_;
}

const DateTime& Goods::dateExpires() const
{
    return date_expires_;
}

DateTime& Goods::dateExpires()
{
    return date_expires_;
}