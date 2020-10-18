#include <iostream>
#include <stdio.h>

int log_flag = 1;
//两个##，在宏里面表示的连接，见下面的CAT例子。在这里表示args可以是空
//log_flag是控制日志开关的一种方式，我们希望当其等于0的时候，就不打开日志信息，即跳过下面的printf,这个时候就巧妙的引入了do,while（0）循环，就是为了break出来
#define LOG(frm, args...)                                        \
    do                                                           \
    {                                                            \
        if (log_flag == 0)                                       \
            break;                                               \
        printf("[%s : %s : %d] ", __FILE__, __func__, __LINE__); \
        printf(frm, ##args);                                     \
        printf("\n");                                            \
    } while (0);

#define CAT(a, b) a##b
int main()
{
    int haizei = 9937;
    CAT(hai, zei) = 10000;    //宏替换，haizei=10000
    LOG("haizei=%d", haizei); //10000
    int a = 10;
    LOG("HELLO LOG");
    LOG("%d", a);
    printf("日志封装宏\n");
    return 0;
}