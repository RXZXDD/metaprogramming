#include<gtest/gtest.h>
#include<c3-5.hpp>

TEST(c35,t1) {
    using namespace xdd35;
    quantity<float, mass> m(1.f);
    quantity<float, acceleration> a(1.f);
    quantity<float, force> f(0.f);
    f = f+f;
    
    f = m*a;

   // f = f + m*a;

}