#pragma once

#include <memory>
#include <string>
#include <stdexcept>

#include "System/Singleton/Singleton.hpp"
#include "System/IScene/IScene.hpp"
#include "System/ErrorHandling.hpp"

namespace System {

/// <summary>
/// Singleton pattern implementation for scene management.
/// </summary>
class SceneManager : public Singleton<SceneManager> {

    GENERATE_SINGLETON_BODY(SceneManager)

public:

    /// <summary>
    /// Set the start scene with constructor arguments.
    /// Returns std::expected&lt;void, ErrorMessage&gt;.
    /// </summary>
    template<class TScene, class...Args>
    Result<void> SetStartScene(Args&&...args) {

        return ChangeScene<TScene>(std::forward<Args>(args)...);

    }

    template<class TScene, class...Args>
    Result<void> ChangeScene(Args&&...args)
    {
        /// <summary>
        /// Transition to a new scene.
        /// </summary>
        // Clean up current scene with exception-safe cleanup
        if (mCurrent) {

            try {
                mCurrent->Finalize();
            } catch (...) {
                // Log error but continue transition
            }
        }
        // Create new scene with exception safety
        mCurrent = std::make_unique<TScene>(std::forward<Args>(args)...);
        // Initialize new scene with exception handling
        try {
            mCurrent->Initialize();
        } catch (...) {
            // Clean up on initialization failure
            mCurrent.reset();
            throw;
        }

        return {}; // Success
    }

    void Update();

    /// <summary>
    /// Get the name of the current scene.
    /// Returns "none" if no scene is active.
    /// </summary>
    std::string CurrentSceneName() const noexcept;

protected:

    /// <summary>
    /// Called when singleton is created.
    /// </summary>
    void OnCreate() override;
    /// <summary>
    /// Called when singleton is destroyed.
    /// </summary>
    void OnDestroy() override;

private:

    std::unique_ptr<IScene> mCurrent;
};

} // namespace System
