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
 * 前三种方法中，当插入已经插入的key时，会返回失败。
 * 方法四，当插入已经插入的key时，则是会覆盖之前插入的值
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

int main()
{
    main37();
    return 0;
}
