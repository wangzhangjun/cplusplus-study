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
    //数组方式
    std::cout << "数组方式：" << std::endl;
    for(int i = 0; i < s1.length(); i++) {
        std::cout << s1[i] ;
    }
    std::cout << std::endl;

    //迭代器
    std::cout << "迭代器方式：" << std::endl;
    for(std::string::iterator it = s1.begin(); it != s1.end(); ++it) {
        std::cout << *it ;
    }
    std::cout << std::endl;

    //at方式
    /*
     * at方式和[]方式的最大区别在于，at在访问出错的时候，可以跑出异常。[]会直接导致系统崩溃
     * 如果您希望通过try,catch捕获异常，建议使用at
     * */
    std::cout << "at方式：" << std::endl;
    for(int i = 0; i < s1.length(); i++) {
        std::cout << s1.at(i) ;
    }
    std::cout << std::endl;
}

//字符指针和string的转换
void main03() {
    std::string s1 = "aaabbb";
    //c_str返回一个以'\0'结尾的字符串的首地址
    printf("s1:%s\n", s1.c_str());  //s1 => char *

    //s1的内容copy到buf中
    //把当前串中以pos开始的n个字符拷贝到以s为起始位置的字符数组中，
    //返回实际拷贝的数目。注意要保证s所指向的空间足够大以容纳当前字符串，不然会越界。
    char buf1[128] = {0};
    s1.copy(buf1,3,0);  //只拷贝3个字符，不会加\0
    std::cout << buf1 <<std::endl;
}

//拼接
void main04()
{
    std::string s1 = "aa";
    std::string s2 = "bbb";
    std::string s3 = s1 + s2;
    std::string s4 = s1.append(s3);
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;
}

int main(){
//    main01();
//    main02();
//    main03();
    main04();
    std::cout << "hello world" << std::endl;
    return 0;
}