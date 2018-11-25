# c++多态案例程序员工资

```
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//³éÏóÀà
class Programmer
{
public:
	virtual void printMoney() = 0;
};

class  Junior_programmer : public Programmer
{
public:
	Junior_programmer(double salary) {
		this->salary = salary;
	}
	virtual void printMoney()  {
		cout << "³õ¼¶³ÉÔ±µÄ¹¤×ÊÊÇ " << salary << endl;
	}

private:
	double salary; //¹¤×Ê
};

class Mid_programmer :public Programmer
{
public:
	Mid_programmer(double salary)
	{
		this->salary = salary;
	}
	virtual void printMoney() {
		cout << "ÖÐ¼¶³ÉÔ±µÄ¹¤×ÊÊÇ " << salary << endl;
	}
private:
	double salary;
};

class Adv_programmer : public Programmer
{
public:
	Adv_programmer(double salary)
	{
		this->salary = salary;
	}
	virtual void printMoney() {
		cout << "¸ß¼¶¼¶³ÉÔ±µÄ¹¤×ÊÊÇ " << salary << endl;
	}
private:
	double salary;
};

//Õë¶Ô³éÏóÀà·â×°µÄÒ»¸ö¼Ü¹¹º¯Êý
void printSalary(Programmer *p)
{
	p->printMoney();
}

int main(void)
{
	Programmer *p = new Junior_programmer(8000);

	printSalary(p);
	delete p;

	p = new Mid_programmer(18000);
	printSalary(p);
	delete p;


	p = new Adv_programmer(20000);
	printSalary(p);
	delete p;

	return 0;
}
```
