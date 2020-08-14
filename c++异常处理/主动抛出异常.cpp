#include <iostream>
using namespace std;

int divide(int v1, int v2)
{
    int c = 0;
    try{
        c = v1 / c;  //这样的是不会抛出异常，所以下面的catch也捕获不住
    }catch(...){  //...表示可以捕获任意的异常
        cout << "产生了异常" << endl;
    }
    return c;
}

int divide1(int v1, int v2) throw(int, const char*) //为了增强可读性和方便团队合作，建议函数声明一下异常类型。改声明表示只抛出int,double类型的异常
{
    if(v2 == 0){
        throw "444"; //抛出异常，注意，一旦抛出异常，后面的代码就不会再执行了。
    }
    return v1/v2;
}

//throw抛出后，首先会在当前函数中查找匹配的catch， 找不到就终止当前函数代码，去上一层函数中
//查找。如果最终都找不到匹配的catch,整个程序就会终止
void func1() {
	cout << "func1-begin" << endl;
	throw 666;  //throw以后的代码不会执行

    //在当前函数中查找catch如下
    // try{
    //     throw 666;
    // }catch(...){
    //     cout << "异常" << endl;
    // }
	cout << "func1-end" << endl;
}

void func2() {
	cout << "func2-begin" << endl;
	func1();
	cout << "func2-end" << endl;
}

void test3() {
	cout << "main-begin" << endl;
	try {
		func2();
	} catch (int exception) {
		cout << "产生异常了(int):" << exception << endl;
	}
	cout << "main-end" << endl;
}

int main()
{
    int a = 10;
    int b = 0;
    int ret = 0;

    //ret = divide(a,b);

    try{
        cout << divide1(a,b)<<endl;
    }catch(int execption){   //999的异常会被这里捕获，所以会输出“产生异常了”.catch的参数类型要和throw的类型保持一致
        cout << "产生异常了" << endl;
        cout << execption << endl;  //999,
    }catch(const char * execption){  //可以catch多个异常类型，根据throw的类型不同捕获
        cout << "产生异常了string" << endl;
        cout << execption << endl;
    }

    test3();
    return 0;
}
