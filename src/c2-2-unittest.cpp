#include <gtest/gtest.h>
#include "c2-2.hpp"

int main(int argc, char const *argv[]) {
    printf("Running main() from %s\n", __FILE__);

    EXPECT_EQ(test(), 0);

    return 0;
}