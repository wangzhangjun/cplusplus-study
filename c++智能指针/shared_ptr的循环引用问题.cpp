#include <iostream>
using namespace std;

/*
智能指针的循环引用导致内存泄露。（普通指针不会导致）
使用weak_ptr（弱引用）来解决。weak_ptr
*/
class Person;

class Car{
public:
    // shared_ptr<Person> m_person;
    weak_ptr<Person> m_person;
    Car() {
		cout << "Car()" << endl;
	}
	~Car() {
		cout << "~Car()" << endl;
	}
};

class Person{
public:
    shared_ptr<Car> m_car;
	Person() {
		cout << "Person()" << endl;
	}
	~Person() {
		cout << "~Person()" << endl;
	}
};

int main()
{
    shared_ptr<Person> p1(new Person()); //p1在栈上，会指向堆上的Person对象，所以Person对象的引用计数加1
    shared_ptr<Car> c1(new Car()); //c1在栈上，会指向堆上的Car对象，所以car对象的引用计数加1

    p1->m_car = c1;  //m_car是一个shared_ptr，指向c1，又会导致堆上的car对象引用计数加1
    c1->m_person = p1;  //m_person是一个shared_ptr，指向p1，又会导致堆上的person对象引用计数加1
    cout << p1.use_count() << endl;  //2
    cout << c1.use_count() << endl;  //2
    return 0;
    //所以当Main函数执行完毕后，对象的引用计数为1，没有调用析构函数，导致内存泄露
}
