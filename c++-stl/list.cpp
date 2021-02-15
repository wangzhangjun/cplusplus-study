//
// Created by zhjwang on 2021-02-15.
//

#include <iostream>
#include "list"

void main25()
{
    std::list<int> testList;
    std::cout << "list的大小：" <<testList.size() << std::endl; //0
    for (int i = 0; i < 10; ++i) {
        testList.push_back(i);//尾部插入
    }
    testList.push_front(250);//头部插入
    std::cout << "list的大小：" <<testList.size() << std::endl; //10

    //迭代遍历
    for(std::list<int>::iterator it = testList.begin(); it!=testList.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "=========插入：==========" <<std::endl;
    //list不能随机访问
    std::list<int>::iterator it1 = testList.begin();
    it1 ++;
    it1 ++;
    //it1  = it1 + 2;//不支持随机访问

    //插入
    /*
     * 结论：链表的下标是从0开始
     *  在3号位置插入，是让原来的的3号位置变为4号位置，让4号变为5号
     * */
    testList.insert(it1, 100);//100插入到了什么位置？
    for(std::list<int>::iterator it = testList.begin(); it!=testList.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

void main26()
{
    std::list<int> testList;
    for (int i = 0; i < 10; ++i) {
        testList.push_back(i);//尾部插入
    }
    testList.push_front(3);
    testList.push_front(3);
    testList.push_front(3);

    testList.push_front(4);
    testList.push_front(4);

    //删除所有值为3的元素
    for(std::list<int>::iterator it = testList.begin(); it != testList.end();) {
        if(*it == 3) {
            it = testList.erase(it);
        }else{
            it++;
        }
    }
    testList.remove(4);//删除所有值为4的元素

    for(std::list<int>::iterator it = testList.begin(); it!=testList.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

int main27()
{
    main26();
    return 0;
}
