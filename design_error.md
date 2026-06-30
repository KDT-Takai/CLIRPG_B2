# CLIRPG_B2 設計書 - エラーハンドリング

## Result<T, E> パターン

C++20 の `std::expected` を使用したエラーハンドリングを実装。

```cpp
template<typename T, typename E = ErrorMessage>
using Result = std::expected<T, E>;
```

### 特徴

- 例外処理を最小限に抑える
- エラーメッセージで原因を明確にする
- 呼び出し側で明示的にエラー処理を行う
