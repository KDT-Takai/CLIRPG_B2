# CLIRPG_B2 設計書 - エンティティシステム

## Entt ライブラリ

高パフォーマンスな C++ エンティティ管理ライブラリを使用。

### コンポーネント設計

```cpp
// キャラクターコンポーネント
struct CharactorStatusComp {
    std::string name;
    Status status;
};

// タグコンポーネント
struct PlayerTag : entt::component<PlayerTag> {};
```

### EntityManager

エンティティの作成・削除を管理。

```cpp
class EntityManager {
public:
    static EntityManager& GetInstance();
    entt::entity CreateLocalEntity();
    void Destroy(entt::entity entity);
};
```
