#include <iostream>
using namespace std;

/*
    编译：g++ --std=c++11 lamda_mutable.cpp
*/

int main()
{
    int a =  10;
    //1. 会出错，因为是值捕获，相当于执行10 = 10++
    // auto func = [a](){
    //     a++;
    // };
    // cout << a << endl;

    //2.mutable 相当于是在lamda表达式中int a  = 10
    auto func = [a]() mutable {
        a++;
        cout << a << endl;//11
    };
    cout << a << endl; //10
    func();
    
    return 0;
}
