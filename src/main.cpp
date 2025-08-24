#include "pcd_header.h"
#include <iostream>

int main(int argc, char* argv[]) {
    // 检查命令行参数
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <pcd_file_path>" << std::endl;
        return 1;
    }

    // 从命令行参数获取PCD文件路径
    const char* pcdFilePath = argv[1];

    try {
        auto fields = extractPCDHeaderInfo(pcdFilePath);
        for (const auto& f : fields) {
            std::cout << "Field: " << f.name 
                      << ", Type: " << f.type 
                      << ", Size: " << f.size 
                      << ", Count: " << f.count 
                      << ", Offset: " << f.offset << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}