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

int main()
{
    main17();
    std::cout << "hello" << std::endl;
    return 0;
}
