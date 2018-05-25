# c++中的静态成员占的内存大小

```text
#include <iostream>
using namespace std;
class C1 {    //12
    public:
        int i;  //4
        int j; //4
        int k;  //4
}; //12

class C2 {  //12
    public:
        int i;
        int j;
        int k;
        static int m;                   //不在这个类的内存空间
    public:
        int getK() const { return k; }  //也不占内存空间
        void setK(int val) { k = val; }
};

struct S1 {
    int i;
    int j;
    int k;
}; //12

struct S2
{
    int i;
    int j;
    int k;
    static int m;
}; //12

int main() {
    cout <<"c1 : " << sizeof(C1) <<endl;
    cout <<"c1 : " << sizeof(C2) <<endl;
    cout <<"c1 : " << sizeof(S1) <<endl;
    cout <<"c1 : " << sizeof(S2) <<endl;
    return 0;
}
```

