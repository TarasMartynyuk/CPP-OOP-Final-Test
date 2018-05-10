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
    using DiscountedSupply = std::pair<Supply, float *>;
    
    // adds discount foreach supply depending on expiration date
    static std::vector<DiscountedSupply> applyDiscountsIfNeeded(
        std::vector<Supply>&);

private:
    using DiscountToPeriod = std::pair<date::days, float>;
    // discount : min time left to expire to be granted this discount
    // vec will be sorted by the days
    // and we will check the supply against each of the discounts, stopping when some will have
    // days greater that time till expiration
    static const std::vector<DiscountToPeriod> discounts;

    // sorts by discount percents
    struct DiscountComparator;

    static float* getMaxDiscount(const Supply&);
};

struct Discounter::DiscountComparator
{
    bool operator()(const DiscountToPeriod& left, const DiscountToPeriod& right)
    {
        return left.second < right.second;
    }
};




#endif //OOPFINALEXAM_DISCOUNTER_H
