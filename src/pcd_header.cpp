#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include "pcd_header.h"
std::string getDataTypeName(int datatype) {
    switch(datatype) {
        case 1: return "INT8";
        case 2: return "UINT8";
        case 3: return "INT16";
        case 4: return "UINT16";
        case 5: return "INT32";
        case 6: return "UINT32";
        case 7: return "FLOAT32";
        case 8: return "FLOAT64";
        default: return "UNKNOWN";
    }
}
std::vector<FieldInfo> extractPCDHeaderInfo(const std::string& file_path) {
    pcl::PCLPointCloud2 cloud;
    if (pcl::io::loadPCDFile(file_path, cloud) == -1) {
        throw std::runtime_error("Failed to load PCD file: " + file_path);
    }

    std::vector<FieldInfo> fields;
    for (const auto& field : cloud.fields) {
        if (field.name[0] == '_') continue;
        size_t field_size = 0;
        switch (field.datatype) {
            case 1: case 2: field_size = 1; break;
            case 3: case 4: field_size = 2; break;
            case 5: case 6: case 7: field_size = 4; break;
            case 8: field_size = 8; break;
            default: field_size = 0;
        }
        fields.push_back({field.name, field_size * field.count, getDataTypeName(field.datatype), field.count, field.offset});
    }
    return fields;
}