//
// Created by Taras Martynyuk on 5/1/2018.
//

#include "Store.h"
using  namespace std;


bool Store::goodsRegistered(const Goods& good)
{
    return goods_.count(good.id()) == 1;
}
