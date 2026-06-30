#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "System/ErrorHandling.hpp"

namespace Data {

/// <summary>
/// JSON データ読み込みクラス。
/// </summary>
class JsonLoader {
public:

    /// <summary>
    /// ファイルから JSON を読み込む。
    /// </summary>
    /// <param name="filename">JSON ファイルパス。</param>
    /// <returns>読み込んだ JSON 文字列。</returns>
    static Result<std::string, std::string> LoadFile(const std::string& filename);

    /// <summary>
    /// 文字列から JSON をパースする。
    /// </summary>
    /// <param name="json">JSON 文字列。</param>
    /// <returns>パースされたデータ構造。</returns>
    static Result<std::string, std::string> Parse(const std::string& json);

private:

    JsonLoader() = default;
};

} // namespace Data
