#include<gtest/gtest.h>
#include<c4-2.hpp>




TEST(c42, or)
{
    class ta{};

    bool a = Logical_or<false, false, false, false, true>::value;
    EXPECT_TRUE(a == true);
}

TEST(c42, and)
{


    bool a = Logical_and<false, true, true, true, true>::value;
    EXPECT_TRUE(a == false);

    
    bool b = Logical_and<true, true, true, true, true>::value;
    EXPECT_TRUE(b == true);
}