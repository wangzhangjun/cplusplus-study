#include <iostream>
#include <iomanip>

using namespace std;

void testPut(){
    cout.put('a').put('c').put('d');

}

int main() {
    //原本的输出
    cout.unsetf(ios::dec);
    cout.setf(ios::hex);
    cout << 1234 << endl; //16进制输出
    cout.unsetf(ios::hex); //关闭16进制输出。如果不关的话，下面一直输出16进制
    cout << 5678 << endl;  //输出10进制

    //iomainip
    {
        int n=1234; 
        cout<<"设置进制:"<<endl;
        cout<<"十进制 :"<<n<<endl; 
        cout<<"十六进制:"<<hex<<n<<endl;
        cout<<"八进制 :"<<oct<<n<<endl;
        cout<<"十进制 :"<<dec<<n<<endl;
    }
    testPut();
}