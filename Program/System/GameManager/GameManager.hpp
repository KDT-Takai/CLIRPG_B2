#pragma once
#include"System/Scene/TitleScene.hpp"

/// <summary>
/// Main game loop controller.
/// </summary>
namespace System {
	class GameManager : public Singleton<GameManager>
	{
		GENERATE_SINGLETON_BODY(GameManager);

		/// <summary>
		/// Main game loop update.
		/// </summary>
		void Update();

		/// <summary>
		/// Render frame (placeholder for future graphics).
		/// </summary>
		void Render();
	public:
		/// <summary>
		/// Initialize the game manager.
		/// </summary>
		/// <returns>true: Initialization successful</returns>
		bool Initilaize();

		/// <summary>
		/// Run the main game loop.
		/// </summary>
		void Run();

		/// <summary>
		/// Cleanup and shutdown.
		/// </summary>
		/// <returns>true: Shutdown successful</returns>
		bool Finalize();

	private:
		bool mIsRunning = true;
	};
}
