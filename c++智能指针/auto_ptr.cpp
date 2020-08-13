#include <iostream>
using namespace std;

/*
分为3类：
1. auto_ptr已经过时了，现在不推荐使用
*/

class Person {
	int m_age;
public:
	Person() {
		cout << "Person()" << endl;
	}
	Person(int age) : m_age(age) {
		cout << "Person(int)" << endl;
	}
	~Person() {
		cout << "~Person()" << endl;
	}
	void run() {
		cout << "run() - " << m_age << endl;
	}
};

void test()
{
	//以前的写法
	Person *p = new Person(20);
	p->run();

	//可以理解为：智能指针p指向了堆空间的Person对象,会发现自动调用
	//p1是在栈空间上，test执行完毕后，自动销毁. 对象的生命周期是跟随p1的。p1销毁，对象也会销毁
	auto_ptr<Person> p1(new Person(20));
	p1->run();

	//为什么不适用这种方式呢。这种也是在test执行完毕后，会自动销毁
	//上面的适用在堆空间上的
	Person p2(20);
	p2.run();

	//在输出2之前就会销毁
	cout << 1 << endl;
	{
		auto_ptr<Person> p3(new Person(20));
		p3->run();
	}
	cout << 2 << endl;

	//智能指针不要去指向栈空间的对象（没意义），智能指针就是指向堆空间的
	//下面这个例子会出现double free，就会出错
	//栈上的释放一次，智能指针也会释放一次
	//程序会挂掉
	// cout << 1 << endl;
	// {
	// 	Person p4(20);
	// 	auto_ptr<Person> p5(&p4);
	// 	p5->run();
	// }
	// cout << 2 << endl;

	//auto_ptr的缺陷
	//不支持数组，下面的代码会挂掉。
	// {
	// 	auto_ptr<Person> p6(new Person[10]);
	// 	p->run();
	// }
}

int main()
{
	 cout << "hello world" << endl;
	 test();
	 return 0;
}
