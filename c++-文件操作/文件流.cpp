#include <iostream> 
#include <fstream>
using namespace std;

void testReadFile()
{
    fstream ifs("src.txt", ios::in);
    if(!ifs) {
        cout << "open src.txt error" << endl;    
    }
    fstream ofs("dest.txt", ios::out | ios::trunc);
    if(!ofs) {
        cout << "open dest.txt error" << endl;
    }
    //一个一个字符读取
    // char ch;
    // while(ifs.get(ch), !ifs.eof()) {
    //     ofs.put(ch);
    // }

    //一个一个读效率低下，可以使用getline,尽量不要使用get()，因为会有遇到截止符卡住的情况
    char buf[1024];
    while(ifs.getline(buf, 1024, '\n'), !ifs.eof())
    {
        ofs<< buf << endl;
    }
    /*注意，在windows系统上，如果最后一行之后没有换行符的话，使用getline是读取不到的，可以使用c的方法*/
    FILE * fp = fopen("src.txt", "r");
    while(fgets(buf, 1024, fp) != NULL){
        printf("%s", buf);
    }

    ofs.close();
    ifs.close();
}

void read_write_binary()
{
    struct Student {
        char name[30];
        int age;
        char sex;
    };
    struct Student s[3] = {
        {"li",18,'f'},
        {"Fun",19,'m'},
        {"Wang",17,'f'}
    };

    fstream ofs("student.data", ios::in|ios::out|ios::trunc|ios::binary);
    if(!ofs){
        cout << "open student.data error" << endl;
    }
    for(int i = 0; i < 3; i++) {
        ofs.write((char *)(&s[i]), sizeof(s[i]));
    }
    
    ofs.seekg(0,ios::beg);//需要回退文件指针
//第一次读不出来，是因为上面写的时候，文件指针已经到了最后
    struct Student stu;
    while(ofs.read((char *)&stu, sizeof(stu)), !ofs.eof())
    {
        cout<<"Name "<< stu.name <<endl; 
        cout<<"Age "<<stu.age<<endl;
        cout<<"Sex "<<stu.sex<<endl;
        cout<<"---------------"<<endl;
    }

    ofs.close();
}


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

    testReadFile();
    cout << "==========binary===========" << endl;
    read_write_binary();

}