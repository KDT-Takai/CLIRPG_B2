#include "JsonLoader.hpp"
#include <iostream>

namespace Data {

Result<std::string, std::string> JsonLoader::LoadFile(const std::string& filename) {
    try {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return std::expected<std::string, std::string>{std::string("Failed to open file: ") + filename};
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        return std::expected<std::string, std::string>{buffer.str()};

    } catch (const std::exception& e) {
        return std::expected<std::string, std::string>{std::string("Error loading file: ") + e.what()};
    }
}

Result<std::string, std::string> JsonLoader::Parse(const std::string& json) {
    // TODO: JSON パース実装（簡易版）
    if (json.empty()) {
        return std::expected<std::string, std::string>{"Empty JSON"};
    }

    // 簡易なパース処理（実際には proper JSON parser を使用する）
    return json;
}

} // namespace Data
