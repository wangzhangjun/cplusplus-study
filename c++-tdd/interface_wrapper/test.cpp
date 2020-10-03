#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <numeric>
#include <vector>
#include <string>

using namespace std;

class IEngine
{
public:
    virtual ~IEngine() {}
    virtual void start() = 0;
};

class Engine : public IEngine
{
public:
    virtual void start()
    {
        cout << "engine start..." << endl;
    }
};

class Car
{
public:
    Car(IEngine &engine_) : engine(engine_)
    {
    }
    void run()
    {
        engine.start();
    }

private:
    IEngine &engine;
};

class MockIegine : public IEngine
{
public:
    MOCK_METHOD0(start, void());
};

TEST(car, shouldStartEngine)
{
    MockIegine MockIegine;
    EXPECT_CALL(MockIegine, start()).Times(1);
    Car car(MockIegine);
    car.run();
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}