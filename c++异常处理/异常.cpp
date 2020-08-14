#include <iostream>
using namespace std;

int main()
{
    try{
        int *p = new int[99999999];
        cout << "test" << endl;  //假设上面一条出现了异常，那么这行之下的代码就不会再被执行了。
        cout << "test2" << endl;
    }catch(...){  //...表示可以捕获任意的异常
        cout << "产生了异常" << endl;
    }
    return 0;
}
