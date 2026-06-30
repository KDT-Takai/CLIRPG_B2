#pragma once

#include <string>
#include <stdexcept>
#include <variant>
#include <utility>

namespace System {

/// エラーメッセージの型
using ErrorMessage = std::string;

/// 成功またはエラーを返す型（C++20 std::expected の代替）
template<typename T, typename E = ErrorMessage>
class Result {
public:
    constexpr Result() noexcept : mValue(E{}) {}
    ~Result() = default;
    Result(const Result&) = delete;
    Result& operator=(const Result&) = delete;

    [[nodiscard]] bool has_value() const {
        return std::holds_alternative<T>(mValue);
    }
    [[nodiscard]] bool ok() const {
        return std::holds_alternative<T>(mValue);
    }
    [[nodiscard]] bool has_error() const {
        return !std::holds_alternative<T>(mValue);
    }
    explicit operator bool() const {
        return std::holds_alternative<T>(mValue);
    }

    T& value() & {
        if (!std::holds_alternative<T>(mValue)) throw E("Result::value() called on error");
        return std::get<T>(mValue);
    }
    const T& value() const & {
        if (!std::holds_alternative<T>(mValue)) throw E("Result::value() called on error");
        return std::get<T>(mValue);
    }
    const T* operator->() const {
        if (!std::holds_alternative<T>(mValue)) return nullptr;
        return &std::get<T>(mValue);
    }

    E error() const {
        if (std::holds_alternative<T>(mValue)) throw std::runtime_error("Result::error() called on success");
        return std::get<E>(mValue);
    }

private:
    std::variant<T, E> mValue{};
};

/// Result<void> のテンプレート特殊化
/// void は variant に入れられないため bool で成功/失敗を表現
template<typename E>
class Result<void, E> {
public:
    constexpr Result() noexcept : mOk(true), mError() {}
    constexpr Result(E err) noexcept : mOk(false), mError(std::move(err)) {}
    ~Result() = default;
    Result(const Result&) = delete;
    Result& operator=(const Result&) = delete;

    [[nodiscard]] bool has_value() const { return mOk; }
    [[nodiscard]] bool ok() const { return mOk; }
    [[nodiscard]] bool has_error() const { return !mOk; }
    explicit operator bool() const { return mOk; }

    void value() const {
        if (!mOk) throw std::runtime_error(mError);
    }

    E error() const {
        if (mOk) throw std::runtime_error("Result::error() called on success");
        return mError;
    }

private:
    bool mOk;
    E mError;
};

} // namespace System
