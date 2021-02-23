#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;
bool MyCompare(const int &a, const int &b)
{
    return a < b;
}

void test()
{
    vector<int> v(10);

    for (int i = 0; i < 10; i++){
        v[i] = rand() % 100;
    }
    sort(v.begin(), v.end(), MyCompare);
    printf("\n");
    for (int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main()
{
    test();
    std::cout << "hello world" << std::endl;
}