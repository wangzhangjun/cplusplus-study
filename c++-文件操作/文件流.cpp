#include <iostream> 
#include <fstream>
using namespace std;

int main()
{
    ifstream ifs("aa.c"); //默认ios::in  不会自动创建
    if(!ifs)
        cout << "open error" << endl;
    ofstream ofs("bb.c"); //ios::out|ios::trunc   会自动创建
    if(!ofs)
        cout << "open error" << endl;
    fstream fs("cc.c");
    if(!fs)
        cout << "open error" << endl;
    ifs.close();
    fs.close();
    ofs.close();
}