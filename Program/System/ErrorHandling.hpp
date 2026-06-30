#pragma once

#include <string>
#include <stdexcept>
#include <variant>

namespace System {

/// エラーメッセージの型
using ErrorMessage = std::string;

/// 成功またはエラーを返す型（C++20 std::expected の代替）
template<typename T, typename E = ErrorMessage>
class Result {
public:
    /// デフォルトコンストラクタ（初期状態はエラー）
    constexpr Result() noexcept : mValue(E{}) {}
    
    ~Result() = default;
    Result(const Result&) = delete;
    Result& operator=(const Result&) = delete;
    
    /// 値があるか確認（成功しているか）
    [[nodiscard]] bool has_value() const { 
        return std::holds_alternative<T>(mValue); 
    }
    
    /// 成功したか確認
    [[nodiscard]] bool ok() const { 
        return std::holds_alternative<T>(mValue); 
    }
    
    /// 失敗しているか確認
    [[nodiscard]] bool has_error() const { 
        return !std::holds_alternative<T>(mValue); 
    }
    
    /// 値があるか確認（bool 型として使用可能）
    explicit operator bool() const { 
        return std::holds_alternative<T>(mValue); 
    }
    
    /// 値を取得（エラーの場合は例外を投げる）
    T& value() & { 
        if (!std::holds_alternative<T>(mValue)) throw E("Result::value() called on error"); 
        return std::get<T>(mValue); 
    }
    
    const T& value() const & { 
        if (!std::holds_alternative<T>(mValue)) throw E("Result::value() called on error"); 
        return std::get<T>(mValue); 
    }
    
    /// 値を取得（エラーの場合は nullptr）
    const T* operator->() const { 
        if (!std::holds_alternative<T>(mValue)) return nullptr; 
        return &std::get<T>(mValue); 
    }
    
    /// エラーを取得
    E error() const { 
        if (std::holds_alternative<T>(mValue)) throw std::runtime_error("Result::error() called on success"); 
        return std::get<E>(mValue); 
    }
    
private:
    std::variant<T, E> mValue{};
};

} // namespace System
