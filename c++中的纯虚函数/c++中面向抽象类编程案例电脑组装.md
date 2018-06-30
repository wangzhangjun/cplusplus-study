# c++中面向抽象类编程案例电脑组装

```
#include <iostream>

using namespace std;

class CPU{
public:
    virtual void caculate() = 0;
};

class Card
{
public:
    virtual void display() = 0;
};

class Memory
{
public:
    virtual void storage() = 0;
};

class Compute
{
public:
    Compute(CPU *cpu1, Memory *memory1, Card *card1)
    {
        this->cpu = cpu1;
        this->memory = memory1;
        this->card = card1;
    }

    void work()
    {
        cpu->caculate();
        memory->storage();
        card->display();
    }

    ~Compute()
    {
        if (cpu != NULL) {
            delete cpu;
            cpu = NULL;
        }
        if (card != NULL) {
            delete card;
            card = NULL;
        }
        if (memory != NULL) {
            delete memory;
            memory = NULL;
        }
    }
private:
    CPU *cpu;
    Memory *memory;
    Card *card;
};

class InterCpu : public CPU
{
public:
    virtual  void caculate() {
        cout << "cpu计算" << endl;
    }
};

class InterCard :public  Card
{
public:
    virtual  void display() override {
        cout << "显卡展示" << endl;
    }
};

class InterMemory : public Memory
{
public:
    virtual void storage() override {
        cout << "内存存储" << endl;
    }
};

//可扩展性
class KingStonMem: public Memory
{
public:
    void storage() override {
        cout << "金士顿内存" << endl;
    }
};

class NvidaCard : public Card
{
public:
    void display() override {
        cout << "英文显卡" << endl;
    }
};

int main() {
    CPU * cpu = new InterCpu;
    Card * card = new InterCard;
    Memory * memory = new InterMemory;

    Compute *compute = new Compute(cpu, memory, card);
    compute->work();
    delete compute;

    Card *cardNvid = new NvidaCard;
    Compute *compute1 = new Compute(cpu, memory, cardNvid);
    compute1->work();
    delete compute1;





    return 0;
}
```
