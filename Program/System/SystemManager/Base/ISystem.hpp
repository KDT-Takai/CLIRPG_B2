#pragma once
#include"entt/entt.hpp"

namespace System
{
	/// <summary>
	/// システムのインターフェース
	/// </summary>
	class ISystem
	{
	public:
		ISystem() = default;
		virtual ~ISystem() = default;
		
		/// <summary>
		/// 状態更新
		/// </summary>
		virtual void Update(entt::registry Reg) {};
	};

	/// <summary>
	/// Viewを自動的に呼ぶテンプレート基底クラス
	/// </summary>
	template<typename... Components>
	class BaseSystem : public ISystem
	{
	protected:
		/// <summary>
		/// 処理メソッド
		/// このメソッドを継承して各システムを作成します
		/// </summary>
		/// <param name="Entity">エンティティ</param>
		/// <param name="...Component">コンポーネントの可変長</param>
		virtual void UpdateEntity(entt::entity Entity, Components&... Component) = 0;
	public:
		/// <summary>
		/// 状態更新
		/// </summary>
		virtual void Update(entt::registry Reg)override;
	};

	template<typename ...Components>
	inline void BaseSystem<Components...>::Update(entt::registry Reg)
	{
		auto view = Reg.view<Components...>();
		// Viewをイテレートして各エンティティを処理
		for (auto entity : view) {
			UpdateEntity(entity, view.template get<Components>(entity)...);
		}
	}
}