#pragma once

namespace System {

/// <summary>
/// シーンインターフェース
/// </summary>
class IScene {
public:
    virtual ~IScene() = default;

    /// <summary>
    /// シーンの名称を取得
    /// </summary>
    /// <returns>シーン名</returns>
    virtual std::string GetName() const = 0;

    /// <summary>
    /// シーンを初期化
    /// </summary>
    virtual void Initialize() = 0;

    /// <summary>
    /// シーンの更新処理
    /// </summary>
    virtual void Update() = 0;

    /// <summary>
    /// シーンを終了処理
    /// </summary>
    virtual void Finalize() = 0;
};

} // namespace System
