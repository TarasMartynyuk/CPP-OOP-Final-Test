//
// Created by Taras Martynyuk on 5/1/2018.
//
#ifndef OOPFINALEXAM_GOODSSUPPLIES_TEST_H
#define OOPFINALEXAM_GOODSSUPPLIES_TEST_H

void run_all_supplies_tests();

void AddSupply_ChangesTotalAmount();
void AddSupply_Throws_IfAddingExpired();
void AddSupply_Throws_IfAddingManufacturedInFuture();

void NextExpDate_IsLessThanNextDateAfterThisOne();
void NextExpDate_ReturnsTheLeastDate_OfTheAddedSupplies();

void RemoveSupplyExpNext_ChangesAmount();

void RemoveNGoods_ThrowsLack_IfNotEnoughItems();
void RemoveNGoods_ChangesTotalAmount();

// i believe in long names
void RemoveNGoods_DoesNotChangeNextExpDate_IfNextExpSupply_HasEnoughGoods();


#endif //OOPFINALEXAM_GOODSSUPPLIES_TEST_H
