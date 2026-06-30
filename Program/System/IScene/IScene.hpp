#pragma once
#include <string>

namespace System {

/// <summary>
/// Scene interface for all game scenes.
/// </summary>
class IScene
{
public:
	virtual ~IScene() = default;

	/// <summary>
	/// Initialize the scene.
	/// Called when the scene is first created or reactivated.
	/// </summary>
	virtual void Initialize() {}

	/// <summary>
	/// Update the scene logic.
	/// Called every frame during game loop.
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// Finalize and cleanup the scene.
	/// Called when the scene is destroyed or deactivated.
	/// </summary>
	virtual void Finalize() {}

	/// <summary>
	/// Get the name of this scene.
	/// </summary>
	/// <returns>The scene name.</returns>
	virtual std::string GetName() const = 0;
};

} // namespace System