#include <iostream> 
using namespace std;

void testGet(){
    char ch;
    while((ch=cin.get()) != EOF) {  //EOF为文件结束符，在mac上按ctrl+d
        cout.put(ch);
    }
}

void testGetYinYong(){
    char ch;
    while(cin.get(ch)) { //get返回的是引用，istream &实现链式编程
        cout.put(ch);
    }
}

//遇到截止符，不会吸收，也不会跳过，最多读n-1个字符
void testGetThressArg()
{
    char str[80] = {};
    cin.get(str,80,'a'); 
    cout << str << endl;
    cin.ignore();
    cin.get(str,80,'a'); 
    cout << str << endl;
}

/*
输入：
fffffaffffa
输出：
fffff
ffff
*/
void testGetline()//最多读n-1个字符，遇到终止符，不吸收，但是会跳过
{
    char buf[1024];
    cin.getline(buf,1024,'a');
    cout << buf << endl;
    cin.getline(buf,1024,'a');
    cout << buf << endl;
}

void testPeekPutbackIgnore()
{
    char ch[20];
    cin.get(ch,20,'/'); // i like c/ i like c++ also/ 
    cout<<"the first part is :"<<ch<<endl; 
    cin.ignore(10, 'i');//因为你可能会输入：i like c/          i like c++ also/ 
    cin.putback('i');//发现把i也ignore了。所以需要回退
    char peek = cin.peek(); 
    cout<<"peek is :"<<peek<<endl;
    cin.get(ch,20,'/');
    cout<<"this second part is:"<<ch<<endl;
}

int main01() {
    int a;
    double b;
    char buf[1024]; //string buf;
    cin>>a>>b>>buf; //读入字符串时遇到空格则止 12 23.5 aa bb cc dd 
    cout<<a<<endl;
    cout<<b<<endl; 
    cout<<buf<<endl; 
    //后面的bb cc dd都丢失了
    return 0;
}

int main()
{
    testPeekPutbackIgnore();
}