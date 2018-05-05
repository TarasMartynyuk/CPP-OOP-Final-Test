//
// Created by Taras Martynyuk on 5/1/2018.
//
#ifndef OOPFINALEXAM_SUPPLY_H
#define OOPFINALEXAM_SUPPLY_H
#include <cstddef>
#include "tz.h"
#include "GoodsSupply.h"

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
        const date::local_days& date_expires);
    Supply() = default;

    const date::local_days& expirationDate() const;
    void setExpirationDate(const date::local_days&);

    const amount_t& amount() const;

    void& setAmount(const amount_t amount);

private:
    amount_t amount_;
    date::local_days expiration_date_;
};

struct Supply::ExpirationComparator
{
    bool operator()(const Supply& left, const Supply& right)
    {
        return left.expirationDate() > right.expirationDate();
    }
};

#endif //OOPFINALEXAM_SUPPLY_H
