#include "c2-3.hpp"
#include <gtest/gtest.h>


namespace {
    TEST(TypeTest, Singgle){
        EXPECT_STREQ(xdd::type_descriptor<int>().c_str(), "int");
        EXPECT_STREQ(xdd::type_descriptor<char>().c_str(), "char");
        EXPECT_STREQ(xdd::type_descriptor<long>().c_str(), "long");
        EXPECT_STREQ(xdd::type_descriptor<short>().c_str(), "short");
        EXPECT_STREQ(xdd::type_descriptor<void>().c_str(), "unknown");
    }

    TEST(TypeTest, pointer) {
         EXPECT_STREQ(xdd::type_descriptor<int*>().c_str(), "int*");
        EXPECT_STREQ(xdd::type_descriptor<char*>().c_str(), "char*");
        EXPECT_STREQ(xdd::type_descriptor<long*>().c_str(), "long*");
        EXPECT_STREQ(xdd::type_descriptor<short*>().c_str(), "short*");
        EXPECT_STREQ(xdd::type_descriptor<void*>().c_str(), "unknown*");

    }

    TEST(TypeTest, reference) {
         EXPECT_STREQ(xdd::type_descriptor<int&>().c_str(), "int&");
        EXPECT_STREQ(xdd::type_descriptor<char&>().c_str(), "char&");
        EXPECT_STREQ(xdd::type_descriptor<long&>().c_str(), "long&");
        EXPECT_STREQ(xdd::type_descriptor<short&>().c_str(), "short&");
        EXPECT_STREQ(xdd::type_descriptor<unsigned&>().c_str(), "unknown&")<<xdd::type_descriptor<unsigned&>().c_str();

    }

    TEST(TypeTest, Const) {
        EXPECT_STREQ(xdd::type_descriptor<int const>().c_str(), "int const");
        EXPECT_STREQ(xdd::type_descriptor<char const>().c_str(), "char const");
        EXPECT_STREQ(xdd::type_descriptor<long const>().c_str(), "long const");
        EXPECT_STREQ(xdd::type_descriptor<short const>().c_str(), "short const");

    }

    TEST(TypeTest, Compose) {
        EXPECT_STREQ(xdd::type_descriptor<int const* &>().c_str(), "int const*&");
        EXPECT_STREQ(xdd::type_descriptor<long const* &>().c_str(), "long const*&");
        EXPECT_STREQ(xdd::type_descriptor<long const* &>().c_str(), "long const*&");
    }
}

