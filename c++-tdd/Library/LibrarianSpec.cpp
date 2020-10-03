#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include "Librarian.h"

//test fixture
class bookSpec : public testing::Test
{
public:
    Librarian librarian;
};

TEST_F(bookSpec, ShouldIncreaseBookCountOnStore0)
{
    ASSERT_EQ(1, librarian.store("C++ Primer"));
    ASSERT_EQ(2, librarian.store("The C++ Programming Language"));
    ASSERT_EQ(3, librarian.store("Thinking in Java"));
}

TEST(Librarian, ShouldIncreaseBookCountOnStore)
{
    Librarian librarian;
    ASSERT_EQ(1, librarian.store("C++ Primer"));
    ASSERT_EQ(2, librarian.store("The C++ Programming Language"));
    ASSERT_EQ(3, librarian.store("Thinking in Java"));
}

TEST(Librarian, ShouldDecreaseBookCountOnBorrow)
{
    Librarian librarian;
    ASSERT_EQ(1, librarian.store("C++ Primer"));
    ASSERT_EQ(2, librarian.store("The C++ Programming Language"));
    ASSERT_EQ(1, librarian.borrow("C++ Primer"));
}

TEST(Librarian, ShouldThrowExceptionWhenNoBookIsAvailable)
{
    // how to assert an exception, look up the document
    Librarian librarian;
    ASSERT_THROW(librarian.borrow("c++"), std::runtime_error);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
