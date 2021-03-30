//
// Created by zhjwang on 2021/3/29.
//

#include "manager.h"
#include <iostream>

using namespace  std;

manager::manager() {}
manager::manager(std::string name, std::string pwd) {
    this->m_Name = name;
    this->m_Pwd = pwd;
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
