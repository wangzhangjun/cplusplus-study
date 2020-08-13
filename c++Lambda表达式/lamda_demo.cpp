#include <iostream>
using namespace std;

/*
编译：g++ --std=c++11 lamda.cpp
*/

int add(int v1, int v2) {
	return v1 + v2;
}

int sub(int v1, int v2) {
	return v1 - v2;
}

int multiple(int v1, int v2) {
	return v1 * v2;
}

int divide(int v1, int v2) {
	return v1 / v2;
}

int exec(int v1, int v2, int (*func)(int, int)) {
	return func(v1, v2);
}

int main()
{
    cout << exec(1, 3, add) <<endl;
    cout << exec(1, 3, divide) <<endl;

    //上面的方式可以重构成这样的，减少了很多的代码
    cout << exec(1, 3, [] (int v1, int v2){return v1+v2;}) << endl;
    return 0;
}
