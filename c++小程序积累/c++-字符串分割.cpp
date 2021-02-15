#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

//g++ --std=c++11  c++-字符串分割.cpp

void split(const std::string &s, std::vector<std::string> &sv, const char *delim = " ")
{
    sv.clear();                            // 1.
    char *buffer = new char[s.size() + 1]; // 2.
    buffer[s.size()] = '\0';
    std::copy(s.begin(), s.end(), buffer); // 3.
    char *p = std::strtok(buffer, delim);  // 4.
    do
    {
        sv.push_back(p);                      // 5.
    } while ((p = std::strtok(NULL, delim))); // 6.
    delete[] buffer;
    return;
}

void spilt_string(const std::string &strIn, const std::string &div, std::vector<std::string> &vecOut)
{
    std::string::size_type pos1(0);
    std::string::size_type pos2 = strIn.find(div);

    while (std::string::npos != pos2)
    {
        vecOut.push_back(strIn.substr(pos1, pos2 - pos1));
        pos1 = pos2 + div.size();
        pos2 = strIn.find(div, pos1);
    }

    if (pos1 != strIn.length())
    {
        vecOut.push_back(strIn.substr(pos1));
    }
}

void main01()
{
    std::string testInput = "2,3,4,5"; //输入
    std::vector<std::string> output;   //输出
    std::string div = ",";             //分隔符
    spilt_string(testInput, div, output);
    for (auto iter = output.begin(); iter != output.end(); ++iter)
    {
        std::cout << *iter << std::endl;
        std::cout << atoi((*iter).c_str()) << std::endl; //转换成数字
    }
}

int main()
{
    main01();
    std::cout << "===========================" << std::endl;
    std::string s("       0        0            all  --  *      *       172.17.0.1           0.0.0.0/0");
    std::vector<std::string> sv;

    split(s, sv, " ");

    for (auto iter = sv.begin(); iter != sv.end(); ++iter)
    {
        //std::cout << *iter << std::endl;
    }
    for (int i = 0; i < sv.size(); i++)
    {
        std::cout << "destination : " << sv[7] << std::endl;
        std::cout << "source : " << sv[6] << std::endl;
        std::cout << "bytes : " << sv[1] << std::endl;
    }

    return 0;
}