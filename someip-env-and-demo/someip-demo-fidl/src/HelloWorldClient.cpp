// HelloWorldClient.cpp
#include <iostream>
#include <string>
#include <unistd.h>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HelloWorldProxy.hpp>

using namespace v1_0::commonapi;

int main() {
    std::shared_ptr < CommonAPI::Runtime > runtime = CommonAPI::Runtime::get();
    std::shared_ptr<HelloWorldProxy<>> myProxy = runtime->buildProxy<HelloWorldProxy>("local", "test");  // test是InstanceId, 

    std::cout << "Checking availability!" << std::endl;
    while (!myProxy->isAvailable()) {
        std::cout <<  "Service is not Available..."  << std::endl;
        usleep(10);
    }

    // Subscribe to broadcast
    myProxy->getMyStatusEvent().subscribe([&](const int32_t& val) {
        std::cout << "Got message  Received status event: " << val << std::endl;
    });

    std::cout << "Available..." << std::endl;
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    while(true) {
        myProxy->sayHello("Zhjwang", 123 , HelloWorld::EventType::HEART_BEAT, callStatus, returnMessage);
        std::cout << "Got message after sayHello: '" << returnMessage << "'\n";

        myProxy->sayGoodBye("Zhjwang", 456 , HelloWorld::EventType::HB_RESTART, callStatus, returnMessage);
        std::cout << "Got message after sayGoodBye: '" << returnMessage << "'\n";

        std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    return 0;
}