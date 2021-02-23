#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cctype>
#include <vector>
#include <set>
#include <string>

class IsGreat {
public:
    IsGreat(int i)
    {
        m_num = i;
    }

    bool operator()(int &num)
    {
        if(num > m_num) {
            return true;
        }
        return false;
    }

private:
    int m_num;
};
void test()
{
    std::vector<int> v1;
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i + 1);
    }

    for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        std::cout << *it << " ";
    }

    int num1 = std::count(v1.begin(), v1.end(), 3);
    std::cout << "num1:" << num1 << std::endl;

    //通过谓词求大于2的个数
    int num2 = std::count_if(v1.begin(), v1.end(), IsGreat(2));
    std::cout << "num2:" << num2 << std::endl;

    //通过预定义函数对象求大于2的个数
    /*
    greater<>()有两个参数，左参数来自容器的元素，右参数固定成2（通过bind2nd绑定的）
    */
    int num3 = std::count_if(v1.begin(), v1.end(), bind2nd(std::greater<int>(), 2));
    std::cout << "num3:" << num3 << std::endl;

    //取模 能被2整除的数 求奇数
    int num4 = count_if(v1.begin(), v1.end(), bind2nd(std::modulus<int>(), 2));
    std::cout << "奇数num4:" << num4 << std::endl;

    //求偶数
    int num5 = count_if(v1.begin(), v1.end(), std::not1(bind2nd(std::modulus<int>(), 2)));
    std::cout << "偶数num5:" << num5 << std::endl;
}

int main()
{
    test();
    std::cout << "hello world" << std::endl;
}