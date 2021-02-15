//
// Created by zhjwang on 2021-02-15.
//

#include <iostream>
#include "stack"

void main17()
{
    std::stack<int> s;

    //入栈
    for(int i = 0; i<10; i++) {
        s.push(i+1);
    }
    std::cout << "栈大小：" << s.size() << std::endl; //栈的大小
    //出栈
    while(!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();  //出栈
    }
}

 //复杂类型
 class Teacher{
 public:
    int age;
    char name[32];
 public:
    void printT(){
        std::cout << "age:" << this->age << std::endl;
    }
 };

void main18(){
    Teacher t1,t2,t3;
    t1.age = 12;
    t2.age = 34;
    t3.age = 90;

    std::stack<Teacher> t;
    //相当于是把t1,t2,t3复制了一份到容器中。所以必须是可以复制的，不能存在深拷贝和浅拷贝的问题
    t.push(t1);
    t.push(t2);
    t.push(t3);

    while(!t.empty()){
        std::cout << t.top().age << std::endl;
        t.pop();
    }
}

void main19()
{
    Teacher t1,t2,t3;
    t1.age = 12;
    t2.age = 34;
    t3.age = 90;
    std::stack<Teacher *> t;
    t.push(&t1);
    t.push(&t2);
    t.push(&t3);
    while(!t.empty()){
        Teacher *tmp = t.top();
        tmp->printT();
        t.pop();
    }

}

int main()
{
//    main17();
//    main18();
    main19();
    std::cout << "hello" << std::endl;
    return 0;
}
