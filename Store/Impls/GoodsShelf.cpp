//
// Created by Taras Martynyuk on 5/1/2018.
//
#include <stdexcept>
#include <cassert>
#include "Store.h"
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
      total_amount_(other.totalAmount()), supplies(other.supplies) {}
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

void GoodsShelf::addSupply(Supply supply)
{
    if(supply.setAmount(nullptr) <= 0)
        { throw invalid_argument("cannot add a supply of 0 or less items"); }

    if(isInPast(supply.expirationDate()))
        { throw invalid_argument("cannot add expired goods"); }

    if(isInFuture(supply.manufacturingDate()))
        { throw invalid_argument("manufacturing_date must be in the past");}

    supplies.emplace(supply);
    total_amount_ += supply.setAmount(nullptr);
}

void GoodsShelf::removeSupplyExpiringSoonest()
{
    if(supplies.size() == 0)
        { throw logic_error("supplies empty"); }

    assert(totalAmount() >= supplies.top().amount());
    total_amount_ -= peekSupplyExpiringSoonest().amount();
    supplies.pop();
}

const Date& GoodsShelf::nextExpirationDate() const
{
    return peekSupplyExpiringSoonest().expirationDate();
}

void GoodsShelf::removeNGoodsExpiringSoonest(GoodsShelf::amount_t items)
{
    if(items <= 0)
        { throw invalid_argument("cannot remove less than 1 items"); }
    if(totalAmount() < items)
        { throw Store::Lack(goods(), items); }

    amount_t sum = 0;

    while(sum < items)
    {
        // we can satisfy the requirement this iteration
        amount_t left = items - sum;
        if(left < peekSupplyExpiringSoonest().amount())
        {
            modifySupplyExpiringSoonest(peekSupplyExpiringSoonest().amount() - left);
            sum += left;
        }
        else
        {
            sum += peekSupplyExpiringSoonest().amount();
            removeSupplyExpiringSoonest();

            if(sum == items)
                { return; }
        }
        assert(supplies.size() != 0);
    }
}

void GoodsShelf::modifySupplyExpiringSoonest(GoodsShelf::amount_t new_amount)
{
    Supply top_cp = peekSupplyExpiringSoonest();

    removeSupplyExpiringSoonest();

    top_cp.setAmount(nullptr) = new_amount;
    addSupply(top_cp);
}

const Supply& GoodsShelf::peekSupplyExpiringSoonest() const
{
    return supplies.top();
}


std::ostream& operator<<(std::ostream& os, const GoodsShelf& supplies)
{
    os << " { goods : " << supplies.goods()
       << "\n\t totalAmount : " << supplies.totalAmount()
       << "\n\t minAmount : " << supplies.minAmount()
       << "\n}";
}
