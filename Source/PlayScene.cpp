#include "PlayScene.h"
#include <DxLib.h>
#include "../Stage.h"




PlayScene::PlayScene()
{
	new Stage(); // ステージのインスタンスを作成
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	//if (CheckHitKey(KEY_INPUT_T)) {
	//	SceneManager::ChangeScene("TITLE");
	//}
}

void PlayScene::Draw()
{
	//DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	//DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
