#if 0
#include "../include/work/HammingCode/hamming.h"
#include <gtest/gtest.h>

//LFLAGS = -lgtest_main -lgtest -pthread

//global resource here

TEST(group1, test1)
{
    EXPECT_TRUE(get_k(1) == 2);
    EXPECT_TRUE(get_k(2) == 3);
    EXPECT_TRUE(get_k(4) == 3);
    EXPECT_TRUE(get_k(5) == 4);
    EXPECT_TRUE(get_k(11) == 4);
    EXPECT_TRUE(get_k(12) == 5);
    EXPECT_TRUE(get_k(26) == 5);
    EXPECT_TRUE(get_k(27) == 6);
    EXPECT_TRUE(get_k(57) == 6);
    EXPECT_TRUE(get_k(58) == 7);
    EXPECT_TRUE(get_k(120) == 7);
}

TEST(group1, test2)
{
    EXPECT_TRUE(true);
}

TEST(group1, test3)
{
    EXPECT_TRUE(true);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//EXPECT        : when fail continue
//ASSERT        : when fail stop
#endif