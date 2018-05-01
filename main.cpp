#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;
int main()
{
    chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

    time_t in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;

    auto tm = std::localtime(&in_time_t);

    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");

    std::cout << ss.str() << std::endl;
    return 0;
}