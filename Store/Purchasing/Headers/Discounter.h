//
// Created by Taras Martynyuk on 5/2/2018.
//
#ifndef OOPFINALEXAM_DISCOUNTER_H
#define OOPFINALEXAM_DISCOUNTER_H
#include <vector>
#include "Supply.h"

// adds discounts to goods taking into account their expiration date
class Discounter
{
public:
    //    days_left : discount
    using DiscountedSupply = std::pair<Supply, float *>;
    using DiscountToPeriod = std::pair<date::days, float>;
    // sorted by days left ascending,
    // and by discount percents descending
    static const std::vector<DiscountToPeriod> kDiscounts;
    
    // adds discount foreach supply depending on expiration date
    static std::vector<DiscountedSupply> applyDiscountsIfNeeded(
        std::vector<Supply>&);

private:
    // returns nullptr if no discount can be assigned
    static float* getMaxDiscount(const Supply&);
};





#endif //OOPFINALEXAM_DISCOUNTER_H
