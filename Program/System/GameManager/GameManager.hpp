#pragma once
#include"System/Singleton/Singleton.hpp"


namespace System
{
	class GameManager : public Singleton<GameManager>
	{
		GENERATE_SINGLETON_BODY(GameManager);

		/// <summary>
		/// 更新処理
		/// </summary>
		void Update();

		/// <summary>
		/// 描画
		/// </summary>
		void Render();
	public:
		/// <summary>
		/// 初期化
		/// </summary>
		/// <returns>true:成功</returns>
		bool Initilaize();

		/// <summary>
		/// メインループ
		/// </summary>
		void Run();

		/// <summary>
		/// 終了処理
		/// </summary>
		/// <returns>true:成功</returns>
		bool Finalize();

	private:
		bool mIsRunning = true;
	};
}

