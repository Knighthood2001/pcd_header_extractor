cmake_minimum_required(VERSION 3.10)
project(test_pcd_header)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找PCL库（必须与主项目一致）
find_package(PCL REQUIRED COMPONENTS io common)

# 包含头文件路径
include_directories(
    ${PCL_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/../include  # 主项目的头文件
)

# 链接静态库路径
link_directories(${CMAKE_SOURCE_DIR}/../lib)

# 添加测试程序
add_executable(test_pcd_header test.cpp)

# 链接静态库和PCL库
target_link_libraries(test_pcd_header
    pcd_header_static  # 静态库名称（无需写lib前缀和.a后缀）
    ${PCL_LIBRARIES}
)