//
// Created by Taras Martynyuk on 5/1/2018.
//
#ifndef OOPFINALEXAM_SUPPLY_H
#define OOPFINALEXAM_SUPPLY_H
#include <Store/DateTime/DateTime.h>

struct Supply
{
    DateTime date_expires;
    size_t amount;
};

#endif //OOPFINALEXAM_SUPPLY_H
