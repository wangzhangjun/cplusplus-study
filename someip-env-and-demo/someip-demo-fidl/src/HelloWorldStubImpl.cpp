// HelloWorldStubImpl.cpp
#include "HelloWorldStubImpl.hpp"

HelloWorldStubImpl::HelloWorldStubImpl() { }
HelloWorldStubImpl::~HelloWorldStubImpl() { }

int cnt = 0;
void HelloWorldStubImpl::incCounter() {
    cnt++;
    fireMyStatusEvent((int32_t) cnt);
    std::cout << "Service New counter value = " << cnt << "!" << std::endl;
}

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


void HelloWorldStubImpl::myByteBuffer(const std::shared_ptr<CommonAPI::ClientId> _client, CommonAPI::ByteBuffer _indata, myByteBufferReply_t _reply) {
	
	std::cout << "in service myByteBuffer get indata:" << std::endl;

	//构造一个vector
	// 获取指向数据的指针
        const uint8_t* dataPtr = _indata.data();
        size_t dataSize = _indata.size();
        // 创建并填充 std::vector
        std::vector<uint8_t> result(dataPtr, dataPtr + dataSize);
	for(uint8_t elm : result) {
		std::cout << "elm:" << static_cast<int>(elm) << std::endl;
	}
	std::cout << "receive size:" << result.size() << std::endl;
	
	for (uint8_t i = 0; i < _indata.size(); i++) {
		// 注意直接打印_indata[i]是不行的，因为uint8_t实际上是 unsigned char，直接打印时会被解释为字符而不是数字
        std::cout << "index" << static_cast<int>(i) << ":value:" <<static_cast<int>(_indata[i]) << std::endl;
	}

	std::vector<uint8_t> data = { 'H', 'e', 'l', 'l', 'o', ',', ' ', 'C', 'o', 'm', 'm', 'o', 'n', 'A', 'P', 'I', '!' };
    CommonAPI::ByteBuffer buffer(data.begin(), data.end());

	_reply(buffer);	
}

