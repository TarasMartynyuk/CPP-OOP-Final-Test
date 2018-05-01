//
// Created by Taras Martynyuk on 4/17/2018.
//

#include <string>
#include <iostream>

void logPassed(std::string testName)
{
    std::cout << "PASSED test: " << testName << '\n';
}

void logAllPassed()
{
    std::cout << "passed all tests!\n";
}
