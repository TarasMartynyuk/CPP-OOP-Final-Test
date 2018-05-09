//
// Created by Taras Martynyuk on 5/9/2018.
//
#ifndef OOPFINALEXAM_PURCHASING_TEST_H
#define OOPFINALEXAM_PURCHASING_TEST_H

void run_all_purch_tests();

void ThrowsLack_IfPurchAmount_GraterThanStoreHas();
void ThrowsLack_IfMoreItemsOfGoodsInPurch_ThanStoreHas();
void ChangesItemsAmount_ByPurchaseAmount();
void AddsPurchSum_ToCash();
// TODO: test that the amount is changed correctly
// separately for each good in purch

#endif //OOPFINALEXAM_PURCHASING_TEST_H
