#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <numeric>
#include <vector>
#include <string>

template <class T>
class Test
{
public:
    virtual void push(const T &elem) = 0;
    virtual T pop() = 0;
};

template <class T>
class TestMock : public Test<T>
{
public:
    MOCK_METHOD1_T(push, void(const T &elem));
    MOCK_METHOD0_T(pop, T());
};

TEST(TemplateTest, ShouldAbleToBeMocked)
{
    TestMock<int> testmock;
    EXPECT_CALL(testmock, pop()).WillRepeatedly(testing::Return(3));
    ASSERT_EQ(3, testmock.pop());
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}