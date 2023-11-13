### 环境搭建
docker build -t someipimage-latest  -f ./Dockerfile .
启动一个容器。

编译demo工程：

```bash
cd commonapi_someip_demo
mkdir build
cd build
cmake ..
make
```

生成fidl文件
```
commonapi-core-generator-linux-x86_64 -sk ./fidl/HelloWorld.fidl
commonapi-someip-generator-linux-x86_64 ./fidl/HelloWorld.fdepl
```
