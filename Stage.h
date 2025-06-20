#pragma once
#include "Library/GameObject.h"
#include <vector>
#include "MapChip.h"
#include "MapEdit.h"


class Stage :
    public GameObject
{
public:
	Stage();
	~Stage();
	void Update() override;
	void Draw() override;
private:
	//int *bgHandle; //背景画像のハンドルの配列へのポインタ（配列自体）
	//std::vector<int> bgHandle_; //背景画像のハンドルの配列へのポインタ（配列自体）
	MapChip* mapChip_; //マップチップのポインタ
	MapEdit* mapEdit_; //マップエディタのポインタ

	//Rect drawAreaRect_;
};

//playsceneでstageクラスのインスタンスを作って、
//playsceneに、bg.pngが表示される
