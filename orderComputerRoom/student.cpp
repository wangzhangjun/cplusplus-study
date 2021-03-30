//
// Created by zhjwang on 2021/3/29.
//

#include <fstream>
#include "Student.h"
#include "iostream"
#include "globalFile.h"

using namespace std;

Student::Student() {

}

Student::Student(int id, std::string name, std::string pwd) {
    this->m_id  = id;
    this->m_Name = name;
    this->m_pwd = pwd;

    //获取机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    computerRoom c;
    while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
    {
        vCom.push_back(c);
    }

    ifs.close();
}

void Student::operMenu() {
    cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          1.申请预约              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          2.查看我的预约          |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          3.查看所有预约          |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          4.取消预约              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          0.注销登录              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

void Student::applyOrder() {}

void Student::showMyorder() {}

void Student::showAllOrder() {}

void Student::cancelOrder() {}