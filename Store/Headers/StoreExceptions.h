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
    using amount_t = int;
    
    Lack(const Goods& gds,
        GoodsSupply::amount_t amount);
    Lack(size_t goods_id,
        GoodsSupply::amount_t amount);
    
    virtual char const * what() const noexcept;

private:
    std::string createMessage(const Goods&,
        amount_t amount);
    std::string createMessage(size_t goods_id,
        amount_t amount);
};

class GoodsNotRegistered : public std::logic_error
{
public:
    explicit GoodsNotRegistered(const Goods&);
    explicit GoodsNotRegistered(size_t goods_id);
    
    virtual char const * what() const noexcept;

private:
    std::string createMessage(const Goods&);
    std::string createMessage(size_t goods_id);
};


#endif //OOPFINALEXAM_STOREEXCEPTIONS_H
