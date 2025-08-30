cmake_minimum_required(VERSION 3.10)
project(pcd_header_extractor)

# 设置PCL依赖
find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})

# 添加头文件目录
include_directories(include)


# 添加测试程序
add_executable(pcd_header_extractor src/main.cpp src/pcd_header.cpp)
# 链接静态库和PCL库
target_link_libraries(pcd_header_extractor
    ${PCL_LIBRARIES}
)
