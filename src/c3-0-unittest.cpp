#include<gtest/gtest.h>
#include<c3-0.hpp>


TEST(c30, t1) {
    EXPECT_EQ(binary<1>::value, 1);
    EXPECT_EQ(binary<10>::value, 2);
    EXPECT_EQ(binary<101>::value, 5);
    //error 
    //EXPECT_EQ(binary<102>::value, 5);
    //EXPECT_EQ(binary<103>::value, 5);
    //EXPECT_EQ(binary<104>::value, 5);
    //EXPECT_EQ(binary<105>::value, 5);
    //EXPECT_EQ(binary<106>::value, 5);
    //EXPECT_EQ(binary<107>::value, 5);
    //EXPECT_EQ(binary<108>::value, 5);
    //EXPECT_EQ(binary<109>::value, 5);
}