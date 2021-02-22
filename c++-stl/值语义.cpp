#include <iostream>
#include <vector>
/*
容器是值语义的：
一定要提供相关的拷贝构造函数，和重载=
这样你自己的对象才能被放到容器中。
*/

class Teacher {
public:
    char *name;
    int age;
public:
    //有参构造函数
    Teacher(const char *pname , int age) {
        this->name = new char[strlen(pname)];
        strcpy(this->name, pname);
        this->age = age;
    }
    //拷贝构造函数
    Teacher (const Teacher &obj) {
        this->name = new char[strlen(obj.name)];
        strcpy(this->name, obj.name);
        this->age  = obj.age;
    }
    //重载=操作符
    //t3 = t2 = t1 :支持连等，所以要返回引用
    Teacher &operator=(const Teacher &obj)
    {
        //释放旧的内存，因为t2 = "aaa"已经有内存了，这时候改成t2 = "bbbb",不释放原来的就内存泄漏了。
        if(this->name != NULL) {
            delete[] this->name;
            this->name = NULL;
        }
        //根据t1分配内存
        this->name = new char[strlen(obj.name)] + 1;

        //copy数据
        strcpy(this->name, obj.name);
        this->age = obj.age;
        return *this;  //返回引用
    }

    ~Teacher(){
        if(name != NULL) {
            delete[] name;
            this->name = NULL;
            this->age = 0;
        }
    }


};
void test()
{
    std::vector<Teacher> v1;
    Teacher t1("t1", 10);
    v1.push_back(t1);  //容器都是值语义的拷贝，所以要有拷贝构造函数、以及重载=操作符
    std::cout << v1[0].name << std::endl;
    std::cout << v1[0].age << std::endl;
}

int main()
{
    test();
    std::cout << "hello world" << std::endl;
}