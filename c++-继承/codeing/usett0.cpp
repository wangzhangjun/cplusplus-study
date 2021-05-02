#include <iostream>
#include "tabtenn0.h"

using namespace std;


int main()
{
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