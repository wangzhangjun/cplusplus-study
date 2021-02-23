#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cctype>
#include <vector>
#include <set>
#include <string>

using namespace std;
bool MyCompare(const int &a, const int &b)
{
    printf("a:%d\n",a);
    printf("b:%d\n", b);
    return a < b;
}

void test()
{
    vector<int> v(10);

    for (int i = 0; i < 10; i++){
        v[i] = rand() % 100;
    }
    sort(v.begin(), v.end(), MyCompare);
    printf("\n");
    for (int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

struct CompareNoCase{
   bool operator()(const std::string &str1, const std::string &str2){
       std::string str1_;
       str1_.resize(str1.size());
       transform(str1.begin(), str1.end(), str1_.begin(), static_cast<int (*)(int)>(std::tolower)); //tolower预定义的函数对象

       std::string str2_;
       str2_.resize(str2.size());
       transform(str2.begin(), str2.end(), str2_.begin(), static_cast<int (*)(int)>(std::tolower)); //tolower预定义的函数对象

       return (str1_ < str2_); //从小到大排序
   } 
};

void test2()
{
    std::set<std::string> set1;
    set1.insert("aaa");
    set1.insert("bbb");
    set1.insert("ccc");
    std::set<std::string>::iterator it = set1.find("aaa"); //find默认是区分大小写的
    if(it != set1.end()) {
        std::cout << "find!" << std::endl;
    }

    //不区分大小写的查找
    std::set<std::string, CompareNoCase> set2;
    set2.insert("aaa");
    set2.insert("bbb");
    set2.insert("ccc");
    std::set<std::string, CompareNoCase>::iterator it2 = set2.find("aAa"); //find默认是区分大小写的
    if (it2 != set2.end())
    {
        std::cout << "No Case find!" << std::endl;
    }
}

int main()
{
    // test();
    test2();
    std::cout << "hello world" << std::endl;
}