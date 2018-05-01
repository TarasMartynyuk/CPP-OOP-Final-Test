//
// Created by Taras Martynyuk on 5/1/2018.
//
#ifndef OOPFINALEXAM_GOODSINFO_H
#define OOPFINALEXAM_GOODSINFO_H

#include <cstddef>
#include <vector>
#include "Date.h"
#include "Goods.h"
#include "Supply.h"

// stores all the supplies of the goods type(all the packages that where given to the store)
// along with shared information about that type(total values for all supplies)
class GoodsSupplies
{
public:
    // can create with amount less than specified min
    GoodsSupplies(const Goods&, size_t min_amount);
//    GoodsSupplies(const Goods&, size_t min_amount, size_t init_amount);

    size_t& totalAmount();
    const size_t& totalAmount() const;
    size_t& minAmount();
    const size_t& minAmount() const;

    const void addSupply(const Date&, size_t amount);
    // the date of the expiration of the next supply
    const Date& nextExpirationDate();
    void removeSupplyThatExpiresNext();

private:
    const Goods goods_;
    size_t total_amount_;
    size_t min_amount_;

    //change to priority queue
    std::vector<Supply> supplies;
};


#endif //OOPFINALEXAM_GOODSINFO_H
