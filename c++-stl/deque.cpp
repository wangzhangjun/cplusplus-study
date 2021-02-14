//
// Created by zhjwang on 2021-02-14.
//

#include <iostream>
#include <queue>
#include <algorithm>

//迭代器遍历
void printD(std::deque<int> &d)
{
    for(std::deque<int>::iterator it = d.begin(); it != d.end(); ++it){
        std::cout << *it << " " ;
    }
    std::cout  << std::endl;
}

void main15()
{
    std::deque<int> dl;
    dl.push_back(1);
    dl.push_back(3);
    dl.push_back(5);

    dl.push_front(-11);
    dl.push_front(-33);
    dl.push_front(-55);

    std::cout << "头部元素：" << dl.front() << std::endl;
    std::cout << "尾部元素：" << dl.back() << std::endl;

    printD(dl);

    dl.pop_front();  //弹出头部
    dl.pop_back();  //弹出尾部

    printD(dl);

    //查找-33在数组的下标的值
    std::deque<int>::iterator it  = std::find(dl.begin(),dl.end(),-33);
    if(it != dl.end())
    {
        std::cout << "-33下标是：" << std::distance(dl.begin(),it) <<std::endl;
    }else{
        std::cout << "-33没有找到" <<std::endl;
    }
}
int main()
{
    main15();
    std::cout << "hello.." << std::endl;
    return 0;
}
