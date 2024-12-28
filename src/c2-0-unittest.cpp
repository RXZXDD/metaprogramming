#include "c2-0.hpp"
#include <gtest/gtest.h>

int main(){
    printf("Running main() from %s\n", __FILE__);

    EXPECT_EQ(test(), 0);
    //EXPECT_EQ(test(), 1) << "FAILED";

    return 0;
}
