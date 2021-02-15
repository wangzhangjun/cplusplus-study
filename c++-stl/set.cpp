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

void main32()
{

}
int main()
{
//    main30();
    main31();
    return 0;
}
