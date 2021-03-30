//
// Created by zhjwang on 2021/3/29.
//

#ifndef ORDERCOMPUTERROOM_MANAGER_H
#define ORDERCOMPUTERROOM_MANAGER_H
#include "Identity.h"

class manager : public Identity{
public:
    manager();
    manager(std::string name, std::string pwd);

    //选择菜单
    virtual void operMenu();

    //添加账号
    void addPerson();

    //查看账号
    void showPerson();

    //查看机房信息
    void showComputer();

    //清空预约记录
    void cleanFile();

    std::string m_Name;
    std::string m_Pwd;


};


#endif //ORDERCOMPUTERROOM_MANAGER_H
