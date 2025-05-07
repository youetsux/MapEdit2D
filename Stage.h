#pragma once
#include "Library/GameObject.h"
#include <vector>
#include "MapChip.h"
#include "MapEdit.h"


class Stage :
    public GameObject
{
	//int *bgHandle; //背景画像のハンドルの配列へのポインタ（配列自体）
	//std::vector<int> bgHandle_; //背景画像のハンドルの配列へのポインタ（配列自体）
	MapChip* mapChip_; //マップチップのポインタ
	MapEdit* mapEdit_; //マップエディタのポインタ
public:
	Stage();
	~Stage();
	void Update() override;
	void Draw() override;
};

//playsceneでstageクラスのインスタンスを作って、
//playsceneに、bg.pngが表示される
