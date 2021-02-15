//
// Created by zhjwang on 2021-02-15.
//

#include "map"
#include <iostream>
#include <string>

//map增删改查
/*
 * 插入的四种方法中，前三种方法都是返回值为pair<iterator, bool>
 *
 * 注意：
 * 前三种方法中，如果key已经存在，会返回失败。
 * 方法四，如果key已经存在，则是会覆盖（修改）之前插入的值
 * */
void main37()
{
    std::map<int ,std::string> map1;
    //方法1
    map1.insert(std::pair<int,std::string>(1, "teacher1"));
    map1.insert(std::pair<int,std::string>(2, "teacher2"));

    //方法2
    map1.insert(std::make_pair(3, "teacher3"));
    map1.insert(std::make_pair(4, "teacher4"));

    //方法3
    std::pair<std::map<int ,std::string>::iterator,bool> pair1 = map1.insert(std::map<int ,std::string>::value_type(5,"teacher5"));
    if(pair1.second == true) {
        std::cout << "插入成功:" ;
        std::cout << pair1.first->first << "\t" << pair1.first->second << std::endl;
    }else{
        std::cout << "插入失败！" << std::endl;
    }
    std::pair<std::map<int ,std::string>::iterator,bool> pair2 = map1.insert(std::map<int ,std::string>::value_type(5,"teacher6"));
    if(pair2.second == true) {
        std::cout << "插入成功:" ;
        std::cout << pair2.first->first << "\t" << pair2.first->second << std::endl;
    }else{
        std::cout << "插入失败！" << std::endl;
    }

    //方法4
    map1[7] = "teacher7";
    map1[7] = "teacher8"; //方法4会覆盖前面的插入值

    //遍历
    for(std::map<int ,std::string>::iterator it = map1.begin(); it!=map1.end();it++) {
        std::cout << it->first << "\t" << it->second << std::endl;
    }
    std::cout << "size:" << map1.size() <<std::endl;
    //删除
    std::cout << "删除。。。" <<std::endl;
    while(!map1.empty()) {
        std::map<int ,std::string>::iterator it = map1.begin();
        std::cout << it->first << "\t" << it->second << std::endl;
        map1.erase(it);
    }
}

//查找
void main38()
{
    std::map<int ,std::string> map1;
    //方法1
    map1.insert(std::pair<int,std::string>(1, "teacher1"));
    map1.insert(std::pair<int,std::string>(2, "teacher2"));
    //方法2
    map1.insert(std::make_pair(3, "teacher3"));
    map1.insert(std::make_pair(4, "teacher4"));
    //方法3
    map1.insert(std::map<int ,std::string>::value_type(5,"teacher5"));
    map1.insert(std::map<int ,std::string>::value_type(6,"teacher6"));
    //方法4
    map1[7] = "teacher7";
    map1[8] = "teacher8";

    //遍历
    for(std::map<int ,std::string>::iterator it = map1.begin(); it!=map1.end();it++) {
        std::cout << it->first << "\t" << it->second << std::endl;
    }

    std::map<int ,std::string>::iterator it = map1.find(100);
    if(it == map1.end()){
        std::cout << "key为100元素不存在！" <<std::endl;
    }else{
        std::cout << it->first << "\t" << it->second << std::endl;
    }

    //equal_range
    std::pair<std::map<int ,std::string>::iterator,std::map<int ,std::string>::iterator> pair = map1.equal_range(5);
    //第一个迭代器 大于等于5的迭代器位置
    //第二个迭代器 大于5的位置
    if(pair.first == map1.end()){
        std::cout << "第一个迭代器 大于等于5的迭代器位置不存在" << std::endl;
    }else{
        std::cout << pair.first->first << "\t" << pair.first->second << std::endl;
    }
    if(pair.second == map1.end()){
        std::cout << "第二个迭代器 大于5的迭代器位置不存在" << std::endl;
    }else{
        std::cout << pair.second->first << "\t" << pair.second->second << std::endl;
    }
}

int main39()
{
//    main37();
    main38();
    return 0;
}
