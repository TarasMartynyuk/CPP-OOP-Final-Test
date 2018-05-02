//
// Created by Taras Martynyuk on 5/2/2018.
//

#ifndef OOPFINALEXAM_CASHREGISTER_H
#define OOPFINALEXAM_CASHREGISTER_H

#include <Store/Headers/Store.h>

class CashRegister
{
public:
    const int& cash() const;
    int& cash();

    // excludes items from purchase from store,
    // and adds cash
    // items get discount if their expiration dates are soon
    // throws if not enough items
    void makePurchase();

private:
    int cash_;
    const Store& store_;
};


#endif //OOPFINALEXAM_CASHREGISTER_H
