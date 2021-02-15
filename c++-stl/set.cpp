//
// Created by zhjwang on 2021-02-15.
//

#include "set"
#include <iostream>

//基本数据类型，默认是升序的
void main30()
{
    std::set<int> set1;
    for (int i = 0; i < 10; ++i) {
        int tmp = rand();
        set1.insert(tmp);
    }
    set1.insert(100);  //只会插入一个100
    set1.insert(100);
    set1.insert(100);

    std::cout << "set的大小：" <<set1.size() << std::endl; //11
    for(std::set<int>::iterator it = set1.begin(); it != set1.end(); it++) {
        std::cout << *it << std::endl;
    }
    //删除
    while(!set1.empty()) {
        std::set<int>::iterator it1 = set1.begin();
        std::cout << *it1 << std::endl;
        set1.erase(set1.begin());
    }
    std::cout << "set的大小：" <<set1.size() << std::endl; //0
}

//基本数据类型，指定从大到小，或者从小到大
void main31()
{
    std::set<int> set1;
    std::set<int, std::less<int>> set2; //默认从小到大
    std::set<int, std::greater<int>> set3; //从大到小
    for (int i = 0; i < 5; ++i) {
        int tmp = rand();
        set3.insert(tmp);
    }
    for(std::set<int ,std::greater<int>>::iterator it = set3.begin(); it != set3.end(); it++){
        std::cout << *it << std::endl;
    }
}

//对于复杂数据类型
//自定义数据类型的比较 ==》 仿函数
class Student {
public:
    Student(char *name, int age) {
        strcpy(this->name, name);
        this->age = age;
    }
    char name[64];
    int age;
};
//使用仿函数进行大小比较
struct FuncStudent
{
    bool operator()(const Student &left, const Student &right){
        if(left.age < right.age) {
            return true;
        }else{
            return false;
        }
    }
};
//插入返回值判断
void main32()
{
    std::set<Student, FuncStudent> set1;
    Student s1("s1", 31);
    Student s2("s2", 22);
    Student s3("s3", 44);
    Student s4("s4", 11);
    Student s5("s5", 31); //set集合是唯一，不会插入进去。按照年龄排序，发现年龄一样，不会插入

    set1.insert(s1);
    set1.insert(s2);
    set1.insert(s3);
    set1.insert(s4);
    //insert返回值判断
    std::pair<std::set<Student, FuncStudent>::iterator, bool> pair1 =  set1.insert(s5);
    if(pair1.second == true) {
        std::cout << "插入成功！" << std::endl;
    }else{
        std::cout << "插入失败！" << std::endl;
    }

    //遍历
    for(std::set<Student, FuncStudent>::iterator it = set1.begin(); it!=set1.end();it++){
        std::cout << it->age << "\t" << it->name << std::endl;
    }
}

//set的查找
void main33()
{
    std::set<int> set1;
    for (int i = 0; i < 10; ++i) {
        set1.insert(i);
    }
    //从小到大
    for(std::set<int ,std::greater<int>>::iterator it = set1.begin(); it != set1.end(); it++){
        std::cout << *it << std::endl;
    }
    std::set<int>::iterator it = set1.find(5);
    std::cout << "5的迭代器:" << *it << std::endl;//5
    int num = set1.count(5);
    std::cout << "5的个数:" << num << std::endl;//1
    std::set<int>::iterator it1 = set1.lower_bound(5);//大于等于5的第一个元素的迭代器的位置
    std::cout << "大于等于5的第一个元素迭代器：" << *it1 << std::endl;//5
    std::set<int>::iterator it2 = set1.upper_bound(5);//大于5的第一个元素的迭代器的位置
    std::cout << "大于5的第一个元素迭代器：" << *it2 << std::endl;//6

    //set1.erase(5);测试equal_range
    std::pair<std::set<int>::iterator ,std::set<int>::iterator> pair1 =  set1.equal_range(5);
    std::set<int>::iterator it3 = pair1.first;
    std::set<int>::iterator it4 = pair1.second;
    std::cout << *it3 << std::endl;//5
    std::cout << *it4 << std::endl;//6
}

int main34()
{
//    main30();
//    main31();
//    main32();
    main33();
    return 0;
}
