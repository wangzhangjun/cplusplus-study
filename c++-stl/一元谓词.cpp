#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

template <typename T>
class isDiv
{
public:
    isDiv(T div){
        this->divison = div; 
    }
    bool operator()(T &t)
    {
        return (t % divison == 0);
    }

private:
    T divison;
};

void test()
{
    std::vector<int> v2;
    for (int i = 10; i < 33; i++)
    {
        v2.push_back(i);
    }
    
    int a = 4;
    isDiv<int> mydiv(a); //函数对象
    // find_if(v2.begin(), v2.end(), mydiv);
    std::vector<int>::iterator it = find_if(v2.begin(), v2.end(), mydiv); //find_if返回的是一个迭代器
    if (it != v2.end())
    {
        std::cout << "第一个被4整除的数是：" << *it << std::endl; //12
    }
}

int main()
{
    test();
    std::cout << "hello world" << std::endl;
}