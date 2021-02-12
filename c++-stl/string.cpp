//
// Created by zhjwang on 2021-02-12.
//

#include <iostream>
#include <string>

//string构造
/*
 * 1. sring() //构造一个口弄个的字符串
 * 2. string(const string &str) //构造一个与str一样的string。如string s1(s2)。
 * 3. string(const char *s);    //用字符串s初始化
 * 4. string(int n,char c);    //用n个字符c初始化
 * */
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