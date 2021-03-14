#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
代理模式：为其他对象提供一种代理，以控制对这个对象的访问。
在某些情况下，一个对象不适合或者不能直接引用另一个对象，而代理对象可以在客户端和目标对象之间起到中介的作用
*/

class AbstractCommonInterface{
public:
    virtual void run() = 0;
};

class MySystem : public AbstractCommonInterface
{
public:
    virtual void run()
    {
        cout << "系统启动。。。" << endl;
    }
};

//必须要有权限验证，提供用户名和密码
class mySystemProxy : public AbstractCommonInterface{
    public:
        mySystemProxy(string user, string password){
            this->user = user;
            this->password = password;
            pSystem = new MySystem;
        }
        bool checkUser()
        {
            if (user == "admin" && password == "admin")
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        virtual void run()
        {
            if(checkUser()){
                this->pSystem->run();
            }else{
                cout << "系统认证失败。。。" << endl;
            }
        }
        
        ~mySystemProxy(){
            if(pSystem != nullptr){
                delete pSystem;
            }
        }
    public:
        MySystem *pSystem;
        string user;
        string password;
};

void test()
{
    //通过代理类，控制对其他对象的使用
    mySystemProxy *proxy = new mySystemProxy("admin", "123");
    proxy->run();
}

int main()
{
    test();
    return 0;
}