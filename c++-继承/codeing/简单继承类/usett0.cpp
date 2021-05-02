#include <iostream>
#include "tabtenn0.h"

using namespace std;

void show(TableTennisPlayer &rt)  //参数改为指针也是可以的
{
    rt.Name();
    // rt.Rating();  这个是错误的，因为参数是基类，所以只能调用基类的方法
}

void test()
{
    //派生类和基础类之间的两种特殊关系
    /*
    第一种关系：派生类可以使用基类的方法，条件是方法不是私有的。
    第二种关系：基类指针可以在不进行显示类型转换的情况下指向派生类对象，基类引用也可以指向派生类对象
    注意：在第二种关系下，基类指针或者引用只能调用基类的方法。
    注意2：不可以反着来，也就是把派生类的指针或者引用指向基类对象，因为一般来说派生类的内存空间大于基类
    */

    //这样其实会出现一些有趣的用法：
    /*
    第一种：基类引用或者指针做函数参数
    */
   TableTennisPlayer tp1("zhjwang", "laowang", false);
   RatedPlayer rp1(1140, "Tom", "Tom1", false);
   show(tp1);
   show(rp1);
   /*
   第二种：用子类对象初始化父类对象
   原理：
        要初始化tp2，需要调用复制构造函数：TableTennisPlayer(const RatedPlayer &)
        但是没有这样的构造函数，但是存在隐式的复制构造函数：
        TableTennisPlayer（const TableTennisPlayer &）
        符合父类引用或者指针指向子类对象。它会复制firstname, lastname, hasTable等成员。
        其实也就是把tp2初始化我嵌套在rp2中的TableTennisPlayer对象
   */
   RatedPlayer rp2(1140, "Tom2", "Tom3", false);
   TableTennisPlayer tp2(rp2);
   tp2.Name();

   /*
   第三种：将子类对象赋值给父类对象,
        这种情况下，程序将使用隐式的重载赋值运算符
    TableTennisPlayer & operator=(const TableTennisPlayer &) const;
   */
   RatedPlayer rp3(1140, "Tom3", "Tom4", false);
   TableTennisPlayer tp3("none", "none", false);
   tp3 = rp3;
   tp3.Name();
}
int main()
{
    test();
    std::cout << "=====================" << std::endl;
    TableTennisPlayer p1("Chuck", "Blizzard", true);
    TableTennisPlayer p2("Tara", "Boomdea", false);

    //派生类的第一种构造
    RatedPlayer rplayer1(1140, "Tom", "Tom1", false); 
    //从这里的Name方法就可以看出，派生类其实把父类的所有的成员（成员函数和成员变量）都继承过来了，
    //只是在派生类中要想使用父类的Private成员，就得通过父类的public成员函数
    rplayer1.Name();  //设置的是RatedPlayer这个子类的名字，但是使用的是父类的代码片段。

    //派生类的第二种构造
    RatedPlayer rplayer2(1212, p1);
    rplayer2.Name();
    std::cout  << "=====================" << std::endl;

    p1.Name();
    if(p1.HasTable()) {
        cout << "p1 has a table";
    }else
        cout << "p1 no table" << endl;
    p2.Name();
    if (p2.HasTable())
    {
        cout << "p2 has a table" ;
    }
    else
        cout << "p2 no table" << endl;
    return 0;
}