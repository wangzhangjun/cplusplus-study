// HelloWorldStubImpl.cpp
#include "HelloWorldStubImpl.hpp"

HelloWorldStubImpl::HelloWorldStubImpl() { cnt = 0; }
HelloWorldStubImpl::~HelloWorldStubImpl() { }


void HelloWorldStubImpl::sayHello(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, uint64_t _index, v1::commonapi::HelloWorld::EventType _eventType, sayHelloReply_t _reply) {
	std::stringstream messageStream;
	messageStream << "Hello " << _name << "!";
	std::cout << "service recv sayHello index : " <<  +_index << std::endl;
	printf("service recv sayHello eventType : %d\n", (int)_eventType);
	std::cout << "sayHello('" << _name << "'): '" << messageStream.str() << "'\n";

    _reply(messageStream.str());
};

void HelloWorldStubImpl::sayGoodBye(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, uint64_t _index, v1::commonapi::HelloWorld::EventType _eventType, sayGoodByeReply_t _reply) {
	std::stringstream messageStream;
	messageStream << "GoodBye " << _name << "!";
	std::cout << "service recv sayGoodBye index : " <<  +_index << std::endl;
	printf("service recv sayGoodBye eventType : %d\n", (int)_eventType);
	std::cout << "sayGoodBye('" << _name << "'): '" << messageStream.str() << "'\n";

    _reply(messageStream.str());
}

void HelloWorldStubImpl::incCounter() {
	cnt++;
	fireMyStatusEvent((int32_t) cnt);  //  生成后就会有这个方法名，把广播fire出去
	std::cout << "New counter value = " << cnt << "!" << std::endl;
}
