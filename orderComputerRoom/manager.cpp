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
void manager::addPerson() {}
void manager::cleanFile() {}
void manager::showComputer() {}
void manager::showPerson() {}

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

