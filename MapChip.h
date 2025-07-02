#pragma once
#include "Library/GameObject.h"
#include <vector>
#include "globals.h"
#include <map>


class MapChip :
    public GameObject
{
public:
	MapChip();
	~MapChip();
	void Update() override;
	void Draw() override;
	int GetHandle(int index) { return bgHandle[index]; } //ハンドルを取得する
	bool IsHold();//マップチップを持っているかどうか
	int  GetHoldImage(); //持ってるマップチップのハンドルを取得する
	int  GetChipIndex(int handle);
private:
	std::vector<int> bgHandle;
	std::map<int, int> HandleToIndex;

	std::vector<Rect> bgRects_;
	bool isUpdate_;
	bool isInMapChipArea_;
	Point selected_;//選択したマップチップの座標
	int selectedIndex_;//選択したマップチップのインデックス
	bool isHold_;
};

