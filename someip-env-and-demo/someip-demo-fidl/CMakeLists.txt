PROJECT(HelloWorldDemo)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
include_directories(
    src-gen
    /usr/include/CommonAPI-3.2
    /usr/include/vsomeip
)
link_directories(
	#/usr/local/lib
	/usr/lib
)
add_executable(client
	src/HelloWorldClient.cpp
	src-gen/v1/commonapi/HelloWorldSomeIPProxy.cpp
	src-gen/v1/commonapi/HelloWorldSomeIPDeployment.cpp
)
target_link_libraries(client CommonAPI CommonAPI-SomeIP vsomeip3)


add_executable(service
	src/HelloWorldService.cpp
	src/HelloWorldStubImpl.cpp
	src-gen/v1/commonapi/HelloWorldSomeIPStubAdapter.cpp
	# src-gen/v1/commonapi/HelloWorldStubDefault.cpp
	src-gen/v1/commonapi/HelloWorldSomeIPDeployment.cpp
)
target_link_libraries(service CommonAPI CommonAPI-SomeIP vsomeip3)
