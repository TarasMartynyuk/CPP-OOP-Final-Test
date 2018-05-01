//
// Created by Taras Martynyuk on 5/1/2018.
//

#ifndef OOPFINALEXAM_GOODSINFO_H
#define OOPFINALEXAM_GOODSINFO_H

#include <cstddef>
#include <vector>
#include <Store/DateTime/DateTime.h>
#include "Goods.h"
#include "Supply.h"

// stores all the supplies of the goods type(all the packages that where given to the store)
// along with shared information about that type(total values for all supplies)
class GoodsSupplies
{
public:
    GoodsSupplies(const Goods&, size_t min_amout, size_t init_amount);

    size_t& totalAmount();
    const size_t& totalAmount() const;
    size_t& minAmount();
    const size_t& minAmount() const;

    const void addSupply(const DateTime&, size_t amount);
    // the date of the expiration of the next supply
    const DateTime& nextExpirationDate();
    void removeSupplyThatExpiresNext();

    //change to priority queue
    std::vector<Supply> goodsGroups;
};


#endif //OOPFINALEXAM_GOODSINFO_H
