//
// Created by Taras Martynyuk on 5/2/2018.
//
#ifndef OOPFINALEXAM_PURCHASEITEM_H
#define OOPFINALEXAM_PURCHASEITEM_H

#include "Goods.h"
#include "Discount.h"

class PurchaseItem
{
    PurchaseItem();

    Goods goods;
    int amount;
    // maybe there, ,maybe not
    Discount* discount;

    int costs();
};


#endif //OOPFINALEXAM_PURCHASEITEM_H
