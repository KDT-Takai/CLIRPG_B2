# 依存関係管理ドキュメント

## 外部ライブラリ一覧

### Entt (エンティティ管理)
- **パス**: `Plugin/entt/entt.hpp`
- **サイズ**: ~3.4 MB
- **用途**: エンティティ・コンポーネント・システム管理
- **ライセンス**: MIT License
- **活用判断**: ✅ 使用推奨

#### 特徴
- 高パフォーマンスな C++ エンティティ管理ライブラリ
- Entity Component System (ECS) パターンをサポート
- コンポーネントの動的追加/削除が可能
- View ベースのクエリシステム

#### 使用方法
```cpp
#include "entt/entt.hpp"

// エンティティ作成
auto entity = registry.create();

// コンポーネント追加
registry.emplace<Position>(entity, x, y);

// クエリ
for (auto [it, pos] : registry.view<Position>()) {
    // 処理
}
```

### Google Test (ユニットテスト)
- **パス**: `tests/` フォルダ
- **用途**: ユニットテストフレームワーク
- **活用判断**: ✅ 使用推奨

#### 使用方法
```cpp
#include <gtest/gtest.h>

TEST(TestCaseName, TestName) {
    // テストコード
}
```

## ビルド依存関係

### Visual Studio プロジェクト設定
- **C++ 標準**: C++20 (`stdcpp20`)
- **プラットフォーム**: Win32 / x64
- **ビルド構成**: Debug / Release

### 必要なライブラリ
1. `gtest_main.lib` - Google Test ライブラリ
2. `entt.hpp` - ヘッダーのみ（リンク不要）

## 依存関係図

```
CLIRPG_B2/
├── Program/
│   ├── System/
│   │   └── EntityManager (Entt を使用)
│   └── Data/
│       └── JsonLoader (標準ライブラリのみ)
├── Plugin/entt/
│   └── entt.hpp (ヘッダーファイル)
└── tests/
    ├── UnitTests.vcxproj
    └── *.cpp/.h (Google Test を使用)
```

## 依存関係管理方針

### ヘッダーのみ（Entt）
- `entt.hpp` は単一の巨大なヘッダーファイル
- リンク不要、コピーのみで利用可能
- プラグインフォルダに配置してバージョン管理

### ライブラリ（Google Test）
- 外部からダウンロードまたはビルド
- `tests/UnitTests.vcxproj` に依存関係として設定
- バージョン固定（例：v1.12.x）

## 今後の拡張

### 追加予定ライブラリ
- **nlohmann/json**: JSON パース用（JsonLoader の実装に使用）
- **fmt**: フォーマット出力用（エラーメッセージの整形）

### 依存関係管理ツール
- `vcpkg` または `conan` を導入して依存関係を自動管理
