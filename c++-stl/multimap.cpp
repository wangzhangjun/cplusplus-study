//
// Created by zhjwang on 2021-02-15.
//

//1个key值可以对应多个valude  =分组
//公司有销售部 sale （员工2名）、技术研发部 development （1人）、财务部 Financial （2人）
//人员信息有：姓名，年龄，电话、工资等组成
//通过 multimap进行 信息的插入、保存、显示
//分部门显示员工信息

#include "map"
#include <iostream>
#include <string>

class Person{
public:
    std::string name;
    int age;
    std::string tel;
    double saly;
};
void main40 ()
{
    Person p1, p2,p3,p4,p5;
    p1.name = "王1";
    p1.age = 31;

    p2.name = "王2";
    p2.age = 32;

    p3.name = "王3";
    p3.age = 31;

    p4.name = "王4";
    p4.age = 44;

    p5.name = "王5";
    p5.age = 55;

    std::multimap<std::string, Person> map2;
    //sale部门
    map2.insert(std::make_pair("sale", p1));
    map2.insert(std::make_pair("sale", p2));
    //development部门
    map2.insert(std::make_pair("development", p3));
    map2.insert(std::make_pair("development", p4));
    //financial 部门
    map2.insert(std::make_pair("financial", p5));

    for(std::multimap<std::string, Person>::iterator it = map2.begin();it!=map2.end();it++){
        std::cout << it->first << "\t" << it->second.name << std::endl;
    }
    std::cout << "遍历结束！" << std::endl;

    std::cout << "dev部门的人数：" << map2.count("development") << std::endl;
    std::cout << "dev部门的员工信息：" << std::endl;
    std::multimap<std::string ,Person>::iterator it2 = map2.find("development");
    int tag = 0; //find会把dev后面的都找到，所以用tag去记录下dev的数量
    while(it2 != map2.end() && tag < map2.count("development") )
    {
        std::cout << it2->first << "\t" << it2->second.name << std::endl;
        it2++;
        tag++;
    }

    std::cout << "修改！" << std::endl;
    //修改
    for(std::multimap<std::string, Person>::iterator it = map2.begin();it!=map2.end();it++){
        if(it->second.age == 32) {
            it->second.name = "name32";
        }
        std::cout << it->first << "\t" << it->second.name << std::endl;
    }
}

int main()
{
    main40();
}
