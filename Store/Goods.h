//
// Created by Taras Martynyuk on 4/30/2018.
//
#ifndef OOPFINALEXAM_GOODS_H
#define OOPFINALEXAM_GOODS_H
#include <glob.h>
#include <string>
#include "DateTime.h"

class Goods
{
public:
    Goods(size_t id, std::string name,
        DateTime dateManufactured, DateTime dateExpires);

    size_t& id();
    const size_t& id() const;
    std::string& name();
    const std::string& name() const;
    DateTime& dateManufactured();
    const DateTime& dateManufactured() const;
    DateTime& dateExpires();
    const DateTime& dateExpires() const;

private:
    size_t id_;
    std::string name_;
    DateTime date_manufactured_;
    DateTime date_expires_;
};

#endif //OOPFINALEXAM_GOODS_H