#include<gtest/gtest.h>
#include<c5-7.hpp>
#include<boost/static_assert.hpp>

using namespace boost;

TEST(c57, Q)
{
   typedef demension<char [10][5][2]> seq;
   BOOST_STATIC_ASSERT(mpl::size<seq>::value == 3);
   BOOST_STATIC_ASSERT(mpl::at_c<seq,0>::type::value == 2);
   BOOST_STATIC_ASSERT(mpl::at_c<seq,1>::type::value == 5);
   BOOST_STATIC_ASSERT(mpl::at_c<seq,2>::type::value == 10);
   BOOST_STATIC_ASSERT(std::is_same_v<mpl::at_c<seq,2>::AT, char>);
}