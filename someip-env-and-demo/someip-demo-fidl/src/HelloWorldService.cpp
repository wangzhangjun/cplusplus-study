// HelloWorldService.cpp
#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "HelloWorldStubImpl.hpp"

using namespace std;

int main() {
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    
    // 创建两个服务实例对象，分别传入实例名称
    std::shared_ptr<HelloWorldStubImpl> myService = std::make_shared<HelloWorldStubImpl>("test");
    std::shared_ptr<HelloWorldStubImpl> myService2 = std::make_shared<HelloWorldStubImpl>("test2");
    
    // 注册MyService配置的实例 (InstanceId = "test")
    runtime->registerService("local", "test", myService);  
    
    // 注册MyService2配置的实例 (InstanceId = "test2")  
    runtime->registerService("local", "test2", myService2);
    
    std::cout << "Successfully Registered 2 Service Instances!" << std::endl;

    while (true) {
        // 两个实例都要更新计数器
        myService->incCounter();
        myService2->incCounter();
        std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    return 0;
}