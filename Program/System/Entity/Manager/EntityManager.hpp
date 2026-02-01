#pragma once
#include"System/Singleton/Singleton.hpp"
#include"entt/entt.hpp"

namespace System
{
	/// <summary>
	/// エンティティ管理
	/// </summary>
	class EntityManager : public Singleton<EntityManager>
	{
		GENERATE_SINGLETON_BODY(EntityManager);

	public:
		/// <summary>
		/// エンティティの生成
		/// </summary>
		/// <returns></returns>
		entt::entity CreateEntity();
		
		/// <summary>
		/// ローカルオブジェクトの作成
		/// </summary>
		/// <returns></returns>
		entt::entity CreateLocalEntity();

		/// <summary>
		/// Globalオブジェクトの生成
		/// </summary>
		/// <returns></returns>
		entt::entity CreateGlobalEntity();

		/// <summary>
		/// コンポーネントの追加
		/// </summary>
		/// <typeparam name="T">任意のコンポーネントの型/typeparam>
		/// <typeparam name="...Args">可変引数</typeparam>
		/// <param name="Entity">エンティティ</param>
		/// <param name="...Arg">引数</param>
		/// <returns>コンポーネントのインスタンスの参照</returns>
		template<typename T,typename... Args>
		T& AddComponent(entt::entity entity, Args&&... arg)
		{
			return mRegistry.emplace<T>(entity, std::forward<Args>(arg)...);
		}

		/// <summary>
		/// コンポーネントの取得
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="entity"></param>
		/// <returns></returns>
		template<typename T>
		T& GetComponent(entt::entity entity) {
			return mRegistry.get<T>(entity);
		}

		/// <summary>
		/// 全ての削除
		/// </summary>
		void AllClear();

		/// <summary>
		/// Localタグを持つオブジェクトの削除
		/// </summary>
		void ClearLocalEntitys();

		/// <summary>
		/// Globalタグを持つオブジェクトの削除
		/// </summary>
		void ClearGlobalEntitys();

		/// <summary>
		/// registryの参照取得
		/// </summary>
		/// <returns></returns>
		entt::registry& GetRegistry();
	private:
		/// <summary>
		/// EnTTのすべての管理
		/// </summary>
		entt::registry mRegistry;
	};
}

