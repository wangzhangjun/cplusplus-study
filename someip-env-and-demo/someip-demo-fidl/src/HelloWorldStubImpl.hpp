// HelloWorldStubImpl.hpp
#ifndef HELLOWORLDSTUBIMPL_H_
#define HELLOWORLDSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HelloWorldStubDefault.hpp>

class HelloWorldStubImpl: public v1_0::commonapi::HelloWorldStubDefault {
public:
    HelloWorldStubImpl();
    virtual ~HelloWorldStubImpl();
    virtual void sayHello(const std::shared_ptr<CommonAPI::ClientId> _client,   std::string _name,uint8_t _index, sayHelloReply_t _return);
    // virtual void sayHello2(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, sayHello2Reply_t _reply);
};
#endif /* HELLOWORLDSTUBIMPL_H_ */