# プロジェクト名
CLIRPG_B2_

## リンク
- [Develop](https://github.com/KDT-Takai/CLIRPG_B2/tree/feature/Develop)
- [Issues](https://github.com/KDT-Takai/CLIRPG_B2/issues)
- [PR](https://github.com/KDT-Takai/CLIRPG_B2/pulls)
- [Actions](https://github.com/KDT-Takai/CLIRPG_B2/actions)
- [Insights](https://github.com/KDT-Takai/CLIRPG_B2/pulse)

## 概要
CLIRPG_B2_は、Visual Studioで作成したC++のコンソールRPG。
プレイヤーは攻撃や魔法、アイテムを駆使してモンスターと戦い、階層を進みます。  
10階層にはボスが登場し、最深階を目指して冒険します。

---

## 使い方
- ゲーム起動後、画面の指示に従ってコマンドを入力
- 攻撃、魔法、アイテムで戦闘を行う
- 階層を進みボスを倒すとゲームクリア

---

## 環境
- Windows 10以降
- Visual Studio 2022
- C++20
- ビルド構成: Debug / Release
- 出力: CLIRPG_B2.exe

---

## インストール・セットアップ
1. リポジトリをクローン
   ```bash
   git clone https://github.com/KDT-Takai/CLIRPG_B2.git
2. VisualStudioでCLIRPG_B2.slnを開く

# 開発ルール

### ブランチの分け方
- `master` : 安定版
- `feature/develop` : 開発中の最新版
- 機能追加用ブランチ : `feature/Name/xxx`
- バグ修正用ブランチ : `bugfix/Name/xxx`
- ホットフィックス用ブランチ : `hotfix/Name/xxx`

### ブランチ命名規則
- 英語小文字を使用
- 例: `feature/Sato/AddLogin`, `bugfix/Sato/FixCrash`

## 命名規則

### フォルダ名
- 最初大文字  
  例：`System`, `Document`

### 変数・型・関数
- **ローカル変数、型（クラス、型のエイリアス、列挙型、テンプレート引数）、関数**  
  → パスカルケース  
  例：`AddDamage() {}`

- **メンバ変数**  
  → `m` + 変数名  
  例：`mAtk`

- **定数**  
  → スネークケース  
  例：`SNAKE_CASE`

- **関数引数**  
  → `a` + 引数名  
  例：`aNum`

- **struct（構造体）**  
  → パスカルケース  
  例：`TransformComponent`

- **enum（列挙型）**  
  → `e` + 列挙型名  
  例：`eType`

- **namespace**  
  → 一番先頭ディレクトリフォルダ名  
  例：`System`

> 分からない場合は @KDT_Takai か、 @KDT-SHIKAHARA に連絡してください

---

## 禁止事項

- `#define` による定数定義は禁止  
  例：`#define PLAYER_NUM 4`

- グローバル変数の定義は禁止

> **注意** 機能追加用ブランチなどを `master` ブランチにあげるのは絶対にしないでください。
