# c++易犯错误模型

## 1.求圆的面积

```text
#include "iostream"

using namespace std;

void main01()
{
    int i;
    //printf("hello c++ \n");
    //cout相当于屏幕的终端
    //<<   c里面是左移动
    //<< 说明c++对这个操作符作了功能的增强（操作符重载）
    cout<<"hello cplusepluse\n";
    cout<<"清输入一个数:\n";
    //cin相当于键盘
    cin>>i;
    //endl相当于\n
    cout<<i<<endl;
    system("pause");
}
//面向过程
void main02()
{
    double r;
    double s;
    cout<<"请输入半径：";
    cin>>r;
    s = 3.14*r*r;
    cout<<"圆的面地："<<s;
    system("pause");
}
//面向对象
class circle
{
private:
    double m_r;//属性，成员变量
public:
    void setR(double r)
    {
        m_r  = r;
    }
    double setR()
    {
        return m_r;
    }
    double  getR()
    {
        return m_r;
    }
    double getS()
    {
        return 3.14 * m_r * m_r;
    }
};
void main()
{
    circle c1;
    c1.setR(10);
    cout<<"面地势 :"<<c1.getS();
    system("pause");
}
```

## 2.易犯错误模型

```text
#include<iostream>
using namespace std;//c++的命名空间
class circle
{
public:

    double r;

    double pi = 3.1415926;
    double area = pi*r*r;

    double getS()
    {
        return area = 3.14*r*r;
    }

};
int main()
{
    circle pi;//当你来了一个新的对象的时候，在栈中就会为r分配一个临时的值，所以会产生不可预测的结果
    cout << "请输入area" << endl;
    //cin >> pi.r;

    cout << pi.area << endl;    //乱码

    pi.r = 100; //
    pi.getS();//方法只有在被调用的时候才会被zhixing

    cout << pi.area << endl;
    system("pause");
    return 0;
}
```

