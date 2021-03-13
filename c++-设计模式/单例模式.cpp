#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
实现单例：
1.构造函数私有化
2.静态的私有类指针变量
3.static的对外接口，可以让用户获得单例对象
*/

//单例模式，一般不用释放内存吧，因为系统就new了一份，可以等到程序结束，让OS释放
//如果要释放，就采用下面Garbo的方式

//懒汉式
class Singleton_lazy{
    private:
        Singleton_lazy(){}
    public:
        static Singleton_lazy* getInstance(){
            if (pSingleton == nullptr)
            {
                pSingleton = new Singleton_lazy;
            }
            return pSingleton;
        }
        #if 0
        static void freeSpace(){
            if(pSingleton != NULL){
                free(pSingleton);
            }
        }
        #endif
        class Garbo{
            ~Garbo(){
                cout << "~Garbo()" << endl;
                if (pSingleton != NULL)
                {
                    free(pSingleton);
                }
            }
        };
    private:
        static Singleton_lazy *pSingleton;
        static Garbo garbo;
};
//static 的要类外初始化
Singleton_lazy *Singleton_lazy::pSingleton = NULL;

//饿汉式
class Singleton_hungry
{
private:
    Singleton_hungry() {cout << "饿汉式" << endl;}
public:
    static Singleton_hungry *getInstance()
    {
        return pSingleton;
    }
private:
    static Singleton_hungry *pSingleton;
};
Singleton_hungry *Singleton_hungry::pSingleton = new Singleton_hungry;  //在main函数执行之前就创建好了

void test()
{
    Singleton_lazy *test = Singleton_lazy::getInstance();
    Singleton_lazy *test1 = Singleton_lazy::getInstance();
    if(test1 == test){
        cout << "指针指向同一个内存空间" << endl;
    }
    Singleton_hungry *p1 = Singleton_hungry::getInstance();
    Singleton_hungry *p2 = Singleton_hungry::getInstance();
    if (p1 == p2)
    {
        cout << "指针指向同一个内存空间" << endl;
    }
}

int main()
{
    test();
    return 0;
}