#include <iostream>

/*
和c最大的区别在于封装，把数据和操作数据的绑定在一起了。
*/
class Stack 
{
    typedef struct link {
        link(int _data, struct link *next_) : data(_data), next(next_) {

        } 
        int data;
        struct link *next;
    }Link;
private:
    int size;
    Link *head;
public:
    Stack() : size(0), head(NULL) {}
    ~Stack() {
        Link *tmp;
        while(head)
        {
            tmp = head;
            head = tmp->next;
            delete tmp;
        }
    }
    void initStack() {
        size = 0;
        head = NULL;
    }
    void pushStack(int data_) {
        Link *node = new Link(data_,head);
        head = node;
        ++size;
    }
    bool empty() {
        return (size == 0);
    }
    bool popStack(int &data)
    {
        if(empty()) {
            return false;
        }
        Link *tmp = head;
        data = head->data;
        head = head->next;
        delete tmp;
        --size;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Stack stack;
    for(int i = 0; i < 5; i++) {
        stack.pushStack(i);
    }
    int tmp;
    while(!stack.empty()) {
        stack.popStack(tmp);
        printf("%d\n", tmp);
    }
    return 0;
}
