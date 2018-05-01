#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "Test/Headers/test.h"
using namespace std;

int main()
{
//    run_all_tests();
    tm orig;

    orig.tm_mday = 1;
    orig.tm_year = 118;
    orig.tm_mon = 4;

    std::stringstream orig_ss;
    orig_ss << std::put_time(&orig, "%Y-%m-%d %X");
    std::cout << orig_ss.str() << std::endl;

    time_t tmstmp = mktime(&orig);

    tm* there_and_back_again = localtime(&tmstmp);

//    chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
//    time_t in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream taba_ss;
    taba_ss << std::put_time(there_and_back_again, "%Y-%m-%d %X");
    std::cout << taba_ss.str() << std::endl;
    return 0;
}