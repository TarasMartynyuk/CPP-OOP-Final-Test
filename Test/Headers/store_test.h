//
// Created by Taras Martynyuk on 5/1/2018.
//
#ifndef OOPFINALEXAM_STORE_TEST_H
#define OOPFINALEXAM_STORE_TEST_H

void test_store();
// batch testing, should have made 3 separate functions but they take up so much space...
void IncludeExcludeCanExclude_Throws_WhenNotRegistered();

void Include_ChangesAmount();
void Exclude_ThrowsLack_IfNotEnoughItems();
void Exclude_ChangesAmount();
void Cannot_ExcludeToLessThanMin();

#endif //OOPFINALEXAM_STORE_TEST_H
