//
// Created by zhjwang on 2021/3/29.
//

#ifndef ORDERCOMPUTERROOM_STUDENT_H
#define ORDERCOMPUTERROOM_STUDENT_H

#include "Identity.h"
#include <string>

class Student : public Identity{
public:
    Student();
    Student(int id, std::string name, std::string pwd);
public:
    //菜单界面
    virtual void operMenu();
    //申请预约
    void applyOrder();
    //查看我的预约
    void showMyorder();
    //查看所有预约
    void showAllOrder();
    //取消预约
    void cancelOrder();
    //学生学号
    int m_id;
};


#endif //ORDERCOMPUTERROOM_STUDENT_H
