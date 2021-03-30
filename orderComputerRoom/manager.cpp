//
// Created by zhjwang on 2021/3/29.
//

#include "manager.h"
#include "globalFile.h"
#include <iostream>
#include <fstream>

using namespace  std;

manager::manager() {}
manager::manager(std::string name, std::string pwd) {
    this->m_Name = name;
    this->m_Pwd = pwd;
    this->initVector();
}
void manager::operMenu() {
    cout << "欢迎管理员："<<this->m_Name << "登录！" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.添加账号            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.查看账号            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          3.查看机房            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          4.清空预约            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.注销登录            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "请选择您的操作： " << endl;
}
void manager::addPerson()
{
    cout << "请输入添加账号的类型" << endl;
    cout << "1、添加学生" << endl;
    cout << "2、添加老师" << endl;

    string errorTip; //重复错误提示
    string fileName;
    string tip;
    ofstream ofs;

    int select = 0;
    cin >> select;
    if (select == 1){
        fileName = STUDENT_FILE;
        tip = "请输入学号： ";
        errorTip = "学号重复，请重新输入";
    }
    else{
        fileName = TEACHER_FILE;
        tip = "请输入职工编号：";
        errorTip = "职工号重复，请重新输入";
    }

    ofs.open(fileName, ios::out | ios::app);
    int id;
    string name;
    string pwd;
    cout <<tip << endl;

    while (true) {
        cin >> id;
        bool ret = this->checkRepeat(id, 1);
        if (ret) //有重复
        {
            cout << errorTip << endl;
        }
        else
        {
            break;
        }
    }

    cout << "请输入姓名： " << endl;
    cin >> name;

    cout << "请输入密码： " << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功" << endl;

    system("clear");
    ofs.close();

    this->initVector(); //刚添加的用户也要加到容器中
}

void manager::cleanFile()
{
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();

    cout << "清空成功！" << endl;
    system("clear");
}

void manager::showComputer()
{
    cout << "机房信息如下： " << endl;
    for(auto it  = vCom.begin(); it != vCom.end(); ++it) {
        cout << "机房编号： " << it->m_ComId << " 机房最大容量： " << it->m_MaxNum << endl;
    }
    system("clear");
}

void printStudent(Student &s)
{
    cout << "学号： " << s.m_id << " 姓名： " << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
void printTeacher(teacher &t)
{
    cout << "职工号： " << t.m_emid << " 姓名： " << t.m_emname << " 密码：" << t.m_empwd << endl;
}

void manager::showPerson()
{
    cout << "请选择查看内容：" << endl;
    cout << "1、查看所有学生" << endl;
    cout << "2、查看所有老师" << endl;

    int select = 0;
    cin >> select;
    if(select  == 1) {
        for_each(vStu.begin(), vStu.end(),printStudent);
    }else {
        for_each(vTeacher.begin(), vTeacher.end(),printTeacher);
    }
}
void manager::initVector() {
    //读取学生文件中
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if(!ifs.is_open()) {
        cout << "文件读取失败！" << endl;
        return;
    }
    vStu.clear();
    vTeacher.clear();

    Student s;
    while (ifs >> s.m_id && ifs >> s.m_Name &&  ifs >> s.m_Pwd){
        vStu.push_back(s);
    }
    cout << "当前学生数量为： " << vStu.size() << endl;
    ifs.close();

    //读取老师
    ifs.open(TEACHER_FILE, ios::in);
    teacher t;
    while(ifs >> t.m_emid && ifs >> t.m_emname && ifs >> t.m_empwd){
        vTeacher.push_back(t);
    }
    cout << "当前教师数量为： " << vTeacher.size() << endl;
    ifs.close();

    //读取机房信息
    computerRoom com;
    ifs.open(COMPUTER_FILE, ios::in);
    while (ifs >> com.m_ComId && ifs >> com.m_MaxNum){
        vCom.push_back(com);
    }
    cout << "当前机房数量为： " << vCom.size() << endl;
    ifs.close();
}

bool manager::checkRepeat(int id, int type) {
    if(type == 1){
        for(auto it = vStu.begin(); it != vStu.end(); ++it) {
            if(id == it->m_id) {
                return true;
            }
        }
    }else if(type == 2) {
        for(auto it = vTeacher.begin(); it != vTeacher.end(); ++it) {
            if(id == it->m_emid) {
                return true;
            }
        }
    }
    return false;
}

