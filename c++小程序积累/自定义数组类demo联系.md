# c++小程序积累
Myarray.h
```
//
// Created by Zhangjun Wang  on 2018/5/21.
//

#ifndef PROJECT_MYARRAY_H
#define PROJECT_MYARRAY_H

#include <iostream>
using namespace std;

class MyArray{
public:
    MyArray();
    MyArray(int len);
    MyArray(const MyArray& another);
    int getLen();
    void setData(int index, int data);
    int getData(int index);
    ~MyArray();

private:
    int length;
    int *space;
};

#endif //PROJECT_MYARRAY_H

```

MyArray.cpp
```
//
// Created by Zhangjun Wang  on 2018/5/21.
//

#include "MyArray.h"

MyArray::MyArray() {
    this->space = NULL;
    this->length = 0;
}

MyArray::MyArray(int len) {
    if(len <= 0){
        this->length = 0;
        return;
    }
    else{
        this->length = len;
        this->space = new int[this->length];
        cout << "MyArray::MyArray(int len)" << endl;
    }
}

MyArray::MyArray(const MyArray &another) {
    if(another.length >= 0){
        this->length = another.length;
        this->space = new int[this->length];

        for(int i = 0; i < this->length; i++){
            this->space[i] = another.space[i]; //赋值
        }

        cout << "MyArray(const MyArray &another)" << endl;
    }
}

MyArray::~MyArray() {
    if(this->space != NULL){
        delete [] this->space;
        this->length = 0;
        this->space = NULL;
        cout <<"~MyArray()"<<endl;
    }
}

int MyArray::getLen() {
    return this->length;
}

void MyArray::setData(int index, int data) {
    if(this->space != NULL){
        this->space[index] = data;
    }
}

int MyArray::getData(int index) {
    return this->space[index];
}
```
main.cpp
```
#include <iostream>
#include "MyArray.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    MyArray array1(10);

    for(int i = 0; i < array1.getLen(); i++){
        array1.setData(i , i+10);
    }

    cout << "-----------" << endl;

    for(int i = 0; i < array1.getLen(); i++){
        cout << array1.getData(i) << endl;
    }

    //拷贝构造
    MyArray array2 = array1;
    cout << "------array2-----" << endl;

    for(int i = 0; i < array2.getLen(); i++){
        cout << array2.getData(i) << endl;
    }

    return 0;
}
```
