#include <iostream>
using namespace std;

/*
1. unique_ptr也会对对象产生强引用，它可以确保同一时间只有1个指针指向对象
2. 当unique_ptr销毁时（作用域结束时），其指向的对象也就自动销毁
3. 可以使用std::move函数转移unique_ptr的所有权
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

int main() {

    unique_ptr<Person> p0;
    {
        unique_ptr<Person> p1(new Person());
        p0 = std::move(p1);
    }

    unique_ptr<Person> p2(new Person());
    // unique_ptr<Person> p3(p2); 编译错误

	return 0;
}
