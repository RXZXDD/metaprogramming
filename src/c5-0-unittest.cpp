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

TEST(c50, distance)
{
    Tiny<int, bool, float> t;
    typedef mpl::begin<decltype(t)>::type begin;
    typedef mpl::end<decltype(t)>::type end;


    constexpr bool b = mpl::distance<begin, end>::value == 3;
    static_assert(b == true);

}

TEST(c50, deref)
{
    Tiny<int, bool, float> t;
    typedef mpl::begin<decltype(t)>::type begin;
    typedef mpl::next<begin>::type supose_bool;
    constexpr bool b = std::is_same_v<mpl::deref<supose_bool>::type
                            , mpl::deref<mpl::advance<begin, mpl::int_<1>>::type>::type>;
    static_assert(b == true);

}