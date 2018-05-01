//
// Created by Taras Martynyuk on 5/1/2018.
//
#ifndef OOPFINALEXAM_STORE_TEST_H
#define OOPFINALEXAM_STORE_TEST_H

void test_store();
void Throws_IfIncludeExclude_WhenNotRegistered();
void DoesNotThrow_IfIncludeExclude_WhenRegistered();

void Include_ChangesAmout();
void Exclude_ChangesAmout();
void Cannot_ExcludeToLessThanMin();

#endif //OOPFINALEXAM_STORE_TEST_H
