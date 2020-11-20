//https://webcache.googleusercontent.com/search?q=cache:mSAXzF3AO7YJ:https://xie.infoq.cn/article/9fe3dbbce72bd675339dfcf0e+&cd=1&hl=en&ct=clnk&gl=hk&google_abuse=GOOGLE_ABUSE_EXEMPTION%3DID%3D0d1176f662776f90:TM%3D1605846017:C%3Dr:IP%3D124.108.22.102-:S%3DAPGng0sZrOx3eZmtG8_JqWVtQi3tAGAMjQ%3B+path%3D/%3B+domain%3Dgoogle.com%3B+expires%3DFri,+20-Nov-2020+07:20:17+GMT
#include <iostream>
#include <string>

using namespace std;

//编译不通过
struct TT {
    void func() {
        int x = 0;
        int y = 0;
        string s;
        s = x + "-" + to_string(y);
        s = x + to_string(y);
    }
};

int main()
{

    return 0;
}
