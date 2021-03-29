//
// Created by zhjwang on 2021/3/26.
//

#ifndef ORDERCOMPUTERROOM_IDENTITY_H
#define ORDERCOMPUTERROOM_IDENTITY_H
#include "string"

//身份抽象类
//每一种身份都有其特性，抽出公共的部分
class Identity {
public:
    std::string m_name;  //用户名
    std::string m_pwd;   //密码
    //操作菜单
    virtual void operMenu() = 0;
};

#endif //ORDERCOMPUTERROOM_IDENTITY_H
