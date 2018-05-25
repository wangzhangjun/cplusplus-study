# c++友元类和友元对象

友元类的所有成员函数都是另一个类的友元函数,都可以访问另一个类中 的隐藏信息\(包括私有成员和保护成员\)。

当希望一个类可以存取另一个类的私有成员时,可以将该类声明为另一类 的友元类。定义友元类的语句格式如下:

```text
friend class 类名;
其中:friend 和 class 是关键字,类名必须是程序中的⼀一个已定义过的类。 例如,以下语句说明类 B 是类 A 的友元类:
class A {
... public:
        friend class B;
... };
```

经过以上说明后,类 B 的所有成员函数都是类 A 的友元函数,能存取类 A 的私有 成员和保护成员。

```text
class A {
    public:
        inline void Test()
        {
        }
    private:
        int x ,y; friend Class B;
}
class B {
    public:
        inline void Test()
        {
        }
}
```

