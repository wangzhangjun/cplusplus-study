//
// Created by zhjwang on 2021-02-15.
//

#include <iostream>
#include "queue"

using namespace std;
/*
 * 最大值优先级队列、最小值优先级队列. 会默认的排序
 * 优先级队列适配器 STL priority_queue,用来开发一些特殊的场景
 * */
void main28()
{
    std::priority_queue<int> p1; //默认是 最大值优先级队列
    std::priority_queue<int, std::vector<int>, std::less<int> > p2; //最大值优先
    std::priority_queue<int, std::vector<int>, std::greater<int> > p3; //最小值优先

    p1.push(33);
    p1.push(11);
    p1.push(55);
    p1.push(22);
    cout <<"队列大小" << p1.size() << endl;
    cout <<"队头" << p1.top() << endl;

    while (p1.size() > 0)
    {
        cout << p1.top() << " ";
        p1.pop();
    }
    cout << endl;

    std::cout << "===========最大值优先：" << std::endl;
    p2.push(33);
    p2.push(11);
    p2.push(55);
    p2.push(22);
    while (p2.size() > 0)
    {
        cout << p2.top() << " ";
        p2.pop();
    }
    std::cout << std::endl;
    std::cout << "===========最小值优先：" << std::endl;
    p3.push(33);
    p3.push(11);
    p3.push(55);
    p3.push(22);
    while (p3.size() > 0)
    {
        cout << p3.top() << " ";
        p3.pop();
    }
}

int main29()
{
    main28();
}
