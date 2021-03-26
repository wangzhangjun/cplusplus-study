#include <iostream>
using namespace  std;
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
                break;
            case 2:  //老师
                break;
            case 3:   //管理员
                break;
            case 0:  //退出系统
                break;
            default:
                cout << "输入有误，请重新选择：" << endl;
                system("clear");
                break;
        }
    }


    return 0;
}
