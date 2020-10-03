#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <numeric>
#include <vector>
// 测试集为 MyTest，测试案例为 Sum
TEST(MyTest, ShouldAddTwoOperands)
{
    ASSERT_EQ(2, 1 + 1);
    ASSERT_NE(2, 1 + 1);
    std::cout << "123" << std::endl;
    EXPECT_TRUE((1 + 1 == 2));
}
int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
