//
// Created by Taras Martynyuk on 5/10/2018.
//
#include <algorithm>
#include "Discounter.h"
#include "date_utils.h"
using namespace std;
using namespace date;

//region static init
using DiscToPer = Discounter::DiscountToPeriod;
using DiscSupply = Discounter::DiscountedSupply;

const std::vector<DiscToPer>
    Discounter::kDiscounts = std::vector<DiscToPer>(
{
    { days(1), 0.7 },
    { days(4), 0.3 },
    { days(7), 0.1 }
});

bool discountsSorted()
{
    // by dates, asc
    bool dates_sorted =  is_sorted(Discounter::kDiscounts.cbegin(), Discounter::kDiscounts.cend(),
                                   [](const DiscToPer& left, const DiscToPer& right){
                                       return left.first < right.first;
                                   });
    // by percents, desc
    bool percents_sorted =  is_sorted(Discounter::kDiscounts.cbegin(), Discounter::kDiscounts.cend(),
                                      [](const DiscToPer& left, const DiscToPer& right){
                                          return left.second > right.second;
                                      });
    return dates_sorted && percents_sorted;
}
//endregion

vector<DiscSupply> Discounter::applyDiscountsIfNeeded(std::vector<Supply>& supplies)
{
    assert(discountsSorted());

    vector<DiscSupply> result(supplies.size());
    transform(supplies.begin(), supplies.end(),
              result.begin(), [](const Supply& s) {
                return DiscSupply{ s, getMaxDiscount(s) };
              });
    return result;
}

float* Discounter::getMaxDiscount(const Supply& supply)
{
    assert(discountsSorted());

    days left_till_expire = daysLeft(supply.expirationDate());
    // first discount whose date has not yet come
    auto it = upper_bound(kDiscounts.begin(), kDiscounts.end(),
                          std::make_pair(left_till_expire, -1),
                          [](const DiscountToPeriod& left, const DiscountToPeriod& right){
                              return left.first < right.first;
                          });
//    // no discount has period which is <= than supply's period
    if(it == kDiscounts.begin())
        { return nullptr; }
//    // looks dangerous...
    return new float((--it)->second);
}



