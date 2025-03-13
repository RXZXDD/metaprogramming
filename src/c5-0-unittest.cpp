#include<gtest/gtest.h>
#include<c5-0.hpp>


TEST(c50, at)
{
    Tiny<int, bool, float> t;

    constexpr bool b = std::is_same<
                    mpl::at<decltype(t),mpl::int_<1>>::type
                    , bool
                    >::value;
    static_assert(b == true);

}

TEST(c50, begin)
{
    Tiny<int, bool, float> t;
    typedef mpl::begin<decltype(t)>::type begin;
    typedef mpl::end<decltype(t)>::type end;


    constexpr bool b = mpl::distance<begin, end>::value == 3;
    static_assert(b == true);

}

// TEST(c50, end)
// {
//     Tiny<int, bool, float> t;

//     constexpr bool b = std::is_same<
//                     mpl::end<decltype(t)>::type
//                     , bool
//                     >::value;
//     static_assert(b == true);

// }