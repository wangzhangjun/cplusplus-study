//
// Created by zhjwang on 2021-02-15.
// 队列 :先进先出
//

#include <iostream>
#include "queue"

//队列基本类型
void main21()
{
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    std::cout << "队头元素：" << q.front() << std::endl;
    std::cout << "队大小：" << q.size() << std::endl;
    while(!q.empty()) {
        int tmp = q.front();
        std::cout << tmp<<std::endl;
        q.pop();
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
void main22()
{
    Teacher t1,t2,t3;
    t1.age = 12;
    t2.age = 34;
    t3.age = 90;
    std::queue<Teacher> t;
    t.push(t1);
    t.push(t2);
    t.push(t3);
    while(!t.empty()) {
        Teacher tmp = t.front();
        std::cout << tmp.age <<std::endl;
        t.pop();
    }
}
void main23()
{
    Teacher t1,t2,t3;
    t1.age = 12;
    t2.age = 34;
    t3.age = 90;
    std::queue<Teacher *> t;
    t.push(&t1);
    t.push(&t2);
    t.push(&t3);
    while(!t.empty()) {
        Teacher *tmp = t.front();
        std::cout << tmp->age <<std::endl;
        t.pop();
    }
}

int main()
{
    main23();
    return 0;
}
