// HelloWorldStubImpl.hpp
#ifndef HELLOWORLDSTUBIMPL_H_
#define HELLOWORLDSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HelloWorldStubDefault.hpp>

class HelloWorldStubImpl: public v1_0::commonapi::HelloWorldStubDefault {
public:
    HelloWorldStubImpl();
    virtual ~HelloWorldStubImpl();
    void incCounter();
    virtual void sayHello(const std::shared_ptr<CommonAPI::ClientId> _client,   std::string _name, uint64_t _index, v1::commonapi::HelloWorld::EventType _eventType, sayHelloReply_t _return);
    virtual void sayGoodBye(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, uint64_t _index, v1::commonapi::HelloWorld::EventType _eventType, sayGoodByeReply_t _return);
};
#endif /* HELLOWORLDSTUBIMPL_H_ */