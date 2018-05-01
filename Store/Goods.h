//
// Created by Taras Martynyuk on 4/30/2018.
//
#ifndef OOPFINALEXAM_GOODS_H
#define OOPFINALEXAM_GOODS_H
#include <glob.h>
#include <string>
#include "Date.h"

// data to identify goods
class Goods
{
public:
    Goods(size_t id, std::string name);

    size_t& id();
    const size_t& id() const;
    std::string& name();
    const std::string& name() const;

private:
    size_t id_;
    std::string name_;
};

#endif //OOPFINALEXAM_GOODS_H