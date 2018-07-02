# c++多态案例图形

```
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Shape
{
public:
    virtual void show() = 0;

    virtual void showArea() = 0;

    virtual ~Shape() {

    }
};


class Circle :public Shape
{
public:
    Circle(double r) {
        this->r = r;
    }
    ~Circle() {
        cout << "~Circle()" << endl;
    }
    virtual void show()
    {
        cout << "圆圈半径" << r << endl;
    }

    virtual void showArea() {
        cout << "面积" << 3.14*r*r << endl;
    }

private:
    double r;
};


class Square :public Shape
{
public:
    Square(double a){
        this->a = a;
    }
    ~Square() {
        cout << "~Square()" << endl;
    }
    virtual void show()  {
        cout << "正方形" << a << endl;
    }

    virtual void showArea() {
        cout << "正方形面积" << a * a << endl;
    }
private:
    double a;
};


int main(void)
{
    Shape *array[2];

    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            double r;
            cout << "create circle" << endl;
            cin >> r;
            array[i] = new Circle(r);
        }
        else if (i == 1)
        {
            double a;
            cout << "create square" << endl;
            cin >> a;
            array[i] = new Square(a);
        }
    }

    for (int i = 0; i < 2; i++) {
        array[i]->show();
        array[i]->showArea();

        delete array[i];
    }

    return 0;
}
```
