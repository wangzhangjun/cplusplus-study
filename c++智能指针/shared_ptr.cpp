#include <iostream>
using namespace std;

/*
	1.多个shared_ptr可以指向同一个对象
	2.shared_ptr会对一个对象产生强引用
	3.强引用计数，会记录着这个对象被引用了多少次，每当一个shared_ptr指向，强引用计数就会加1，当shared_ptr销毁的时候，强引用计数就会减1
	4.当强引用计数为0的时候，对象销毁
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

//常见错误,以下会double free
void test(){
	// {
	// 	Person *p = new Person(2);
	// 	{
	// 		shared_ptr<Person> p1(p);
	// 	}
	// 	{
	// 		shared_ptr<Person> p2(p);
	// 	}
	// }
}

int main() {
	//4个智能指针对指向了同一个Person对象
	//这样当最后一个智能指针销毁的时候，才会释放这个对象（调用person的析构函数）
	shared_ptr<Person> p1(new Person(10));
	cout << p1.use_count() << endl;  //被引用了多少次
	shared_ptr<Person> p2 = p1;
	shared_ptr<Person> p3 = p2;
	cout << p1.use_count() << endl;
	shared_ptr<Person> p4(p3);

	test();


	return 0;
}
