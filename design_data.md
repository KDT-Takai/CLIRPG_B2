# CLIRPG_B2 設計書 - データ定義

## キャラクターデータ

- `PlayerDataTable`: プレイヤーの初期ステータス定義
- `EnemyDataTable`: 敵のステータス定義
- `CharactorStatusComponent`: キャラクターの状態管理

### タグシステム

エンティティを分類するためのタグコンポーネント。

```cpp
struct PlayerTag : entt::component<PlayerTag> {};
struct EnemyTag : entt::component<EnemyTag> {};
```
