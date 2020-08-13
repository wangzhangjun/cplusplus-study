#include <iostream>
using namespace std;

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
		cout << "run() -> " << m_age << endl;
	}
};

template <typename T>
class SmartPointer {
private:
	T *m_obj;
public:
	SmartPointer(T *obj) :m_obj(obj) {}
	~SmartPointer() {
		if (m_obj == nullptr){
			return;
		}
		delete m_obj;
	}

	T *operator->() {
		return m_obj;
	}
};

int main() {

	SmartPointer<Person> p(new Person(20));
	p->run();  //需要重载->操作符

	//2之前销毁
	cout << 1 << endl;
	{
		SmartPointer<Person> p(new Person(20));
	}
	cout << 2 << endl;
	return 0;
}
