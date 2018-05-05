//
// Created by Taras Martynyuk on 5/6/2018.
//

#ifndef OOPFINALEXAM_STOREEXCEPTIONS_H
#define OOPFINALEXAM_STOREEXCEPTIONS_H
#include "Goods.h"
#include "GoodsSupply.h"


class Lack : public std::logic_error
{
public:
    Lack(const Goods& gds,
        GoodsSupply::amount_t amount);
    virtual char const * what() const noexcept;

private:
    std::string createMessage(const Goods&, size_t);
};

class GoodsNotRegistered : public std::logic_error
{
public:
    explicit GoodsNotRegistered(const Goods&);
    virtual char const * what() const noexcept;

private:
    std::string createMessage(const Goods&);
};


#endif //OOPFINALEXAM_STOREEXCEPTIONS_H
