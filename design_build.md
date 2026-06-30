# CLIRPG_B2 設計書 - ビルドとテスト

## ビルド構成

- **Debug**: デバッグビルド（シンボル情報付き）
- **Release**: 最適化ビルド

### ビルドコマンド

```bash
# Debug モード
msbuild CLIRPG_B2.sln /p:Configuration=Debug /m:4

# Release モード
msbuild CLIRPG_B2.sln /p:Configuration=Release /m:4
```

## テスト戦略

### ユニットテスト

Google Test を使用したユニットテストを実装。

- `SceneTest`: シーン管理の動作確認
- `ErrorHandlingTest`: エラーハンドリングの確認
- `GameManagerTest`: ゲーム管理ロジックの確認

### テスト実行

```bash
# ビルド後、tests/x64/Debug/CLIRPG_B2_UnitTests.dll を実行
```

## ドキュメント生成

Doxygen を使用した自動ドキュメント生成。

```bash
doxygen doc/Doxyfile
```

出力先: `doc/html/`
