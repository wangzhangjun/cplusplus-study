//
// Created by zhjwang on 2021-02-15.
//

#include "set"
#include <iostream>

void main35()
{
    std::multiset<int> set1;
    int tmp = 0;
    printf("请输入multiset集合的值：");
    scanf("%d\n", &tmp);
    while(tmp != 0){
        set1.insert(tmp);
        printf("请输入multiset集合的值：");
        scanf("%d\n", &tmp);
    }
    for(std::multiset<int>::iterator it = set1.begin(); it!=set1.end(); it++) {
        std::cout << *it << std::endl;
    }
    while(!set1.empty()) {
        std::multiset<int>::iterator it = set1.begin();
        set1.erase(it);
    }
}
int main36()
{
    main35();
    return 0;
}
