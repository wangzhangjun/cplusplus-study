//
// Created by zhjwang on 2021-02-13.
//
#include <iostream>
#include <string>
#include <vector>

void main09()
{
    std::vector<int> v1;
    std::cout << v1.size() << std::endl; //0
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    std::cout << v1.size() << std::endl; //3
}
int main()
{
    main09();
    return 0;
}
