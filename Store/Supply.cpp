//
// Created by Taras Martynyuk on 5/1/2018.
//
#include "Supply.h"

Supply::Supply(size_t amount, const Date& date_manufactured, const Date& date_expires)
    : amount_(amount), date_manufactured_(date_manufactured), date_expires_(date_expires)
{}

Supply::Supply() : Supply(0, Date::kDefaultDate, Date::kDefaultDate) {}

const Date& Supply::manufacturingDate() const
    { return date_manufactured_; }

Date& Supply::manufacturingDate()
    { return date_manufactured_; }

const Date& Supply::expiringDate() const
    { return date_expires_; }

Date& Supply::expiringDate()
    { return date_expires_; }

size_t& Supply::amount()
    { return amount_; }

const size_t& Supply::amount() const
    { return  amount_; }





