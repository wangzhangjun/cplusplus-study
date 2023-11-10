// HelloWorldStubImpl.cpp
#include "HelloWorldStubImpl.hpp"

HelloWorldStubImpl::HelloWorldStubImpl() { }
HelloWorldStubImpl::~HelloWorldStubImpl() { }


void HelloWorldStubImpl::sayHello(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name,  uint8_t _index, sayHelloReply_t _reply) {
	std::stringstream messageStream;
	messageStream << "Hello " << _name << "!";
	std::cout << "service recv index : " <<  +_index << std::endl;
	std::cout << "sayHello('" << _name << "'): '" << messageStream.str() << "'\n";
	// std::cout << "in service" << _name << _index << std::endl;

    _reply(messageStream.str());
};

// virtual void sayHello2(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, sayHello2Reply_t _reply) {
// 	std::stringstream messageStream;
// 	messageStream << "Hello2 " << _name << "!";
// 	std::cout << "sayHello2('" << _name << "'): '" << messageStream.str() << "'\n";
	
// 	_reply(messageStream.str());
// }
