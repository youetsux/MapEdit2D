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
	POINT mousePos_; //マウスの座標
	bool isMouseDown_; //マウスの状態;
	bool isOldMouseDown_; //1フレ前のマウスの状態
	bool isDragging_;
public:
	Stage();
	~Stage();
	void Update() override;
	void Draw() override;
};

//playsceneでstageクラスのインスタンスを作って、
//playsceneに、bg.pngが表示される
