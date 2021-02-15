#include <iostream>
#include <vector>

using namespace std;
/*
从命令行获取如下：

2  8
123456
12

*/
void main01()
{
    int colomns;
    int len;
    string str = "";
    std::vector<std::string> svec;

    cout << "请输入colomns:" << endl;
    cin >> colomns;
    cin.ignore();
    cout << "请输入len:" << endl;
    cin >> len;
    cin.ignore();
    cout << "请输入str:" << endl;
    // for (int i = 0; i < colomns; i++)
    // {
    //     cin >> str; //读取字符串，不含空格
    //     svec.push_back(str);
    //     str = "";
    // }
    for (int i = 0; i < colomns; i++)
    {
        getline(cin, str); //读取一行字符,可以包含空格
        svec.push_back(str);
        str = "";
    }
    //遍历
    for (int i = 0; i < svec.size(); i++)
    {
        std::cout << svec[i] << std::endl;
        for (int j = 0; j < svec[i].length(); j++)
        {
            std::cout << svec[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    main01();
    return 0;
}