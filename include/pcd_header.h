#pragma once
#include <vector>
#include <string>

// 定义字段信息结构体
struct FieldInfo {
    std::string name;
    size_t size;
    std::string type;
    size_t count;
    size_t offset;
};

// 声明库的接口函数
std::vector<FieldInfo> extractPCDHeaderInfo(const std::string& file_path);

std::string getDataTypeName(int datatype);