#include <iostream>
#include <string>
#include <set>
#include "threadsafe_unordered_map.h"

typedef gdface::mt::threadsafe_unordered_map<int, std::string> threadSafeUnorderedMap;

void createMap(threadSafeUnorderedMap &Map)
{
	std::string s("test");
	Map.insert(std::make_pair(1, s));

	std::string s1("test1");
	Map.insert(std::make_pair(2, s1));

	std::string s2("test2");
	Map.insert(std::make_pair(2, s2));
}

void earseSomeKey(threadSafeUnorderedMap& Map, int key)
{
	Map.erase(key);  //擦除某个key元素
}
void clear(threadSafeUnorderedMap& Map)
{
	Map.clear(); //清空整个map
}
void updateMap(threadSafeUnorderedMap& Map, int key, std::string value)
{
	Map.update(key, value);  //找到了就更新，没找到就插入
}
void insertIfAbsentMap(threadSafeUnorderedMap& Map, int key, std::string value)
{
	Map.insertIfAbsent(key, value); //和insert的区别是什么，测试发现都是有的话就不插入
}

 //mutable  RWLock  lock;

void test()
{
	typedef gdface::mt::threadsafe_unordered_map<int, std::set<std::string>> threadSafeUnorderedMapSet;
	threadSafeUnorderedMapSet fs_process_info;
	std::string process_path("c:\test\test.cpp");

	{
		//auto guard = lock.write_guard();
		/*fs_process_info.insertIfAbsent(1, std::set<std::string>());
		fs_process_info.begin()->second.insert(process_path);*/
	}
	fs_process_info.insertIfAbsent(1, std::set<std::string>()).insert(process_path);
	
	for (auto it : fs_process_info.begin()->second) {
		std::cout << it << std::endl;
	}

	auto path_inf_fs = fs_process_info.find(1);
	if (path_inf_fs != fs_process_info.end())
	{
		std::cout << "find set!" << std::endl;
		auto find_path = path_inf_fs->second.find(std::string("c:\test\test.cpp"));
		if (find_path != path_inf_fs->second.end())
		{
			std::cout << "find string result! " << std::endl;
		}
	}

}

int main()
{
	test();
	//threadSafeUnorderedMap testMap;
	//createMap(testMap);

	///*earseSomeKey(testMap, 1);
	//clear(testMap);*/
	//std::cout << testMap.size() << std::endl;
	//auto result = testMap.find(2);
	//if (result != testMap.end()){
	//	std::cout << "found!\n"<< result->second << std::endl;
	//}
	//else {
	//	std::cout << "no found!\n";
	//}

}

