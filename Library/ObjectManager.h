#pragma once
/// <summary>
/// すべてのオブジェクトを管理します
/// ここからすべてのGameObjectのUpdate()/Draw()を呼び出します
/// </summary>
/// <author>N.Hanai</author>

#include <list>
#include <string>
class GameObject;

namespace ObjectManager
{
	void Init();
	void Update();
	void Draw();
	void Release();

	void Push(GameObject* obj);

	/// <summary>
	/// DrawOrderをもとに、Drawを呼ぶ順番を作り直します。
	/// </summary>
	void SortByDrawOrder();

	/// <summary>
	/// GameObjectを削除する
	/// </summary>
	/// <param name="obj">GameObjectのインスタンス</param>
	void Pop(GameObject* obj);

	/// <summary>
	/// 全てのGameObjectを削除する
	/// </summary>
	void DeleteAllGameObject();

	const std::list<GameObject*>& GetAllObject();
};

/// <summary>
/// クラス名でオブジェクトを探す
/// </summary>
/// <typeparam name="C">クラス</typeparam>
/// <returns>オブジェクトの実態（存在しなければnullptr）</returns>
template<class C> C* FindGameObject()
{
	const std::list<GameObject*>& objs = ObjectManager::GetAllObject();
	for (GameObject* node : objs)
	{
		C* obj = dynamic_cast<C*>(node);
		if (obj != nullptr)
			return obj;
	}
	return nullptr;
}

/// <summary>
/// クラスのオブジェクトをすべて探す
/// </summary>
/// <typeparam name="C">クラス名</typeparam>
/// <returns>オブジェクトの実態list</returns>
template<class C> std::list<C*> FindGameObjects()
{
	std::list<C*> out;
	out.clear();

	const std::list<GameObject*>& objs = ObjectManager::GetAllObject();

	for (GameObject* node : objs)
	{
		C* obj = dynamic_cast<C*>(node);
		if (obj != nullptr)
			out.emplace_back(obj);
	}
	return out;
}

/// <summary>
/// クラス名とタグからオブジェクトを探す
/// </summary>
/// <typeparam name="C">クラス名</typeparam>
/// <param name="tag">タグ</param>
/// <returns>オブジェクトの実態（存在しなければnullptr）</returns>
template<class C> C* FindGameObjectWithTag(std::string tag)
{
	const std::list<GameObject*> objs = ObjectManager::GetAllObject();

	for (GameObject* node : objs)
	{
		C* obj = dynamic_cast<C*>(node);
		if (obj != nullptr)
		{
			if (obj->IsTag(tag))
				return obj;
		}
	}
	return nullptr;
}

/// <summary>
/// クラス名とタグからオブジェクトをすべて探す
/// </summary>
/// <typeparam name="C">クラス名</typeparam>
/// <param name="tag">タグ</param>
/// <returns>オブジェクトの実態list</returns>
template<class C> std::list<C*> FindGameObjectsWithTag(std::string tag)
{
	std::list<C*> out;
	out.clear();

	const std::list<GameObject*> objs = ObjectManager::GetAllObject();

	for (GameObject* node : objs)
	{
		C* obj = dynamic_cast<C*>(node);
		if (obj != nullptr)
		{
			if (obj->IsTag(tag))
				out.emplace_back(obj);
		}
	}
	return out;
}
