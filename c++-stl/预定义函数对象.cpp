#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cctype>
#include <vector>
#include <set>
#include <string>

void test()
{
    //普通类型相加
    std::plus<int> intAdd;
    int x = 10;
    int y = 11;
    int z = intAdd(x,y);
    std::cout << z << std::endl;  //21

    //string相加
    std::plus<std::string> stringAdd;
    std::string x1 = "aaa";
    std::string y1 = "bbb";
    std::string z1 = stringAdd(x1,y1);
    std::cout << z1 << std::endl;  //aaabbb

    std::vector<std::string> v1;
    v1.push_back("bbb");
    v1.push_back("aaa");
    v1.push_back("ccc");
    v1.push_back("ccc");
    v1.push_back("ccc");
    v1.push_back("zzzz");

    //缺省情况下，sort()以升序排列容器的元素
    //为了降序，可以传递预定义的类模板greater,它调用底层元素类型的大于操作符：
    sort(v1.begin(), v1.end(), std::greater<std::string>());
    for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) 
    {
        std::cout << *it << std::endl;  //从大到小排序
    }

    std::string s1 = "ccc";
    /*
        std::equal_to<std::string>()是两个参数，left参数来自容器，right参数来自s1。
        bind2nd是函数适配器,把预定义函数对象和第二个参数进行绑定。
    */
    // int num = std::count_if(v1.begin(), v1.end(), std::equal_to<std::string>(), s1);  //这样是不通过的
    int num = count_if(v1.begin(), v1.end(), std::bind2nd(std::equal_to<std::string>(), s1)); //bind2nd是函数适配器
    std::cout << num << std::endl; //3
}
int main()
{
    test();
    std::cout << "hello world" << std::endl;
}