// HelloWorldClient.cpp
#include <iostream>
#include <string>
#include <unistd.h>
#include <thread>
#include <vsomeip/vsomeip.hpp>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HelloWorldProxy.hpp>

using namespace v1_0::commonapi;

void handleStatusEvent(const int32_t& val) {
    std::cout << "Received status event in client: " << val << std::endl;
}

int main() {
    std::shared_ptr < CommonAPI::Runtime > runtime = CommonAPI::Runtime::get();
    std::shared_ptr<HelloWorldProxy<>> myProxy = runtime->buildProxy<HelloWorldProxy>("local", "test");  // test是InstanceId,

    std::cout << "Checking availability!" << std::endl;
    while (!myProxy->isAvailable()) {
        std::cout <<  "Service is not Available..."  << std::endl;
        usleep(200000);
    }

    std::cout << "Available..." << std::endl;
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    myProxy->sayHello("Zhjwang", 123 , HelloWorld::EventType::HEART_BEAT, callStatus, returnMessage);
    std::cout << "Got message after sayHello: '" << returnMessage << "'\n";

    myProxy->sayGoodBye("Zhjwang", 456 , HelloWorld::EventType::HB_RESTART, callStatus, returnMessage);
    std::cout << "Got message after sayGoodBye: '" << returnMessage << "'\n";

    // byteBuffer test
    CommonAPI::ByteBuffer indata = {88, 77, 78, 34};
    CommonAPI::ByteBuffer outdata = {};
    myProxy->myByteBuffer(indata, callStatus, outdata);
    if (callStatus == CommonAPI::CallStatus::SUCCESS) {
        std::cout << "Got message after myByteBuffer success!" << std::endl;
        std::string received_data(outdata.begin(), outdata.end());
        std::cout << "Received data: " << received_data << std::endl;
    }

    // Subscribe to broadcast
    std::function<void(const int32_t&)> statusEventHandler = handleStatusEvent;
    // myProxy->getMyStatusEvent().subscribe([&](const int32_t& val) {
    //     std::cout << "Received status event: " << val << std::endl;
    // });
    // 两种不同的写法，一种是lambda，一种是std::function
    myProxy->getMyStatusEvent().subscribe(statusEventHandler);

    while (true) {
        std::cout << "Now I am going to sleep for 5 seconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    return 0;
}