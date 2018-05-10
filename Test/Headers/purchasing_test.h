//
// Created by Taras Martynyuk on 5/9/2018.
//
#ifndef OOPFINALEXAM_PURCHASING_TEST_H
#define OOPFINALEXAM_PURCHASING_TEST_H

void run_all_purch_tests();

void MakePurch_ThrowsLack_IfPurchAmount_GraterThanStoreHas();
void MakePurch_ThrowsLack_IfMoreItemsOfGoodsInPurch_ThanStoreHas();
void MakePurch_ChangesShelvesTotalAmount_ByPurchaseAmount();
void MakePurch_AddsPurchSum_ToCash();

void Discount_ReturnsNulls_IfNoOneQualifies();
void Discount_ReturnsOneNotNull_IfOneQualifies();
void Discount_Throws_IfExpired();

// TODO: test that the amount is changed correctly
// separately for each goods in purch

#endif //OOPFINALEXAM_PURCHASING_TEST_H
