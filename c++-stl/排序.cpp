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

void test_merge()
{
    std::vector<int> v1, v2, v3;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);

    v3.resize(v1.size() + v2.size());

    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    printfVector(v3); //123456
}

class CStudent
{
public:
    std::string m_name;
    int m_id;
    CStudent(int id, std::string name)
    {
        m_name = name;
        m_id = id;
    }
};
bool Compares(const CStudent &s1, const CStudent &s2)
{
    return (s1.m_id < s2.m_id);
}
void showStudent(CStudent &stu)
{
    std::cout << "name： " << stu.m_name << "id: " << stu.m_id << std::endl;
}
void test_sort()
{
    std::vector<CStudent> vecStu;
    vecStu.push_back(CStudent(2, "老二"));
    vecStu.push_back(CStudent(1, "老大"));
    vecStu.push_back(CStudent(3, "老三"));
    vecStu.push_back(CStudent(4, "老四"));
    std::sort(vecStu.begin(), vecStu.end(), Compares);
    std::for_each(vecStu.begin(), vecStu.end(), showStudent);
}
int main()
{
    // test_merge();
    test_sort();
    std::cout << "hello world" << std::endl;
}