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
    bool any_expired =
    any_of(supplies.begin(), supplies.end(),
              [](const Supply& s){
                  return isInPast(s.expirationDate());
              });
    if (any_expired)
        { throw invalid_argument("at least one of supplies has expired"); }

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
    assert(isInFuture(supply.expirationDate()));
    assert(discountsSorted());

    days left_till_expire = daysLeft(supply.expirationDate());
    // first discount with period greater or eq to time left for supply to expire
    auto it = find_if(kDiscounts.cbegin(), kDiscounts.cend(),
                          [left_till_expire](const DiscountToPeriod& el){
                              return el.first >= left_till_expire;
                          });
    // no discount has period which is <= than supply's period
    if(it == kDiscounts.end())
        { return nullptr; }
//    // looks dangerous...
    return new float((it)->second);
}



