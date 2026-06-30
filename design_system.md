# CLIRPG_B2 設計書 - システム構成

## プロジェクト概要

CLIRPG_B2 は、Visual Studio で開発された C++ コンソール RPG ゲームです。プレイヤーは攻撃や魔法、アイテムを駆使してモンスターと戦い、10 階層のボスを倒してゲームクリアを目指します。

## アーキテクチャ

### システム構成

```
CLIRPG_B2/
├── Program/              # メインロジック
│   ├── Graphics/        # グラフィックス関連
│   │   └── Renderer.cpp/.hpp
│   ├── System/          # ゲームシステム
│   │   ├── GameManager/     # ゲーム管理
│   │   ├── Scene/           # シーン管理
│   │   ├── Singleton/       # シングルトンパターン
│   │   ├── SystemManager/   # システム統合
│   │   ├── Entity/          # エンティティ管理
│   │   └── KeyInput/        # キー入力処理
│   └── main.cpp           # アプリケーションエントリーポイント
├── Source/              # データ定義・ファクトリ
│   ├── Chara/            # キャラクター定義
│   │   ├── Player/          # プレイヤー定義
│   │   ├── Enemy/           # 敵定義
│   │   ├── Status/          # ステータス定義
│   │   └── Tag/             # タグ定義
│   ├── Item/              # アイテム定義
│   ├── Scene/             # シーンイベント定義
│   └── Hierarchy/         # 階層システム
├── Plugin/               # プラグイン・ライブラリ
│   └── entt/             # Entt エンティティ管理ライブラリ
└── tests/                # ユニットテスト
    ├── UnitTests.vcxproj
    ├── SceneTest.cpp/.h
    ├── ErrorHandlingTest.cpp/.h
    └── GameManagerTest.cpp/.h
```
