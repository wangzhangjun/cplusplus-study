//
// Created by zhjwang on 2021/3/29.
//

#ifndef ORDERCOMPUTERROOM_MANAGER_H
#define ORDERCOMPUTERROOM_MANAGER_H
#include "Identity.h"
#include "Student.h"
#include "teacher.h"
#include "vector"

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

    //初始化容器
    void initVector();

    //学生容器
    std::vector<Student> vStu;
    //教师容器
    std::vector<teacher> vTeacher;

    //检测重复 参数:(传入id，传入类型)
    bool checkRepeat(int id, int type);

    std::string m_Name;
    std::string m_Pwd;
    int m_Id;


};


#endif //ORDERCOMPUTERROOM_MANAGER_H
