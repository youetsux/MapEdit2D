#include "Stage.h"
#include "Input.h"
#include "ImGui/imgui.h"

namespace
{

}

Stage::Stage()
	: GameObject()
{
	mapChip_ = new MapChip(); //マップチップのインスタンスを作成
	mapEdit_ = new MapEdit(); //マップエディタのインスタンスを作成
	mousePos_.x = -10; //マウスの座標を初期化
	mousePos_.y = -10;//マウスの座標を初期化	
	isMouseDown_ = false; //マウスの状態を初期化
	isOldMouseDown_ = false; //マウスの状態を初期化
	isDragging_ = false;
}

Stage::~Stage()
{
}

void Stage::Update()
{
	isOldMouseDown_ = isMouseDown_;
	if (Input::IsButtonDown(MOUSE_INPUT_LEFT))
	{
		isMouseDown_ = true;
	}
	if (Input::IsButtonUp(MOUSE_INPUT_LEFT))
	{
		isMouseDown_ = false;
	}

	isDragging_ = isOldMouseDown_ && isMouseDown_;
	
	ImGui::Begin("config 1");
	if (isDragging_)
	{
		ImGui::Text("Dragging");
	}
	else
	{
		ImGui::Text("MouseUp");
	}
	//ImGui::Text("MouseMode %s", (isInMapChipArea_ ? "true" : "false"));
	//ImGui::Text("Dragging %s", (isDragging_ ? "true" : "false"));
	ImGui::End();

}

void Stage::Draw()
{

}


