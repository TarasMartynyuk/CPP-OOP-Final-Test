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
class GoodsShelf
{
public:
    using amount_t = Supply::amount_t;

    // can create with amount less than specified min
    GoodsShelf(const Goods& gds, amount_t min_amount);
    GoodsShelf(const GoodsShelf&);

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
    const Date& nextExpirationDate() const;

    // throws away the whole supply that would expire soonest
    // (or maybe have expired already)
    void removeSupplyExpiringSoonest();

private:
    // no impl
    void operator=(const GoodsShelf&);
    const Goods goods_;
    amount_t total_amount_;
    amount_t min_amount_;

    std::priority_queue<Supply, std::vector<Supply>,
        Supply::ExpirationComparator> supplies;

    void modifySupplyExpiringSoonest(amount_t new_amount);
    const Supply& peekSupplyExpiringSoonest() const;
};

std::ostream& operator<<(std::ostream& os, const GoodsShelf & supplies);


#endif //OOPFINALEXAM_GOODSINFO_H
