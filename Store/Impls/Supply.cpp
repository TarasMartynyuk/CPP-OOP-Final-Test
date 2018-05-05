//
// Created by Taras Martynyuk on 5/1/2018.
//
#include "Supply.h"
using namespace date;

Supply::Supply(
    Supply::amount_t amount,
    const date::local_days& expiration_date)
    : expiration_date_(expiration_date),
    amount_(amount) {}

//region props

const date::year_month_day& Supply::expirationDate() const
    { return expiration_date_; }

void Supply::setExpirationDate(const year_month_day& expiration_date)
{
    //TODO: validate
    expiration_date_ = expiration_date;
}

const Supply::amount_t& Supply::amount() const
    { return  amount_; }

void& Supply::setAmount(const Supply::amount_t amount)
    { amount_ = amount; }
//endregion

struct Supply::ExpirationComparator
{
    bool operator()(const Supply& left, const Supply& right)
    {
        return left.expirationDate() > right.expirationDate();
    }
};
