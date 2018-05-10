//
// Created by Taras Martynyuk on 5/2/2018.
//
#ifndef OOPFINALEXAM_DISCOUNTER_H
#define OOPFINALEXAM_DISCOUNTER_H
#include <vector>
#include "Supply.h"
#include "Discount.h"

// adds discounts to goods taking into account their expiration date
class Discounter
{
public:
    using DiscountedSupply = std::pair<Supply, Discount*>;
    
    // adds discount foreach supply depending on expiration date
    static  std::vector<DiscountedSupply> applyDiscountsIfNeeded(
        std::vector<Supply>&);

private:
    // discount : min time left to expire to be granted this discount
    // vec will be sorted by the Timedeltas
    // and we will check the supply against each of the discounts, stopping when some will have
    // timeDelta greater that time till expiration
//    static std::vector<std::pair<Discount, TimeDelta>> discounts;
};


#endif //OOPFINALEXAM_DISCOUNTER_H
