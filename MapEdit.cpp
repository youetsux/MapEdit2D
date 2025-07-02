#include "MapEdit.h"
#include <cassert>
#include "Input.h"
#include "DxLib.h"
#include "MapChip.h"
#include <fstream>


MapEdit::MapEdit()
	:GameObject(), myMap_(MAP_WIDTH* MAP_HEIGHT, -1), //初期値を-1で20*20の配列を初期化する
	 isInMapEditArea_(false) //マップエディタ領域内にいるかどうか
{
	mapEditRect_ = { LEFT_MARGIN, TOP_MARGIN,
		MAP_WIDTH * MAP_IMAGE_SIZE, MAP_HEIGHT * MAP_IMAGE_SIZE };
}

MapEdit::~MapEdit()
{
}

void MapEdit::SetMap(Point p, int value)
{
	//マップの座標pにvalueをセットする
	//pが、配列の範囲外の時はassertにひっかかる
	assert(p.x >= 0 && p.x < MAP_WIDTH);
	assert(p.y >= 0 && p.y < MAP_HEIGHT);
	myMap_[p.y * MAP_WIDTH + p.x] = value; //y行x列にvalueをセットする

}

int MapEdit::GetMap(Point p) const
{
	//マップの座標pの値を取得する
	//pが、配列の範囲外の時はassertにひっかかる
	assert(p.x >= 0 && p.x < MAP_WIDTH);
	assert(p.y >= 0 && p.y < MAP_HEIGHT);
	return myMap_[p.y * MAP_WIDTH + p.x]; //y行x列の値を取得する

}

void MapEdit::Update()
{
	Point mousePos;
	if (GetMousePoint(&mousePos.x, &mousePos.y) == -1) {
		return;
	}
	// マウスの座標がマップエディタ領域内にいるかどうかを判定する
	isInMapEditArea_ = mousePos.x >= mapEditRect_.x && mousePos.x <= mapEditRect_.x + mapEditRect_.w &&
		mousePos.y >= mapEditRect_.y && mousePos.y <= mapEditRect_.y + mapEditRect_.h;

	//左上　mapEditRect_.x, mapEditRect_.y
	//右上　mapEditRect_.x + mapEditRect_.w, mapEditRect_.y
	//右下  mapEditRect_.x + mapEditRect_.w, mapEditRect_.y + mapEditRect_.h
	//左下  mapEditRect_.x, mapEditRect_.y + mapEditRect_.h
		// グリッド座標に変換
	if (!isInMapEditArea_) {
		return; //マップエディタ領域外なら何もしない
	}

	int gridX = (mousePos.x - LEFT_MARGIN) / MAP_IMAGE_SIZE;
	int gridY = (mousePos.y - TOP_MARGIN) / MAP_IMAGE_SIZE;

	drawAreaRect_ = { LEFT_MARGIN + gridX * MAP_IMAGE_SIZE, TOP_MARGIN + gridY * MAP_IMAGE_SIZE,
		MAP_IMAGE_SIZE, MAP_IMAGE_SIZE };

	//マウスのボタンが押されたら、持ってる画像をその座標に貼る
	//if (Input::IsButtonDown(MOUSE_INPUT_LEFT)) //左クリックでマップに値をセット
	//{
	//	MapChip* mapChip = FindGameObject<MapChip>();

	//	if (CheckHitKey(KEY_INPUT_LSHIFT)) //Rキーを押しているなら
	//	{
	//		SetMap({ gridX, gridY }, -1); //マップに値をセット（-1は何もない状態）
	//		return; //マップチップを削除したらここで終了
	//	}
	//	else if (mapChip && mapChip->IsHold()) //マップチップを持っているなら
	//	{
	//		SetMap({ gridX, gridY }, mapChip->GetHoldImage()); //マップに値をセット
	//	}
	//}

	if (Input::IsButtonKeep(MOUSE_INPUT_LEFT)) //左クリックでマップに値をセット
	{
		MapChip* mapChip = FindGameObject<MapChip>();
		
		if (CheckHitKey(KEY_INPUT_LSHIFT)) //Rキーを押しているなら
		{
			SetMap({ gridX, gridY }, -1); //マップに値をセット（-1は何もない状態）
			return; //マップチップを削除したらここで終了
		}
		else if (mapChip && mapChip->IsHold()) //マップチップを持っているなら
		{
			SetMap({ gridX, gridY }, mapChip->GetHoldImage()); //マップに値をセット
		}
	}
	if (Input::IsKeyDown(KEY_INPUT_S))
	{
		SaveMapData();
	}
}

void MapEdit::Draw()
{//背景を描画する

	for (int j = 0;j < MAP_HEIGHT;j++)
	{
		for (int i = 0; i < MAP_WIDTH; i++)
		{
			int value = GetMap({ i,j });
			if (value != -1) //-1なら何も描画しない
			{
				DrawGraph(LEFT_MARGIN + i * MAP_IMAGE_SIZE, TOP_MARGIN + j * MAP_IMAGE_SIZE,
					value, TRUE);
			}
		}
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBox(LEFT_MARGIN + 0, TOP_MARGIN + 0,
		LEFT_MARGIN + MAP_WIDTH * MAP_IMAGE_SIZE, TOP_MARGIN + MAP_HEIGHT * MAP_IMAGE_SIZE,GetColor(255, 255, 0), FALSE, 5);
	for (int j = 0; j < MAP_HEIGHT; j++) {
		for (int i = 0; i < MAP_WIDTH; i++) {
			DrawLine(LEFT_MARGIN + i * MAP_IMAGE_SIZE, TOP_MARGIN + j * MAP_IMAGE_SIZE,
				LEFT_MARGIN + (i + 1) * MAP_IMAGE_SIZE, TOP_MARGIN + j * MAP_IMAGE_SIZE, GetColor(255, 255, 255), 1);
			DrawLine(LEFT_MARGIN + i * MAP_IMAGE_SIZE, TOP_MARGIN + j * MAP_IMAGE_SIZE,
				LEFT_MARGIN + i * MAP_IMAGE_SIZE, TOP_MARGIN + (j + 1) * MAP_IMAGE_SIZE, GetColor(255, 255, 255),  1);
		}
	}
	if (isInMapEditArea_) {

		DrawBox(drawAreaRect_.x, drawAreaRect_.y,
			drawAreaRect_.x + drawAreaRect_.w, drawAreaRect_.y + drawAreaRect_.h,
			GetColor(255, 255, 0), TRUE);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	

}

void MapEdit::SaveMapData()
{
	printfDx("File Saved!!!\n");

	std::ofstream file("data.dat");
	MapChip* mc = FindGameObject<MapChip>();

	for (int j = 0; j < MAP_HEIGHT; j++) {
		for (int i = 0; i < MAP_WIDTH; i++) {

			int index = mc->GetChipIndex(myMap_[j * MAP_WIDTH + i]);
			file << index << " ";
		}
		file << std::endl;
	}

	file.close();

}
