#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <numeric>
#include <vector>
#include <string>

using namespace std;

class DataBaseConnect
{
public:
    virtual bool login(string username, string password)
    {
        return true;
    }
    virtual bool logout(string username)
    {
        return true;
    }
    virtual int fetchRecord()
    {
        return -1;
    }
};

class MyDatabase
{
    DataBaseConnect &dbConnect;

public:
    MyDatabase(DataBaseConnect &_dbC) : dbConnect(_dbC) {}
    int Init(string uname, string passwd)
    {
        if (dbConnect.login(uname, passwd) != true)
        {
            cout << "Failed to connect >>>>> " << endl;
            return -1;
        }
        else
        {
            cout << "Successful Connection >>>>>" << endl;
            return 1;
        }
    }
};

class MockDB : public DataBaseConnect
{
public:
    MOCK_METHOD0(fetchRecord, int());
    MOCK_METHOD1(logout, bool(string uname));
    MOCK_METHOD2(login, bool(string uname, string passwd));
};

TEST(MyDBTest, LoginTest)
{
    // Arrange
    MockDB mdb;
    MyDatabase db(mdb);
    EXPECT_CALL(mdb, login("Terminator", "I'm Back"))
        .Times(1) //调用几次
        .WillOnce(::testing::Return(true));
    // Act
    int retValue = db.Init("Terminator", "I'm Back");
    // Assert
    EXPECT_EQ(retValue, 1);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}