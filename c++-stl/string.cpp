//
// Created by zhjwang on 2021-02-12.
//

#include <iostream>
#include <string>

//string构造
void main01()
{
    std::string s1 = "123";
    std::string s2("456");
    std::string s3(s1);
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
}
int main(){
    main01();
    std::cout << "hello world" << std::endl;
    return 0;
}