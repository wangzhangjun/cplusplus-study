#include <iostream>
using namespace std;

/*
    编译：g++ --std=c++11 lamda_捕获.cpp
*/
int main()
{
    int a = 10;
    int b = 10;

	// 1.默认都是值捕获
	auto func = [a] {
		cout << a << endl;//10
	};
    a = 20; //不影响输出，因为是值捕获，将值捕获了进来
    func();
    //全部捕获(隐式捕获)，值捕获
    auto func1 = [=] {
		cout << a << endl;//10
        cout << b << endl;//10
	};
    func1();

    //2. 地址捕获
    auto func2 = [&a] {
		cout << a << endl;//30
	};
	a = 30;
	func2();

    //3.a是值捕获，其余变量都是地址捕获
    auto func3 = [&, a]{
        cout << a << endl;
        cout << b << endl;
    };
    func3();

    //4.a是地址捕获，其余变量都是值捕获
    auto func4 = [= , &a] {
        cout << a << endl;
        cout << b << endl;
    };
    func4();

    return 0;
}
