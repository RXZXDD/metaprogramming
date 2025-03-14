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

TEST(c50, push_back)
{
    Tiny<int, bool> t;
    typedef decltype(t)::type target;
    static_assert(mpl::size<target>::value == 2);
    typedef mpl::push_back<target, bool>::type result;
    static_assert(mpl::size<result>::value == 3);
    static_assert(std::is_same_v<result::t2, bool> == true);
    static_assert(std::is_same_v<result::t1, bool> == true);
    static_assert(std::is_same_v<result::t0, int> == true);

    Tiny<int > t2;
    typedef decltype(t2)::type target2;
    static_assert(mpl::size<target2>::value == 1);
    typedef mpl::push_back<target2, bool>::type result2;
    static_assert(mpl::size<result2>::value == 2);
    static_assert(std::is_same_v<result2::t2, none> == true);
    static_assert(std::is_same_v<result2::t1, bool> == true);
    static_assert(std::is_same_v<result2::t0, int> == true);

    
    Tiny t3;
    typedef decltype(t3)::type target3;
    static_assert(mpl::size<target3>::value == 0);
    typedef mpl::push_back<target3, bool>::type result3;
    static_assert(mpl::size<result3>::value == 1);
    static_assert(std::is_same_v<result3::t2, none> == true);
    static_assert(std::is_same_v<result3::t1, none> == true);
    static_assert(std::is_same_v<result3::t0, bool> == true);

    Tiny<none,int> t4;
    typedef decltype(t4)::type target4;
    static_assert(mpl::size<target4>::value == 2);
    typedef mpl::push_back<target4, bool>::type result4;
    static_assert(mpl::size<result4>::value == 3);
    static_assert(std::is_same_v<result4::t2, bool> == true);
    static_assert(std::is_same_v<result4::t1, int> == true);
    static_assert(std::is_same_v<result4::t0, none> == true);
    //compile error for 'tiny_push_back<tiny,T,3>': base class undefined
    // Tiny<int, bool, int> t2;
    // typedef decltype(t2)::type target2;
    // static_assert(mpl::size<target2>::value == 3);
    // typedef mpl::push_back<target2, bool>::type result2;
}

TEST(c50, push_front)
{
    Tiny<> t;
    typedef decltype(t)::type target;
    static_assert(mpl::size<target>::value == 0);
    typedef mpl::push_front<target, bool>::type result;
    static_assert(mpl::size<result>::value == 1);
    static_assert(std::is_same_v<result::t0, bool> == true);

    Tiny<int> t2;
    typedef decltype(t2)::type target2;
    static_assert(mpl::size<target2>::value == 1);
    typedef mpl::push_front<target2, bool>::type result2;
    static_assert(mpl::size<result2>::value == 2);
    static_assert(std::is_same_v<result2::t0, bool> == true);

    Tiny<int,float> t3;
    typedef decltype(t3)::type target3;
    static_assert(mpl::size<target3>::value == 2);
    typedef mpl::push_front<target3, double>::type result3;
    static_assert(mpl::size<result3>::value == 3);
    static_assert(std::is_same_v<result3::t0, double> == true);

    //COMPILE ERR
    // Tiny<int,float, bool> t4;
    // typedef decltype(t4)::type target4;
    // static_assert(mpl::size<target4>::value == 3);
    // typedef mpl::push_front<target4, double>::type result4;
    // static_assert(mpl::size<result4>::value == 3);
    // static_assert(std::is_same_v<result4::t0, double> == true);
}


TEST(c53, insert)
{
    Tiny t;
    typedef decltype(t)::type target;
    static_assert(mpl::size<target>::value == 0);
    typedef mpl::insert<target, mpl::int_<0>, int>::type result;
    static_assert(mpl::size<result>::value == 1);
    static_assert(true == std::is_same_v<result::t0, int>);
    
    Tiny t1;
    typedef decltype(t1)::type target1;
    static_assert(mpl::size<target1>::value == 0);
    typedef mpl::insert<target1, mpl::int_<1>, int>::type result1;
    static_assert(mpl::size<result1>::value == 2);
    static_assert(true == std::is_same_v<result1::t1, int>);
    static_assert(true == std::is_same_v<result1::t0, none>);
}


TEST(c54, erase_single)
{
    Tiny<int, bool, float> t;
    typedef decltype(t)::type target;
    typedef mpl::erase<target, mpl::int_<2>,mpl::int_<2>>::type result;
    static_assert(mpl::size<result>::value == 2);
    static_assert(std::is_same_v<result::t2, none> == true);
    static_assert(std::is_same_v<result::t1, bool> == true);
    static_assert(std::is_same_v<result::t0, int> == true);

    Tiny<int, bool, float > t2;
    typedef decltype(t2)::type target2;
    typedef mpl::erase<target2, mpl::int_<0>,mpl::int_<0>>::type result2;
    static_assert(mpl::size<result2>::value == 2);
    static_assert(std::is_same_v<result2::t2, none> == true);
    static_assert(std::is_same_v<result2::t1, float> == true);
    static_assert(std::is_same_v<result2::t0, bool> == true);

    Tiny<int, bool, float > t3;
    typedef decltype(t3)::type target3;
    typedef mpl::erase<target3, mpl::int_<1>,mpl::int_<1>>::type result3;
    static_assert(mpl::size<result3>::value == 2);
    static_assert(std::is_same_v<result3::t2, none> == true);
    static_assert(std::is_same_v<result3::t1, float> == true);
    static_assert(std::is_same_v<result3::t0, int> == true);

}

TEST(c54, erase_range_int)
{
    Tiny<int, bool, float> t;
    typedef decltype(t)::type target;
    typedef mpl::erase<target, mpl::int_<0>,mpl::int_<1>>::type result;
    static_assert(mpl::size<result>::value == 1);
    static_assert(std::is_same_v<result::t2, none> == true);
    static_assert(std::is_same_v<result::t1, none> == true);
    static_assert(std::is_same_v<result::t0, float> == true);

    Tiny<int, bool, float > t2;
    typedef decltype(t2)::type target2;
    typedef mpl::erase<target2, mpl::int_<1>,mpl::int_<2>>::type result2;
    static_assert(mpl::size<result2>::value == 1);
    static_assert(std::is_same_v<result2::t2, none> == true);
    static_assert(std::is_same_v<result2::t1, none> == true);
    static_assert(std::is_same_v<result2::t0, int> == true);

    // Tiny<int, bool, float > t3;
    // typedef decltype(t3)::type target3;
    // typedef mpl::erase<target3, mpl::int_<1>,mpl::int_<1>>::type result3;
    // static_assert(mpl::size<result3>::value == 2);
    // static_assert(std::is_same_v<result3::t2, none> == true);
    // static_assert(std::is_same_v<result3::t1, float> == true);
    // static_assert(std::is_same_v<result3::t0, int> == true);

}

TEST(c54, erase_range_ter)
{
    Tiny<int, bool, float> t;
    typedef decltype(t)::type target;
    typedef mpl::erase<target
                        ,Tiny_iterator<target, mpl::int_<0>>
                        ,Tiny_iterator<target, mpl::int_<1>>
                        >::type result;

    static_assert(mpl::size<result>::value == 1);
    static_assert(std::is_same_v<result::t2, none> == true);
    static_assert(std::is_same_v<result::t1, none> == true);
    static_assert(std::is_same_v<result::t0, float> == true);

    Tiny<int, bool, float > t2;
    typedef decltype(t2)::type target2;
    typedef mpl::erase<target2
                    ,Tiny_iterator<target2, mpl::int_<1>>
                    ,Tiny_iterator<target2, mpl::int_<2>>
                    >::type result2;
    static_assert(mpl::size<result2>::value == 1);
    static_assert(std::is_same_v<result2::t2, none> == true);
    static_assert(std::is_same_v<result2::t1, none> == true);
    static_assert(std::is_same_v<result2::t0, int> == true);

    // Tiny<int, bool, float > t3;
    // typedef decltype(t3)::type target3;
    // typedef mpl::erase<target3, mpl::int_<1>,mpl::int_<1>>::type result3;
    // static_assert(mpl::size<result3>::value == 2);
    // static_assert(std::is_same_v<result3::t2, none> == true);
    // static_assert(std::is_same_v<result3::t1, float> == true);
    // static_assert(std::is_same_v<result3::t0, int> == true);

}


TEST(c54, pop_front)
{
    Tiny<int, bool, float> t;
    typedef decltype(t)::type target;
    typedef mpl::pop_front<target>::type result;

    static_assert(mpl::size<result>::value == 2);
    static_assert(std::is_same_v<result::t2, none> == true);
    static_assert(std::is_same_v<result::t1, float> == true);
    static_assert(std::is_same_v<result::t0, bool> == true);
}

TEST(c54, pop_back)
{
    Tiny<int, bool, float> t;
    typedef decltype(t)::type target;
    typedef mpl::pop_back<target>::type result;

    static_assert(mpl::size<result>::value == 2);
    static_assert(std::is_same_v<result::t2, none> == true);
    static_assert(std::is_same_v<result::t1, bool> == true);
    static_assert(std::is_same_v<result::t0, int> == true);



}