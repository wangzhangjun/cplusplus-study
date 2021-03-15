#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
适配器模式，就是将已经写好的接口，但是这个接口不符合要求，适配器可以将这个接口转换成目标需要的函数
*/

//函数已经写好了
class myPrint{
public:
    void operator()(int v1, int v2){
        cout << v1 + v2 << endl;
    }
};

//定义目标接口，适配成什么样的
class Target{
    public :
        virtual void operator()(int v) = 0;
};

//适配器
class Adapter : public Target{
    public:
        Adapter(int par){
            param_ = par;
        }
        virtual void operator()(int v){
            print(v, param_);
        }
    public:
        myPrint print;
        int param_;
};

//MyBind2nd  进一步的绑定
Adapter MyBind2nd(int v)
{
    return Adapter(10);
}

void test()
{
    vector<int> v;
    for(int i=0; i < 10; i++) {
        v.push_back(i);
    }
    //for_each(v.begin(), v.end(), myPrint()); //不能用的，因为for_each的第三个参数要求是一个参数的函数对象，所以就需要一个适配器转换
    //for_each(v.begin(), v.end(), Adapter());
    for_each(v.begin(), v.end(), MyBind2nd(10));
}

int main()
{
    test();
    return 0;
}
