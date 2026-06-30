#include "ErrorHandlingTest.h"
#include "System/ErrorHandling.hpp"

// エラーハンドリングテスト
TEST(ErrorHandlingTest, Result_SuccessCase) {
    // 成功ケースのテスト
    auto result = std::expected<int, std::string>{42};
    
    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(*result, 42);
}

TEST(ErrorHandlingTest, Result_ErrorCase) {
    // エラーケースのテスト
    auto result = std::expected<int, std::string>{std::string("error message")};
    
    EXPECT_FALSE(result.has_value());
    EXPECT_EQ(*result, "error message");
}
