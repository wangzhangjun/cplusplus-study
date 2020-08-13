#include <iostream>
using namespace std;

/*
编译：g++ --std=c++11 lamda.cpp
*/

int main()
{
    //1. 定义最简单的lamda表达式
    // [] {
    //     cout << "func" << endl;
    // }

    //2. 如何调用上面的lamda表达式 ，加括号
    ([]{
        cout << "func" << endl;
    })();

    //3. lamda表达式本质是函数, 所以以下的方式是把一个lamda表达式保存起来。
    void (*p)() = [] {
        cout << "func" << endl;
    };
    //调用
    p();
    //可以用auto
    auto p1 = [] {
        cout << "func" << endl;
    };
    p1();

    //4. 带参数的lamda
    //->后面跟的是return type, 返回值类型是可以省略的
    auto p2 = [] (int a, int b) -> int {
        return a + b;
    };
    cout << p2(1,2) <<endl;
    cout << p2(3,4) << endl;
    return 0;
}
