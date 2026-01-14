#pragma once
#include"System/Singleton/Singleton.hpp"
#include"System/SystemManager/Base/ISystem.hpp"

#include<memory>
#include<vector>
#include<concepts>

namespace System
{
	/// <summary>
	/// ISystemを継承しているクラスのみ
	/// </summary>
	template<typename T>
	concept IsSystem = std::derived_from<T, ISystem>;

	class SystemManager : public Singleton<SystemManager>
	{
		GENERATE_SINGLETON_BODY(SystemManager);
	public:
		// システムの登録 (可変長引数でコンストラクト)
		template<IsSystem T, typename... Args>
		void AddSystem(Args&&... args) {
			mSystems.push_back(std::make_unique<T>(std::forward<Args>(args)...));
		}

		/// <summary>
		/// 状態更新
		/// </summary>
		/// <param name="Reg"></param>
		void Update(entt::registry& Reg);
	private:
		/// <summary>
		/// システムのコレクション
		/// </summary>
		std::vector<std::unique_ptr<ISystem>> mSystems;
	};
}



