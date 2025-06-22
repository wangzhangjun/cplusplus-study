// HelloWorldStubImpl.cpp
#include "HelloWorldStubImpl.hpp"

HelloWorldStubImpl::HelloWorldStubImpl(const std::string& instanceName) 
    : instanceName_(instanceName), cnt_(0) { 
    std::cout << "Creating service instance: " << instanceName_ << std::endl;
}

HelloWorldStubImpl::~HelloWorldStubImpl() { }

void HelloWorldStubImpl::incCounter() {
    cnt_++;
    fireMyStatusEvent((int32_t) cnt_);
    std::cout << "[" << instanceName_ << "] Service New counter value = " << cnt_ << "!" << std::endl;
}

void HelloWorldStubImpl::sayHello(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, uint64_t _index, v1::commonapi::HelloWorld::EventType _eventType, sayHelloReply_t _reply) {
	std::stringstream messageStream;
	messageStream << "Hello " << _name << " from " << instanceName_ << "!";
	
	std::cout << "[" << instanceName_ << "] service recv sayHello index : " <<  +_index << std::endl;
	printf("[%s] service recv sayHello eventType : %d\n", instanceName_.c_str(), (int)_eventType);
	std::cout << "[" << instanceName_ << "] sayHello('" << _name << "'): '" << messageStream.str() << "'\n";

    _reply(messageStream.str());
};

void HelloWorldStubImpl::sayGoodBye(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, uint64_t _index, v1::commonapi::HelloWorld::EventType _eventType, sayGoodByeReply_t _reply) {
	std::stringstream messageStream;
	messageStream << "GoodBye " << _name << " from " << instanceName_ << "!";
	
	std::cout << "[" << instanceName_ << "] service recv sayGoodBye index : " <<  +_index << std::endl;
	printf("[%s] service recv sayGoodBye eventType : %d\n", instanceName_.c_str(), (int)_eventType);
	std::cout << "[" << instanceName_ << "] sayGoodBye('" << _name << "'): '" << messageStream.str() << "'\n";

    _reply(messageStream.str());
}

void HelloWorldStubImpl::myByteBuffer(const std::shared_ptr<CommonAPI::ClientId> _client, CommonAPI::ByteBuffer _indata, myByteBufferReply_t _reply) {
	
	std::cout << "[" << instanceName_ << "] in service myByteBuffer get indata:" << std::endl;

	//构造一个vector
	// 获取指向数据的指针
        const uint8_t* dataPtr = _indata.data();
        size_t dataSize = _indata.size();
        // 创建并填充 std::vector
        std::vector<uint8_t> result(dataPtr, dataPtr + dataSize);
	for(uint8_t elm : result) {
		std::cout << "[" << instanceName_ << "] elm:" << static_cast<int>(elm) << std::endl;
	}
	std::cout << "[" << instanceName_ << "] receive size:" << result.size() << std::endl;
	
	for (uint8_t i = 0; i < _indata.size(); i++) {
		// 注意直接打印_indata[i]是不行的，因为uint8_t实际上是 unsigned char，直接打印时会被解释为字符而不是数字
        std::cout << "[" << instanceName_ << "] index" << static_cast<int>(i) << ":value:" <<static_cast<int>(_indata[i]) << std::endl;
	}

	std::vector<uint8_t> data = { 'H', 'e', 'l', 'l', 'o', ',', ' ', 'C', 'o', 'm', 'm', 'o', 'n', 'A', 'P', 'I', '!', ' ', 'f', 'r', 'o', 'm', ' ' };
	// 将实例名称添加到响应中
	for (char c : instanceName_) {
		data.push_back(static_cast<uint8_t>(c));
	}
    CommonAPI::ByteBuffer buffer(data.begin(), data.end());

	_reply(buffer);	
}

