#include "Stage.h"
#include "Input.h"

namespace
{

}

Stage::Stage()
	: GameObject()
{
	mapChip_ = new MapChip(); //マップチップのインスタンスを作成
	mapEdit_ = new MapEdit(); //マップエディタのインスタンスを作成
	//mousePos_.x = -10; //マウスの座標を初期化
	//mousePos_.y = -10;//マウスの座標を初期化	
}

Stage::~Stage()
{
	//for (int i = 0;i < MAP_CHIP_WIDTH * MAP_CHIP_HEIGHT;i++) {
	//	if (bgHandle_[i] != -1) {
	//		DeleteGraph(bgHandle_[i]);
	//		bgHandle_[i] = -1;
	//	}
	//}
	//delete[] bgHandle; //配列の解放 自分で撮ったものは自分で消す
	delete mapChip_; //マップチップのインスタンスを解放
	//delete mapEdit_; //マップエディタのインスタンスを解放
}

void Stage::Update()
{
	//Point mousePos;
	//if (GetMousePoint(&mousePos.x, &mousePos.y) == -1) {
	//	return;
	//}
	
	//左上　mapEditRect_.x, mapEditRect_.y
	//右上　mapEditRect_.x + mapEditRect_.w, mapEditRect_.y
	//右下  mapEditRect_.x + mapEditRect_.w, mapEditRect_.y + mapEditRect_.h
	//左下  mapEditRect_.x, mapEditRect_.y + mapEditRect_.h
	//	// グリッド座標に変換
	//if (mapEdit_->IsInMapEditArea()) {
	//	return; //マップエディタ領域外なら何もしない
	//}

	//int gridX = (mousePos.x - LEFT_MARGIN) / MAP_IMAGE_SIZE;
	//int gridY = (mousePos.y - TOP_MARGIN) / MAP_IMAGE_SIZE;

	//drawAreaRect_ = { LEFT_MARGIN + gridX * MAP_IMAGE_SIZE, TOP_MARGIN + gridY * MAP_IMAGE_SIZE,
	//	MAP_IMAGE_SIZE, MAP_IMAGE_SIZE };
	//if (mapChip_->GetHoldImage() != -1) //マップチップを持っているなら
	//{
	//	//mapEdit_->SetMap(, mapChip_->GetHoldImage());
	//}

}

void Stage::Draw()
{

}


