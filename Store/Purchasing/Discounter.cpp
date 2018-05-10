//
// Created by Taras Martynyuk on 5/10/2018.
//
#include "Discounter.h"
#include <algorithm>
using namespace std;
using namespace date;

const std::vector<Discounter::DiscountToPeriod>
    Discounter::discounts = std::vector<Discounter::DiscountToPeriod>(
{
    { days(7), 0.1f },
    { days(4), 0.3f },
    { days(1), 0.7f },
});



float* Discounter::getMaxDiscount(const Supply&)
{
    // cannot do static assert, as the member is private
    assert(is_sorted(discounts.begin(),
                     discounts.end(),
                     DiscountComparator()
                     ));
    // by dates, in reverse order
    assert(is_sorted(discounts.begin(),
                     discounts.end(),
                     [](const DiscountToPeriod& left, const DiscountToPeriod& right){
                        return left.first > right.first;
                     }));
    return nullptr;
}