//
// Created by Taras Martynyuk on 5/1/2018.
//
#include <stdexcept>
#include <cassert>
#include "date_utils.h"
#include "StoreExceptions.h"
#include "GoodsShelf.h"
using namespace std;
using namespace date;

//region ctors

GoodsShelf::GoodsShelf(
    const Goods& goods, amount_t min_amount)
    : goods_(goods), min_amount_(min_amount),
      total_amount_(0) {}

GoodsShelf::GoodsShelf(const GoodsShelf& other)
    : goods_(other.goods()), min_amount_(other.minAmount()),
      total_amount_(other.totalAmount()), supplies_(other.supplies_) {}
//endregion

//region properties

const Goods& GoodsShelf::goods() const
    { return goods_; }

const GoodsShelf::amount_t GoodsShelf::totalAmount() const
    { return total_amount_; }

const GoodsShelf::amount_t GoodsShelf::minAmount() const
    { return min_amount_; }

void GoodsShelf::setMinAmount(
    GoodsShelf::amount_t min_amount)
{
    if(min_amount < 0)
        { throw invalid_argument("min amount cannot be less than 0"); }

    min_amount_ = min_amount;
}

//endregion
//region removing

const year_month_day& GoodsShelf::nextExpirationDate() const
{
    return peekSupplyExpiringSoonest().expirationDate();
}

std::vector<Supply> GoodsShelf::removeNGoodsExpiringSoonest(
    GoodsShelf::amount_t to_remove)
{
    if(to_remove <= 0)
    { throw invalid_argument("cannot remove less than 1 items"); }
    if(! hasEnough(to_remove))
    { throw Lack(goods(), to_remove); }

    vector<Supply> removed(to_remove / 40);

    amount_t sum = 0;

    while(sum < to_remove)
    {
        amount_t left = to_remove - sum;
        // we can satisfy the requirement this iteration
        const amount_t next_supply_amount =
            peekSupplyExpiringSoonest().amount();

        if(left < next_supply_amount)
        {   // then take part of supply and leave rest
            modifySupplyExpiringSoonest(next_supply_amount - left);
            removed.push_back(
                Supply(left, peekSupplyExpiringSoonest().expirationDate()
                      ));
            sum += left;
        }
        else    // take the full supply
        {
            sum += next_supply_amount;
            removed.push_back(peekSupplyExpiringSoonest());
            removeSupplyExpiringSoonest();
            assert(left == next_supply_amount || ! supplies_.empty());
        }
    }

    assert(amountSum(removed) == to_remove);
    return removed;
}

void GoodsShelf::removeSupplyExpiringSoonest()
{
    if(supplies_.empty())
    { throw logic_error("supplies empty"); }

    assert(totalAmount() >= supplies_.top().amount());
    total_amount_ -= peekSupplyExpiringSoonest().amount();
    supplies_.pop();
}

void GoodsShelf::removeExpiredSupplies()
{
    while(isInPast(nextExpirationDate()))
        { removeSupplyExpiringSoonest(); }
}//endregion



//region methods

void GoodsShelf::addSupply(Supply supply)
{
    // it is handled in ctor, so we are asserting, not checking
    if(supply.amount() <= 0)
        { throw invalid_argument("cannot add less than 1 items"); }

    if(isInPast(supply.expirationDate()))
        { throw invalid_argument("cannot add expired goods"); }

    supplies_.emplace(supply);
    total_amount_ += supply.amount();
}

void GoodsShelf::modifySupplyExpiringSoonest(GoodsShelf::amount_t new_amount)
{
    // makes a copy
    Supply top_cp = peekSupplyExpiringSoonest();

    removeSupplyExpiringSoonest();

    top_cp.setAmount(new_amount);
    addSupply(top_cp);
}

const Supply& GoodsShelf::peekSupplyExpiringSoonest() const
{
    return supplies_.top();
}

bool GoodsShelf::hasEnough(GoodsShelf::amount_t amount) const
{
//    bool b1 = totalAmount() >= amount;
//    bool b2 = totalAmount() - amount >= minAmount();
    return totalAmount() >= amount &&
        totalAmount() - amount >= minAmount();
}

//endregion

std::ostream& operator<<(std::ostream& os, const GoodsShelf& shelf)
{
    os << " { goods : " << shelf.goods()
       << "\n\t totalAmount : " << shelf.totalAmount()
       << "\n\t minAmount : " << shelf.minAmount()
       << "\n}";
}
