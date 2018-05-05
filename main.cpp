#include <iostream>
#include "Goods.h"
using namespace std;


//void storeDemo();


int main()
{
//    run_all_tests();
    Goods g;

    return 0;
}

//void datePlaying()
//{
//    auto zone = locate_zone("Europe/Tallinn");
//    auto utc_time = system_clock::now();
//    auto z_time = make_zoned(zone, utc_time);
//    auto z_days = floor<days>(z_time.get_local_time());
//    auto z_date = year_month_day(z_days);
//
//    std::cout << "UTC time :"  << utc_time<< '\n';
//    std::cout << "Local Time: " << z_time.get_local_time() << '\n';
//    std::cout << z_date << '\n';
//}

//void storeDemo()
//{
//    Store st;
//
//    const Goods unicorn_wand(0, "magical wands made from unicorn's horn", 150);
//    const Goods fenix_wand(1, "magical wands made from the fenix's feather", 300);
//
//    cout << "just registered: \n";
//    st.registerGoods(unicorn_wand, 5);
//    st.registerGoods(fenix_wand, 10);
//    st.show();
//
//    cout << "\nincluded supplies: \n";
//    st.include(unicorn_wand, Supply(7, kInPast, kInFutureSooner));
//    st.include(unicorn_wand, Supply(15, kInPast, kInFutureLater));
//
//    st.include(fenix_wand, Supply(17, kInPast, kInFutureSooner));
//    st.include(fenix_wand, Supply(19, kInPast, kInFutureLater));
//    st.show();
//
//    cout << "\nexcluded supplies: \n";
//    st.exclude(unicorn_wand, 9);
//    st.exclude(fenix_wand, 12);
//    st.show();
//}
