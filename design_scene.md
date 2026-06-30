# CLIRPG_B2 設計書 - シーンシステム

## SceneManager

シングルトンパターンで実装されたシーン管理クラス。現在のシーンを `std::unique_ptr<IScene>` で保持し、シーンの遷移を管理する。

### メソッド一覧

- `SetStartScene<TScene, Args...>(Args&&...)`: ゲーム開始時の初期シーンを設定
- `ChangeScene<TScene, Args...>(Args&&...)`: シーンの切り替えを実行（`std::expected<void, ErrorMessage>` を返す）
- `Update()`: 現在のシーンの Update を呼び出す
- `CurrentSceneName() const`: 現在のシーン名を取得

## IScene インターフェース

すべてのシーンが実装するインターフェース。

```cpp
class IScene {
public:
    virtual ~IScene() = default;
    virtual void Initialize() = 0;
    virtual void Update() = 0;
    virtual void Finalize() = 0;
    virtual std::string GetName() const = 0;
};
```

### シーン実装

- `TitleScene`: タイトル画面シーン
- `InGameScene`: ゲーム進行中のメインシーン
- `ClearScene`: クリアシーンの表示
