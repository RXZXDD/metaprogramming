#include "c2-4.hpp"
#include <gtest/gtest.h>

namespace{
    TEST(C24, Singgle){
        EXPECT_STREQ(xdd_w1::type_descriptor<int>().c_str(), "int");
        EXPECT_STREQ(xdd_w1::type_descriptor<char>().c_str(), "char");
        EXPECT_STREQ(xdd_w1::type_descriptor<long>().c_str(), "long");
        EXPECT_STREQ(xdd_w1::type_descriptor<short>().c_str(), "short");
        EXPECT_STREQ(xdd_w1::type_descriptor<void>().c_str(), "unknown");
    }

    TEST(C24, pointer) {
         EXPECT_STREQ(xdd_w1::type_descriptor<int*>().c_str(), "int*");
        EXPECT_STREQ(xdd_w1::type_descriptor<char*>().c_str(), "char*");
        EXPECT_STREQ(xdd_w1::type_descriptor<long*>().c_str(), "long*");
        EXPECT_STREQ(xdd_w1::type_descriptor<short*>().c_str(), "short*");
        EXPECT_STREQ(xdd_w1::type_descriptor<void*>().c_str(), "unknown*");

    }

    TEST(C24, reference) {
         EXPECT_STREQ(xdd_w1::type_descriptor<int&>().c_str(), "int&");
        EXPECT_STREQ(xdd_w1::type_descriptor<char&>().c_str(), "char&");
        EXPECT_STREQ(xdd_w1::type_descriptor<long&>().c_str(), "long&");
        EXPECT_STREQ(xdd_w1::type_descriptor<short&>().c_str(), "short&");
        EXPECT_STREQ(xdd_w1::type_descriptor<unsigned&>().c_str(), "unknown&")<<xdd_w1::type_descriptor<unsigned&>().c_str();

    }

    TEST(C24, Const) {
        EXPECT_STREQ(xdd_w1::type_descriptor<int const>().c_str(), "int const");
        EXPECT_STREQ(xdd_w1::type_descriptor<char const>().c_str(), "char const");
        EXPECT_STREQ(xdd_w1::type_descriptor<long const>().c_str(), "long const");
        EXPECT_STREQ(xdd_w1::type_descriptor<short const>().c_str(), "short const");

    }

    TEST(C24, Compose) {
        EXPECT_STREQ(xdd_w1::type_descriptor<int const* &>().c_str(), "int const*&");
        EXPECT_STREQ(xdd_w1::type_descriptor<long const* &>().c_str(), "long const*&");
        EXPECT_STREQ(xdd_w1::type_descriptor<long const* &>().c_str(), "long const*&");
    }
}