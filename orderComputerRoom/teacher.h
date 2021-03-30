//
// Created by zhjwang on 2021/3/29.
//

#ifndef ORDERCOMPUTERROOM_TEACHER_H
#define ORDERCOMPUTERROOM_TEACHER_H
#include "Identity.h"

class teacher : public Identity {
public:
    teacher();
    teacher(int empId, std::string name , std::string pwd);
    virtual void operMenu (); //菜单界面
    void showAllOrder();  //查看所有预约
    void validOrder();  //审核预约
    int m_emid;  //教师编号
    std::string m_emname;
    std::string m_empwd;
};


#endif //ORDERCOMPUTERROOM_TEACHER_H
