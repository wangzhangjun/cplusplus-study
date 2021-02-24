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
void printfVector(std::vector<int> &v1)
{
    std::for_each(v1.begin(), v1.end(), showVector);
    std::cout << std::endl;
}

int increase(int &n) 
{
    return n+1;
}

void test()
{
    std::vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    //使用回调函数
    std::transform(v1.begin(), v1.end(), v1.begin(), increase);
    printfVector(v1);

    //使用预定义的函数对象negate：改成负数
    std::transform(v1.begin(), v1.end(), v1.begin(), std::negate<int>());
    printfVector(v1); //-2 -4 -6

    //使用函数适配器
    std::transform(v1.begin(), v1.end(), v1.begin(), std::bind2nd(std::multiplies<int>(),10));  //都乘以10
    printfVector(v1);                                                                           
}

int main()
{
    test();
    std::cout << "hello world" << std::endl;
}