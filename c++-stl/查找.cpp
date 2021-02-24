#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cctype>
#include <vector>
#include <set>
#include <string>

void test_adjacent_find()
{
    std::vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(4);
    vecInt.push_back(5);
    vecInt.push_back(5);

    std::vector<int>::iterator it = adjacent_find(vecInt.begin(), vecInt.end());
    if (it != vecInt.end())
    {
        std::cout << *it << std::endl; //2
    }
    //求index
    int index = std::distance(vecInt.begin(), it);
    std::cout << "index:" << index << std::endl; //1
}

//有序查找
void test_binary_search()
{
    std::vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(3);
    vecInt.push_back(5);
    vecInt.push_back(6);
    vecInt.push_back(7);
    vecInt.push_back(59);
    bool bFind = binary_search(vecInt.begin(), vecInt.end(), 5);
    if (bFind == true)
    {
        std::cout << "找到了！" << std::endl;
    }
}
void test_count()
{
    std::vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(3);
    vecInt.push_back(5);
    vecInt.push_back(6);
    vecInt.push_back(7);
    vecInt.push_back(59);
    int icount = std::count(vecInt.begin(), vecInt.end(), 7);
    std::cout << icount << std::endl; //1
}
bool GreaterThree(int iNum)
{
    if (iNum >= 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void test_count_if()
{
    std::vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(3);
    vecInt.push_back(5);
    vecInt.push_back(6);
    vecInt.push_back(7);
    vecInt.push_back(59);
    int num = count_if(vecInt.begin(), vecInt.end(), GreaterThree);
    std::cout << num << std::endl; //5
}

int main()
{
    test_adjacent_find();
    test_binary_search();
    test_count();
    test_count_if();
    std::cout << "hello world" << std::endl;
}