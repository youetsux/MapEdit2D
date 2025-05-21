#include "Stage.h"
#include "Input.h"
#include "ImGui/imgui.h"

namespace
{

}

Stage::Stage()
	: GameObject()
{
	mapChip_ = new MapChip(); //�}�b�v�`�b�v�̃C���X�^���X���쐬
	mapEdit_ = new MapEdit(); //�}�b�v�G�f�B�^�̃C���X�^���X���쐬
	mousePos_.x = -10; //�}�E�X�̍��W��������
	mousePos_.y = -10;//�}�E�X�̍��W��������	
	isMouseDown_ = false; //�}�E�X�̏�Ԃ�������
	isOldMouseDown_ = false; //�}�E�X�̏�Ԃ�������
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


