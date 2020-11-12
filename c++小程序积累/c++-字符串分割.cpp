#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

void split(const std::string& s,
    std::vector<std::string>& sv,
                  const char* delim = " ") {
    sv.clear();                                 // 1.
    char* buffer = new char[s.size() + 1];      // 2.
    buffer[s.size()] = '\0';
    std::copy(s.begin(), s.end(), buffer);      // 3.
    char* p = std::strtok(buffer, delim);       // 4.
    do {
        sv.push_back(p);                        // 5.
    } while ((p = std::strtok(NULL, delim)));   // 6.
    delete[] buffer;
    return;
}

int main() {
    std::string s("       0        0            all  --  *      *       172.17.0.1           0.0.0.0/0");
    std::vector<std::string> sv;

    split(s, sv, " ");

    for (auto iter = sv.begin();iter != sv.end(); ++iter) {
        //std::cout << *iter << std::endl;
    }
    for(int i = 0; i < sv.size(); i++ ) {
        std::cout << "destination : "  << sv[7]  << std::endl;
        std::cout << "source : " << sv[6]  << std::endl;
        std::cout << "bytes : " <<sv[1]  << std::endl;
    }

    return 0;
}