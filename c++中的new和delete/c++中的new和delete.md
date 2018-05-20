# c++中的new和delete
###1.new是在堆上分配内存，用delete来释放,一共有三种应用场景

### 2.分配基础类型和分配数组类型
```
#include "iostream"
using namespace std;
//1. new delete 操作符号
//malloc  free
//2.new是在堆上分配内存  delete释放内存
//三种用法：分配基础类型，分配数组类型，分配对象
void main()
{
    //new基础类型
    int *p = (int *)malloc(sizeof(int));
    free(p);
    //c++ 第一种
    int *p2 = new int;//相当于上面的
    *p2 = 10;
    delete p2;
    //分配内存的同时，初始化
    int *p3 = new int(100);
    delete p3;


    //非配数组类型
    //c语言
    int *p5 = (int *)malloc(10 * sizeof(int));
    p5[0] = 1;
    free(p5);
    //c++
    int *p4 = new int[10]; //int a[10]
    p4[0] = 1;
    p4[1] = 2;
    delete [] p4;
    system("pause");
}  

```
>* 注：基础类型中：new,delete和malloc.free可以混搭。
>*  在数组类型中，也是可以混搭，注意delete释放数组的语法格式。
>*  当设计的类的时候不能混搭，delete和new会分别取调用析构函数和构造函数，malloc和free不会去调用；

### 3.对象new
```
#include "iostream"
using namespace std;
//1. new delete 操作符号
//malloc  free
//2.new是在堆上分配内存  delete释放内存
//三种用法：分配基础类型，分配数组类型，分配对象
class Test
{
public:
    Test(int mya, int myb)
    {
        a = mya;
        b = myb;
    }
    ~Test()
    {
        cout <<"我被调用了"<<endl;
    }
    int  getA()
    {
    return a;
    }
private:
    int a;
    int b;
};
void main()
{
    Test t1(1,2);//在临时区分配内存
    //new + 类型  返回一个内存的首地址
    //new 操作符会自动的调用这个类的构造函数
    //delete自动调用这个类的析构函数
    //相当于程序员可以手工控制类的对象的生命周期
    Test *p = new Test(1,2);
    cout << p->getA()<<endl;
    delete p;
    system("pause");
}  
```
