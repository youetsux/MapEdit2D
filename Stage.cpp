#include "Stage.h"

namespace
{
	const int IMAGE_SIZE = { 32 }; // ‰æ‘œ‚ÌƒTƒCƒY
	const int MAP_WIDTH = { 10 };
	const int MAP_HEIGHT = { 10 };
	const int myMap[MAP_HEIGHT][MAP_WIDTH]
	{
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 }
	};
}

Stage::Stage()
	: GameObject(), bgHandle(-1)
{
	bgHandle = LoadGraph("./bg.png");
}

Stage::~Stage()
{
	if (bgHandle != -1) {
		DeleteGraph(bgHandle);
		bgHandle = -1;
	}
}

void Stage::Update()
{

}

void Stage::Draw()
{
	if (bgHandle != -1) {
		for (int j = 0;j < MAP_HEIGHT;j++) {
			for (int i = 0;i < MAP_WIDTH;i++) {

				 //DrawRectGraph(i*IMAGE_SIZE,j*IMAGE_SIZE,
				 //              kx, ky,IMAGE_SIZE,IMAGE_SIZE,
				 //              bgHandle, TRUE);
			}
		}
		//DrawGraph(0, 0, bgHandle, TRUE);
	}
}
