#include "../src/math/include/math/math.h"
#include <gtest/gtest.h>

TEST(math_gtests, TestIntegerOne_Zero)
{
    const auto expected = 1;
    const auto actual = fibonacci(1);
    ASSERT_EQ(expected, actual);
}

TEST(math_gtests, TestIntegerTwo_True)
{
    const auto expected = true;
    const auto actual = isPrime(2);
    ASSERT_EQ(expected, actual);
}
TEST(math_gtests, TestIntegerFive_false)
{
    const auto expected = false;
    const auto actual = isPowerOfTwo(5);
    ASSERT_EQ(expected, actual);
}
TEST(math_gtests, TestInteger16_true)
{
    const auto expected = true;
    const auto actual = isPowerOfTwo(16);
    ASSERT_EQ(expected, actual);
}
int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}