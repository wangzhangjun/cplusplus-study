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
    std::cout << "list的大小：" <<testList.size() << std::endl; //10

    //迭代遍历
    for(std::list<int>::iterator it = testList.begin(); it!=testList.end(); ++it) {
        std::cout << *it << std::endl;
    }

    //list不能随机访问
    
}

int main()
{
    main25();
    return 0;
}
