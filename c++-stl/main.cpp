#include <iostream>
#include <vector>
#include <algorithm>

//容器入门：相当于是把元素复制了一份，拷贝到了容器中
void vectortest()
{
    std::vector<int> v1; //容器
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(3);

    //迭代器
    for(std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
        std::cout << *it << std::endl;
    }

    //算法 计算其中3的个数
    int num = std::count(v1.begin(), v1.end(), 3);
    std::cout << "3的个数是:" << num << std::endl;
}

//容器中存放类或者结构体
class Teacher {
public:
    int age;
    char name[32];
};
void vectortestStruct()
{
    Teacher t1, t2, t3;
    t1.age = 32;
    t2.age = 45;
    t3.age = 90;
    std::vector<Teacher> v2; //迭代器装类或者结构体
    v2.push_back(t1);
    v2.push_back(t2);
    v2.push_back(t3);

    for(std::vector<Teacher>::iterator it = v2.begin(); it != v2.end(); ++it) {
        std::cout << it->age << std::endl;
    }
}

//容器存放指针
void vectorTestPoint() {
    Teacher t1, t2, t3;
    t1.age = 32;
    t2.age = 45;
    t3.age = 90;
    std::vector<Teacher *> v3;
    v3.push_back(&t1);
    v3.push_back(&t2);
    v3.push_back(&t3);

    for(std::vector<Teacher *>::iterator it = v3.begin(); it != v3.end(); ++it) {
        std::cout << (*it)->age << std::endl;  //it相当于是指针的指针
    }
}

int main00() {
//    vectortest();
    //vectortestStruct();
    vectorTestPoint();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}