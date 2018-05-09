//
// Created by Taras Martynyuk on 5/1/2018.
//
#ifndef OOPFINALEXAM_SUPPLY_H
#define OOPFINALEXAM_SUPPLY_H
#include <cstddef>
#include <numeric>
#include "tz.h"
#include "GoodsSupply.h"
#include "algorithm"

// a class holding data about one-time delivery
// can be used as a delivery of any good, depending on context
// is used internally, in the GoodsSupplies class
class Supply
{
public:
    using amount_t = GoodsSupply::amount_t;
    // sorts from supplies that will expire sooner
    // to those that will expire later
    struct ExpirationComparator;

    Supply(amount_t amount,
        const date::year_month_day& date_expires);
    Supply(const Supply&);
    Supply();

    const date::year_month_day& expirationDate() const;
    void setExpirationDate(const date::year_month_day& expiration_date);

    const amount_t& amount() const;
    void setAmount(amount_t amount);

    Supply& operator=(const Supply&) = default;
    ~Supply() = default;

private:
    amount_t amount_;
    date::year_month_day expiration_date_;
};


struct Supply::ExpirationComparator
{
    bool operator()(const Supply& left, const Supply& right)
    {
        return left.expirationDate() > right.expirationDate();
    }
};

template <typename SupplyIterable>
Supply::amount_t amountSum(SupplyIterable supIt)
{
    auto accumulator = [](int sum, const Supply& right)
        -> Supply::amount_t {
        return sum + right.amount();
    };

    return std::accumulate(
        supIt.begin(), supIt.end(),
        Supply::amount_t(), accumulator);
}


#endif //OOPFINALEXAM_SUPPLY_H
