//
// Created by Taras Martynyuk on 5/1/2018.
//
#ifndef OOPFINALEXAM_GOODSINFO_H
#define OOPFINALEXAM_GOODSINFO_H
#include <cstddef>
#include <vector>
#include <queue>
#include "Date.h"
#include "Goods.h"
#include "Supply.h"

// stores all the supplies of the goods type(all the packages that where given to the store)
// along with shared information about that type(total values for all supplies)
class GoodsSupplies
{
public:
    using amount_t = Supply::amount_t;

    // can create with amount less than specified min
    GoodsSupplies(const Goods& gds, amount_t min_amount);
    GoodsSupplies(const GoodsSupplies&);

    // making this object mutable would require extra work
    // to achieve concistency, i ll leave it readonly for now
    const Goods& goods() const;
//    amount_t& totalAmount();
    const amount_t& totalAmount() const;
//    amount_t& minAmount();
    const amount_t& minAmount() const;

    const void addSupply(Supply supply);

    // they can be in multiple subsequent supplies
    // throws if removing would render the amount
    // less than minimal amount
    void removeNGoodsExpiringSoonest(amount_t items);

    // the date of the expiration of the next supply
    const Date& nextExpirationDate();

    // throws away the whole supply that would expire soonest
    // (or maybe have expired already)
    void removeSupplyExpiringSoonest();

private:
    const Goods goods_;
    amount_t total_amount_;
    amount_t min_amount_;

    //change to priority queue
    std::priority_queue<Supply, std::vector<Supply>,
        Supply::ExpirationComparator> supplies;
};



#endif //OOPFINALEXAM_GOODSINFO_H
