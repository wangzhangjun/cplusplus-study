#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cctype>
#include <vector>
#include <set>
#include <string>

void showVector(int &n) 
{
    std::cout << n << " ";
}

class showElem{
public:
    showElem(){
        n = 0;
    }
    void operator()(int &num){
        this->n++;
        std::cout << num << " ";
    }
    void printN(){
        std::cout << "执行了n次：" << this->n << std::endl;;
    }
private:
    int n;
};

void test()
{
    std::vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    //方法1，for_each第三个参数是一个回调函数
    std::for_each(v1.begin(), v1.end(), showVector);
    std::cout << std::endl;

    //方法1，for_each第三个参数是一个函数对象
    showElem obj = std::for_each(v1.begin(), v1.end(), showElem());
    obj.printN(); //3
    std::cout << std::endl;

    //这样就无法获取n的值
    showElem test;
    std::for_each(v1.begin(), v1.end(), test);
    test.printN(); //0
    /*
    这是因为：for_each的函数原型
    _Function for_each(_InputIterator __first, _InputIterator __last, _Function __f)
    {
        for (; __first != __last; ++__first)
            __f(*__first);
        return __f;
    }
    第三个形参被赋值后，在函数里面对其修改不会改变实参的任何值。
    所以需要采用返回值的形式来获取，for_each返回一个函数对象
    */
}

int main()
{
    test();
    std::cout << "hello world" << std::endl;
}