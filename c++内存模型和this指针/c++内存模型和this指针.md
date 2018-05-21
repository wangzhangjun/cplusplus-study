# c++内存模型和this指针
### 1.C++类对象中的成员变量和成员函数是分开存储的
> * 成员变量:存储于对象中，与struct变量有相同的内存布局和字节对齐方式
>* 静态成员变量：存储于全局数据区中
> * 成员函数：存储于代码段中。

**那么问题来了**：很多对象公用一块代码？代码是如何区分具体对象的那？

**那么解决问题吧**：
* 1、C++类对象中的成员变量和成员函数是分开存储的。C语言中的内存四区模型仍然有效！
* 2、C++中类的普通成员函数都隐式包含一个指向当前对象的this指针。
* 3、静态成员函数、静态成员变量属于类
* 4、静态成员函数与普通成员函数的区别
  * 静态成员函数不包含指向具体对象的指针
  * 普通成员函数包含一个指向具体对象的指针

```
#include "iostream"
using namespace std;

class Test
{
public:
	Test(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	void getA() //getA(this);
	{
		printf("a:%d \n", this->a);
		printf("a:%d \n", a);
	}

protected:
private:
	int a;
	int b;
};
void main()
{
	Test t(1,2); //====>Test(this, 1, 2);===>Test(&t, 1, 2);
	system("pause");
}
```

### 2.this指针理解
```
#include "iostream"
using namespace std;
class Test
{
public:
    Test(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
    //如果想对一个对象连续调用成员方方法，每次都会改变对象本身，成员方法需要返回引用。
    Test & add(Test &t2)
    {
        this->a = this->a + t2.getA();
        this->b = this->b + t2.getB();
        return *this;//如果想返回一个对象的本身用*this返回，这样你就可以给这个返回的匿名对象继续.add(xx,xx)。
        如果返回的不是引用类型，这里还是返回*this，那么返回的是一个匿名对象本身
    }
    Test add2(Test &t2)
    {
        Test t3(this->a + t2.getA(), this->b + t2.getB());
        return t3;//返回Test对象(匿名对象)
        //匿名对象的去和留，关键看返回的时候怎么去接（和拷贝构造函数的第四种应用场景是一样的）
    }
    void printAB()
    {
        cout<<"a:"<<a<<"b:"<<b<<endl;
    }
private:
    int a;
    int b;
};
//全局函数
//如果把全局函数转成成员函数，少了一个操作数，通过this指针，被隐藏。
Test add(Test &t1, Test &t2)
{
    Test t3(t1.getA()+t2.getA(), t1.getB() + t2.getB()) ;//构造一个Test对象，并返回。
    return t3;//返回的是t3对象，赋值给匿名对象。
}
//把成员函数转成全局函数，需要多一个参数。。。。
void printAB(Test *pthis)
{
    cout<<"a:"<<pthis->getA()<<"b:"<<pthis->getB()<<endl;
}
void main()
{
    Test t1(1,2);//Test(&t1, 1, 2);
    Test t2(3,4);
    t1.add(t2);//---->add(&t1, t2);这个返回的就是t1本身，因为上面返回的是*this
    t1.printAB();
    system("pause");
}  
```
### 3.
