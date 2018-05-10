//
// Created by Taras Martynyuk on 5/10/2018.
//
#ifndef OOPFINALEXAM_SCHEDULER_H
#define OOPFINALEXAM_SCHEDULER_H
#include "GoodsShelf.h"
#include <functional>
#include <chrono>
#include <thread>
#include <unordered_map>

// think how to handle newly included goods
class  ExpiredGoodsExcluder
{
public:
    explicit ExpiredGoodsExcluder(std::unordered_map<size_t, GoodsShelf>& shelves);
    ~ExpiredGoodsExcluder();

    template<class Rep, class Period>
    void throwAwayExpiredSuppliesPeriodically(
        const std::chrono::duration<Rep, Period>& period)
    {
        if (thread_ != nullptr)
        { throw std::runtime_error("the excluder has already started"); }

        auto repeat_action = [this, &period]()
        {
            excludeAllExpired();
            std::this_thread::sleep_for(period);
        };

        thread_ = new std::thread(repeat_action);
        thread_->detach();
    }

    void StopThrowingAway();

private:
    std::unordered_map<size_t, GoodsShelf>& shelves_;
    std::thread* thread_;

    void excludeAllExpired();
};


#endif //OOPFINALEXAM_SCHEDULER_H
