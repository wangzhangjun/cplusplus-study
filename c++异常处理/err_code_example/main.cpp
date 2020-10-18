#include "my_error.h"
#include <fcntl.h>

int main()
{
    std::cout << "hello world" << std::endl;
    std::error_code ec1 = netd::errorcode::netd_error_code::errorCode1;
    std::cout << ec1.message() << std::endl;
    std::error_code ec2 = netd::errorcode::netd_error_code::errorCode2;
//    assert(ec2 == netd::errorcode::netd_error_code::errorCode2);
    std::cout << ec2 << std::endl;
    
    //使用system_category
    //system_category相当于是对posix标准的错误封装，可以方便的得到错误码以及对应的错误信息。
    std::error_code sys_error;
    int fd = open("./1.c", 0 , 0666);
    if(fd == -1){
    	std::cout << "fd==-1" << std::endl;
    	// sys_error = std::error_code(GetLastError(), std::system_category());  windows的用法
        sys_error = std::error_code(errno, std::system_category());  //posix的用法
    	std::cout << sys_error << std::endl;
        std::cout << sys_error.message() << std::endl;
        if(sys_error==std::errc::no_such_file_or_directory)
            std::cout << "123" << std::endl; 
    }
}