# c++友元基本语法
友元函数是可以直接访问类的私有成员的非成员函数。它是定义在类外 的普通函 数,它不属于任何类,但需要在类的定义中加以声明,声明时只需在友元 的名称前加上 关键字 friend,其格式如下:

```
 friend 类型 函数名(形式参数);
```
**一个函数可以是多个类的友元函数,只需要在各个类中分别声明。**

### 1.全局函数作为友元函数
```
#include<iostream>
#include<cmath>
using namespace std;
class Point {
    public:
        Point(double xx, double yy)
        {
          x = xx;
          y = yy;
        }
        void Getxy();
        friend double Distance(Point &a, Point &b);
    private:
      double x, y;
};
void Point::Getxy()
{
    cout << "(" << x << "," << y << ")" << endl;
}
double Distance(Point &a, Point &b) //是类point的友元函数，所以可以直接访问私有成员
{
    double dx = a.x - b.x;  //不需要get方法
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}
int main(void)
{
    Point p1(3.0, 4.0), p2(6.0, 8.0);
    p1.Getxy();
    p2.Getxy();
    double d = Distance(p1, p2);
    cout << "Distance is " << d << endl;
    return 0;
}
```

### 2.类成员函数作友元函数
```
#include<iostream>
#include<cmath>
using namespace std;

class Point;
//前向声明,是⼀一种不完全型声明,即只需提供类名(⽆无需提供类实现)即可。仅可⽤用 于声明指针和引 ⽤用。
class ManagerPoint
{
    public:
        double Distance(Point &a, Point &b);
};
class Point
{
public:
    Point(double xx, double yy)
    {
        x = xx;
        y = yy;
    }
    void Getxy();
    friend double ManagerPoint::Distance(Point &a, Point &b);
private:
    double x, y;
};
void Point::Getxy()
{
    cout << "(" << x << "," << y << ")" << endl;
}
int main(void)
{
    Point p1(3.0, 4.0), p2(6.0, 8.0);
    p1.Getxy();
    p2.Getxy();
    ManagerPoint mp;
    float d = mp.Distance(p1,p2);
    cout << "Distance is " << d<< endl;
    return 0;
}
```
