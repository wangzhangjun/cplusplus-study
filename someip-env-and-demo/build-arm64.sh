#!/bin/bash

# ARM64 Docker构建脚本 - 适用于Mac M4 Pro
# 作者: 自动生成
# 日期: $(date)

echo "🚀 开始为Mac M4 Pro (ARM64)构建SOME/IP开发环境Docker镜像..."

# 设置镜像名称和标签
IMAGE_NAME="someip-dev-arm64"
IMAGE_TAG="latest"
DOCKERFILE="Dockerfile.arm64"

# 检查Dockerfile是否存在
if [ ! -f "$DOCKERFILE" ]; then
    echo "❌ 错误: $DOCKERFILE 文件不存在!"
    exit 1
fi

echo "📋 构建信息:"
echo "   - 镜像名称: $IMAGE_NAME:$IMAGE_TAG"
echo "   - Dockerfile: $DOCKERFILE"
echo "   - 目标架构: linux/arm64"
echo "   - 构建平台: $(uname -m)"

# 确认构建
read -p "⚠️  注意: 构建过程可能需要20-30分钟，是否继续? (y/N): " -n 1 -r
echo
if [[ ! $REPLY =~ ^[Yy]$ ]]; then
    echo "🛑 构建已取消"
    exit 0
fi

echo "🔨 开始构建Docker镜像..."
echo "💡 提示: 如果构建失败，请确保Docker Desktop已启用ARM64支持"

# 构建Docker镜像，明确指定平台
docker build \
    --platform linux/arm64 \
    -t $IMAGE_NAME:$IMAGE_TAG \
    -f $DOCKERFILE \
    . \
    --no-cache \
    --progress=plain

# 检查构建结果
if [ $? -eq 0 ]; then
    echo "✅ Docker镜像构建成功!"
    echo
    echo "📊 镜像信息:"
    docker images | grep $IMAGE_NAME
    echo
    echo "🎯 使用方法:"
    echo "   运行容器: docker run -it --rm $IMAGE_NAME:$IMAGE_TAG /bin/bash"
    echo "   挂载本地代码: docker run -it --rm -v \$(pwd):/workspace $IMAGE_NAME:$IMAGE_TAG /bin/bash"
    echo
    echo "🧪 测试SOME/IP环境:"
    echo "   docker run --rm $IMAGE_NAME:$IMAGE_TAG commonapi-core-generator --version"
    echo "   docker run --rm $IMAGE_NAME:$IMAGE_TAG commonapi-someip-generator --version"
else
    echo "❌ Docker镜像构建失败!"
    echo "💡 常见解决方案:"
    echo "   1. 确保Docker Desktop正在运行"
    echo "   2. 检查网络连接(需要下载依赖包)"
    echo "   3. 确保有足够的磁盘空间(至少5GB)"
    echo "   4. 检查Docker Desktop是否启用了ARM64支持"
    exit 1
fi 