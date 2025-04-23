#include "SceneManager.h"
#include "SceneBase.h"
#include "../Source/SceneFactory.h"
#include <DxLib.h>

namespace
{
	std::string* currentName; // 現在のシーンの名称
	std::string* nextName;    // 次のシーンの名称
	SceneBase* currentScene; // 今のシーンのインスタンスを保持
	SceneFactory* factory;   // シーン切り替え用のFactoryのポインター
	bool exitRequest;
};

void SceneManager::Init()
{
	currentName = new std::string;
	nextName = new std::string;
	*nextName = "";
	*currentName = "";

	factory = new SceneFactory();
	// 最初に動くシーンを、SceneFactoryに作ってもらう
	currentScene = factory->CreateFirst();
	exitRequest = false;
}

void SceneManager::Update()
{
	if (*nextName != *currentName)
	{ // シーン切り替えの指定があったので
		if (currentScene != nullptr)
		{ // 今までのシーンを解放
			ObjectManager::DeleteAllGameObject();
			delete currentScene;
			currentScene = nullptr;
		}
		currentScene = factory->Create(*nextName); // 次のシーンを作成
		*currentName = *nextName;
	}
	if (currentScene != nullptr)
		currentScene->Update();
}

void SceneManager::Draw()
{
	if (currentScene != nullptr)
		currentScene->Draw();
}

void SceneManager::Release()
{
	if (currentScene != nullptr)
	{
		delete currentScene;
		currentScene = nullptr;
	}
	if (factory != nullptr) {
		delete factory;
		factory = nullptr;
	}
	delete currentName;
	delete nextName;
}

void SceneManager::ChangeScene(const std::string& sceneName)
{
	*nextName = sceneName;
}

void SceneManager::Exit()
{
	exitRequest = true;
}

bool SceneManager::IsExit()
{
	return exitRequest;
}
