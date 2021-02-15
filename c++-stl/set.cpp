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
void main32()
{
    std::set<Student, FuncStudent> set1;
    Student s1("s1", 31);
    Student s2("s2", 22);
    Student s3("s3", 44);
    Student s4("s4", 11);
    set1.insert(s1);
    set1.insert(s2);
    set1.insert(s3);
    set1.insert(s4);
    //遍历
    for(std::set<Student, FuncStudent>::iterator it = set1.begin(); it!=set1.end();it++){
        std::cout << it->age << "\t" << it->name << std::endl;
    }
}

int main()
{
//    main30();
//    main31();
    main32();
    return 0;
}
