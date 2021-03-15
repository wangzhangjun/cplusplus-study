#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class HandleClientProtocol{
    public:
        void addMoney(){
            cout << "增加金币..." << endl;
        }
        void addDiamond(){
            cout << "增加钻石..." << endl;
        }
        void addEquipment(){
            cout << "穿装备..." << endl;
        }
};

//命令接口
class AbstractCommand{
    public:
        virtual void handle() = 0;  //处理客户端请求的接口
};

//处理增加金币
class AddMonyCommand : public AbstractCommand{
    public:
        AddMonyCommand(HandleClientProtocol *proto) {
            this->protocol = proto;
        }
        virtual void handle() {
            this->protocol->addMoney();
        }
    public:
        HandleClientProtocol *protocol;
};

//处理增加钻石
class AddDiamondCommand : public AbstractCommand{
public:
    AddDiamondCommand(HandleClientProtocol *proto)
    {
        this->protocol = proto;
    }
    virtual void handle()
    {
        this->protocol->addDiamond();
    }

public:
    HandleClientProtocol *protocol;
};

class AddEquipmentCommand : public AbstractCommand{
public:
    AddEquipmentCommand(HandleClientProtocol *proto)
    {
        this->protocol = proto;
    }
    virtual void handle()
    {
        this->protocol->addEquipment();
    }

public:
    HandleClientProtocol *protocol;
};

//服务器
class Server
{
public:
    void addRequest(AbstractCommand *command){
        commands.push(command);
    }
    void startHandle(){
        while (!commands.empty()){
            AbstractCommand *command  = commands.front();
            command->handle();
            commands.pop();
        }
    }
public:
    std::queue<AbstractCommand *> commands;
};

void test()
{
    HandleClientProtocol *proto = new HandleClientProtocol;

    AbstractCommand *addmoney = new AddMonyCommand(proto);
    AbstractCommand *adddian = new AddDiamondCommand(proto);
    AbstractCommand *addequ = new AddEquipmentCommand(proto);

    Server *ser = new Server;
    ser->addRequest(addmoney);
    ser->addRequest(adddian);
    ser->addRequest(addequ);

    ser->startHandle();
}

int main()
{
    test();
    return 0;
}