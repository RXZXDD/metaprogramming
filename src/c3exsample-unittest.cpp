#include<gtest/gtest.h>
#include<c3exsample.hpp>

TEST(c3example, add)
{
    using namespace xdd;
    xdd::quantity<float, xdd::length> l(4.f);
    xdd::quantity<float, xdd::length> l2(6.f);
    EXPECT_EQ((l+l2).value(), 10.f);

            quantity<float, xdd::mass> m(5.0f);
        quantity<float, xdd::acceleration> a(9.8f);

        quantity<float,xdd::force> f = m*a;
       // quantity<float,length> f1 = m*a;

       quantity<float,xdd::mass> m2 = f/a;
       float rounding_error = std::abs((m2-m).value());

       EXPECT_NEAR(0.f, rounding_error, 0.001f);

}