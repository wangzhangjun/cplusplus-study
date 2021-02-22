#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

template <typename T>
class ShowElem
{
private:
    int n;
public:
    ShowElem(){
        n = 0;
    }
    void operator()(T &t) {
        n++;
        std::cout << t << std::endl;
    }
    void printN() {
        std::cout << n << std::endl;
    }
};

//类模板函数
template <typename T>
void funcShowElem(T &t)
{
    std::cout << t << std::endl;
}
//普通函数
void funcShowElem2(int t)
{
    std::cout << t << std::endl;
}
void test()
{
    int a = 10;
    ShowElem<int> showElem;
    showElem(a); //函数对象的执行，很像是一个函数的调用(参考funcShowElem和funcShowElem2)，所以又叫做仿函数
    funcShowElem<int>(a);
    funcShowElem2(a);
}

//函数对象是属于类的对象，能突破函数的概念，保持调用过程中的状态信息。
void test2()
{
    std::vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    //仿函数遍历
    for_each(v1.begin(), v1.end(), ShowElem<int>()); //第三个参数可以使用函数对象，在这里类名直接声明的称为“匿名函数对象”
    //普通函数遍历
    for_each(v1.begin(), v1.end(), funcShowElem2);  //谁使用for_each,谁填写回调函数的入口地址

    //测试状态
    ShowElem<int> showObj;
    for_each(v1.begin(), v1.end(), showObj); //for_each的第三个参数传递是值传递，不是引用传递。可以通过返回的是_Function，来得到改变的值
    showObj.printN();  //会发现打印出来是0

    std::cout << "通过for_each的返回值来看调用的次数：" << std::endl;
    
    ShowElem<int> showObj1;
    showObj1 = for_each(v1.begin(), v1.end(), showObj1); //for_each的第三个参数传递是值传递，不是引用传递。可以通过返回的是函数对象，来得到改变的值
    showObj1.printN(); //会发现打印出来是3
}

int main()
{
    // test();
    test2();
    std::cout << "hello world" << std::endl;
}