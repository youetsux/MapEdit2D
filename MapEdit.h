#pragma once
#include "Library\GameObject.h"
#include <vector>

namespace
{
	const int MAP_WIDTH = { 20 };
	const int MAP_HEIGHT = { 20 };
	const int MAP_IMAGE_SIZE = { 32 }; // 画像のサイズ
	const int LEFT_MARGIN = { 100 };
	const int TOP_MARGIN = { 40 };
}



class MapEdit :
    public GameObject
{
	std::vector<int> myMap_; //マップの配列
public:
	MapEdit();
	~MapEdit();
	void Update() override;
	void Draw() override;
};

