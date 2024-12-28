#include "c2-5.hpp"
#include <gtest/gtest.h>

namespace {
    TEST(C25, Single) {
        EXPECT_STREQ(xdd_w2::type_descriptor<int>().c_str(), "int");
        EXPECT_STREQ(xdd_w2::type_descriptor<char>().c_str(), "char");
        EXPECT_STREQ(xdd_w2::type_descriptor<long>().c_str(), "long");
        EXPECT_STREQ(xdd_w2::type_descriptor<short>().c_str(), "short");
        EXPECT_STREQ(xdd_w2::type_descriptor<void>().c_str(), "unknown");
    }

    
    TEST(C24, pointer) {
         EXPECT_STREQ(xdd_w2::type_descriptor<int*>().c_str(), "pointer to int");
        EXPECT_STREQ(xdd_w2::type_descriptor<char*>().c_str(), "pointer to char");
        EXPECT_STREQ(xdd_w2::type_descriptor<long*>().c_str(), "pointer to long");
        EXPECT_STREQ(xdd_w2::type_descriptor<short*>().c_str(), "pointer to short");
        EXPECT_STREQ(xdd_w2::type_descriptor<void*>().c_str(), "pointer to unknown");

    }

        TEST(C24, reference) {
         EXPECT_STREQ(xdd_w2::type_descriptor<int&>().c_str(), "reference to int");
        EXPECT_STREQ(xdd_w2::type_descriptor<char&>().c_str(), "reference to char");
        EXPECT_STREQ(xdd_w2::type_descriptor<long&>().c_str(), "reference to long");
        EXPECT_STREQ(xdd_w2::type_descriptor<short&>().c_str(), "reference to short");
        EXPECT_STREQ(xdd_w2::type_descriptor<unsigned&>().c_str(), "reference to unknown");

    }

        TEST(C24, Const) {
        EXPECT_STREQ(xdd_w2::type_descriptor<int const>().c_str(), "const int");
        EXPECT_STREQ(xdd_w2::type_descriptor<char const>().c_str(), "const char");
        EXPECT_STREQ(xdd_w2::type_descriptor<long const>().c_str(), "const long");
        EXPECT_STREQ(xdd_w2::type_descriptor<short const>().c_str(), "const short");

    }

        TEST(C24, Compose) {
        EXPECT_STREQ(xdd_w2::type_descriptor<int const* &>().c_str(), "reference to pointer to const int");
        EXPECT_STREQ(xdd_w2::type_descriptor<char const* &>().c_str(), "reference to pointer to const char");
        EXPECT_STREQ(xdd_w2::type_descriptor<long const* &>().c_str(), "reference to pointer to const long");
        EXPECT_STREQ(xdd_w2::type_descriptor<short const* &>().c_str(), "reference to pointer to const short");
       
       //TODO
       // EXPECT_STREQ(xdd_w2::type_descriptor<char*(*[])()>().c_str(), "array of pointer to function returning pointer to char");
    }


}