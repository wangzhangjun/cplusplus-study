#include <iostream>
#include <fstream>
#include <string>
#include "Identity.h"
#include "globalFile.h"
#include "Student.h"
#include "teacher.h"
#include "manager.h"
using namespace  std;

void managerMenu(Identity * &man)
{
    while (true) {
        //管理员菜单
        man->operMenu();

        manager * m = (manager *) man;
        int select = 0;
        cin >> select;

        if(select == 1) {
            cout << "添加账号" << endl;
            m->addPerson();
        }else if(select == 2) {
            cout << "查看账号" << endl;
            m->showPerson();
        }else if(select == 3) {//查看机房
            cout << "查看机房" << endl;
            m->showComputer();
        }else if (select == 4) {//清空预约
            cout << "清空预约" << endl;
            m->cleanFile();
        }else{
            delete man;
            cout << "注销成功" << endl;
            system("clear");
            return;
        }
    }
}

//登录功能
void LoginIn(std::string fileName, int type)
{
    Identity *person = NULL;
    ifstream  ifs;
    ifs.open(fileName, ios::in);
    if(!ifs.is_open()) {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }
    int id = 0;
    std::string name;
    std::string pwd;

    if(type == 1) {
        cout << "请输入学号：" <<endl;
        cin >> id;
    }else if(type == 2){
        cout << "请输入教师职工号：" <<endl;
        cin >> id;
    }
    cout << "请输入用户名：" << endl;
    cin >> name;
    cout << "请输入密码：" << endl;
    cin >> pwd;

    if (type == 1)
    {
        //学生登录验证
        int fId;
        std::string fName;
        std::string fPwd;
        while(ifs >> fId && ifs >> fName && ifs>>fPwd){
            if(id == fId && name == fName && pwd == fPwd) {
                cout << "学生验证登录成功！" << endl;
                system("clear");

                person = new Student(1, "name", "123");

                //进入学生身份的子菜单
                return;
            }
        }
    }
    else if (type == 2)
    {
        //教师登录验证
        int fId;
        std::string fName;
        std::string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if (id == fId && name == fName && pwd == fPwd)
            {
                cout << "教师验证登录成功!" << endl;
                system("clear");
                person = new teacher(id, name, pwd);

                //跳转到老师身份子菜单
                return;
            }
        }
    }
    else if(type == 3)
    {
        //管理员登录验证
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd)
        {
            if (name == fName && pwd == fPwd)
            {
                cout << "验证登录成功!" << endl;
                //登录成功后，按任意键进入管理员界面
                system("clear");
                //创建管理员对象
                person = new manager(name,pwd);
                managerMenu(person);
                return;
            }
        }
    }

    cout << "验证登录失败!" << endl;
    system("clear");
    return;
}

int main() {
    int select  = 0;
    while(true) {
        cout << "======================  欢迎来到传智播客机房预约系统  ====================="
             << endl;
        cout << endl << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.学生代表           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.老    师           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.管 理 员           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.退    出           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: ";

        cin >> select;
        switch (select) {
            case 1:  //学生
                LoginIn(STUDENT_FILE, 1);
                break;
            case 2:  //老师
                LoginIn(TEACHER_FILE, 2);
                break;
            case 3:   //管理员
                LoginIn(ADMIN_FILE, 3);
                break;
            case 0:  //退出系统
                cout << "欢迎下次使用！" << endl;
                return 0;
            default:
                cout << "输入有误，请重新选择：" << endl;
                system("clear");
                break;
        }
    }
    return 0;
}
