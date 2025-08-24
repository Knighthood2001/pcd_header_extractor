cmake_minimum_required(VERSION 3.10)
project(pcd_header_extractor)

# 设置PCL依赖
find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})

# 添加头文件目录
include_directories(include)

# 设置静态库输出目录为项目根目录下的lib文件夹
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 生成静态库
add_library(pcd_header_static STATIC src/pcd_header.cpp)
target_include_directories(pcd_header_static PUBLIC include)
target_link_libraries(pcd_header_static ${PCL_LIBRARIES})


# 添加测试程序
add_executable(pcd_header_extractor src/main.cpp src/pcd_header.cpp)
# 链接静态库和PCL库
target_link_libraries(pcd_header_extractor
    ${PCL_LIBRARIES}
)


# # 安装库和头文件（可选）
# install(TARGETS pcd_header_static DESTINATION lib)
# install(DIRECTORY include/ DESTINATION include)