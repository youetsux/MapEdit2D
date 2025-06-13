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

	//if (Input::IsMouseDown()) {
	//	//マウスが押された瞬間の処理
	//	DxLib::printfDx("左押された！！：");
	//}
	//if (Input::IsButtonDown(MOUSE_INPUT_RIGHT)) {
	//	//マウスが押された瞬間の処理
	//	DxLib::printfDx("右押された！！：");
	//}
	//if (Input::IsButtonKeep(MOUSE_INPUT_LEFT)) {
	//	//マウスが押されている間の処理
	//	DxLib::printfDx("左押されている！！：");
	//}
	//if (Input::IsButtonKeep(MOUSE_INPUT_RIGHT)) {
	//	//マウスが押されている間の処理
	//	DxLib::printfDx("右押されている！！：");
	//}
	//if (Input::IsButtonUP(MOUSE_INPUT_LEFT)) {
	//	//マウスが離された瞬間の処理
	//	DxLib::printfDx("左離された！！：");
	//}
	//if (Input::IsButtonUP(MOUSE_INPUT_RIGHT)) {
	//	//マウスが離された瞬間の処理
	//	DxLib::printfDx("右離された！！：");
	//}
	//int mx=-1, my=-1;
	//if (GetMousePoint(&mx, &my) == 0)
	//{
	//	//マウスの座標を取得
	//	DxLib::printfDx("マウスの座標(%d,%d)\n", mx, my);
	//}
	//else {
	//	DxLib::printfDx("マウスの座標取得失敗\n");
	//}

}

void Stage::Draw()
{

}


