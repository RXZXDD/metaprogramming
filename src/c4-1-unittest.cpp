#include<gtest/gtest.h>
#include<c4-1.hpp>




TEST(c41, or)
{
    class ta{};

    bool a = is_same<ParamTypeOr<int>::type, int>::value;
    bool b = is_same<ParamTypeOr<ta>::type, const ta>::value;//
    bool c = is_same<ParamTypeOr<c40>::type, c40>::value;
    EXPECT_TRUE(a == true);
    EXPECT_TRUE(b == true);
    EXPECT_TRUE(c == true);
}

TEST(c41, and)
{
    class ta{};

    bool a = is_same<ParamTypeAnd<int>::type,const int>::value;//
    bool b = is_same<ParamTypeAnd<long>::type, long>::value;
    bool c = is_same<ParamTypeAnd<c40>::type, c40>::value;
    EXPECT_TRUE(a == true);
    EXPECT_TRUE(b == true);
    EXPECT_TRUE(c == true);
}