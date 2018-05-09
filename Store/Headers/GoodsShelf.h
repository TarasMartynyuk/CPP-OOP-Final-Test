//
// Created by Taras Martynyuk on 5/1/2018.
//
#ifndef OOPFINALEXAM_GOODSINFO_H
#define OOPFINALEXAM_GOODSINFO_H
#include <cstddef>
#include <vector>
#include <queue>
#include "Goods.h"
#include "Supply.h"

// stores all the supplies of the goods type(all the packages that where given to the store)
// along with shared information about that type(total values for all supplies)
class GoodsShelf
{
public:
    using amount_t = GoodsSupply::amount_t;

    // can create with amount less than specified min
    GoodsShelf(const Goods& gds, amount_t min_amount);
    GoodsShelf(const GoodsShelf&);

    //region props

    // making this object mutable would require extra work
    // to achieve consistency, i ll leave it readonly for now
    const Goods& goods() const;
    const amount_t totalAmount() const;
    const amount_t minAmount() const;

    void setMinAmount(amount_t min_amount);
    //endregion

    void addSupply(Supply supply);

    // they can be in multiple subsequent supplies
    // throws if removing would render the amount
    // less than minimal amount
    void removeNGoodsExpiringSoonest(amount_t items);

    // returns the supplies, that together contain the requested amount of items,
    // removing them from shelf
    // if the last supply is not fully used, it remains on the shelf
    // but contains less items
    // throws if removing would render the amount
    // less than minimal amount
//    std::vector<Supply> removeNGoodsExpiringSoonest(amount_t items);

    // the date of the expiration of the next supply
    const date::year_month_day& nextExpirationDate() const;

    // throws away the whole supply that would expire soonest
    // (or maybe have expired already)
    void removeSupplyExpiringSoonest();

    // no impl
    void operator=(const GoodsShelf&) = delete;

private:

    const Goods goods_;
    amount_t total_amount_;
    amount_t min_amount_;

    // top element expires soonest
    std::priority_queue<Supply, std::vector<Supply>,
        Supply::ExpirationComparator> supplies;

    void modifySupplyExpiringSoonest(amount_t new_amount);
    const Supply& peekSupplyExpiringSoonest() const;
};

std::ostream& operator<<(std::ostream& os, const GoodsShelf & supplies);


#endif //OOPFINALEXAM_GOODSINFO_H
