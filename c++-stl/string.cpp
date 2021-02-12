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
//遍历
void main02()
{
    std::string s1 = "abcdef";
    std::cout << "数组方式：" << std::endl;
    //数组方式
    for(int i = 0; i < s1.length(); i++) {
        std::cout << s1[i] ;
    }
    std::cout << std::endl;
    std::cout << "迭代器方式：" << std::endl;
    //迭代器
    for(std::string::iterator it = s1.begin(); it != s1.end(); ++it) {
        std::cout << *it ;
    }
    std::cout << std::endl;
    //at方式
    std::cout << "at方式：" << std::endl;
    //at方式
    for(int i = 0; i < s1.length(); i++) {
        std::cout << s1.at(i) ;
    }
    std::cout << std::endl;


}
int main(){
//    main01();
    main02();
    std::cout << "hello world" << std::endl;
    return 0;
}