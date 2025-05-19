#include "MapChip.h"
#include "Source\Screen.h"
#include "Input.h"
#include "ImGui/imgui.h"

namespace
{
	//�������O�̕ϐ��͂��Ƃł܂Ƃ߂܂��傤
	const int IMAGE_SIZE = { 32 }; // �摜�̃T�C�Y
	const int MAP_CHIP_WIDTH = { 16 };//�`�b�v�̉����ѐ�
	const int MAP_CHIP_HEIGHT = { 12 };//�`�b�v�̏c���ѐ�
	const int MAP_CHIP_NUM_X = { 8 };//�}�b�v�`�b�v�E�B���h�E�̉����ѐ�
	const int MAP_CHIP_NUM_Y = { 24 };//�}�b�v�`�b�v�E�B���h�E�̏c���ѐ�
	const int MAP_CHIP_WIN_WIDTH = { IMAGE_SIZE * MAP_CHIP_NUM_X };//�E�B���h�E�̉���
	const int MAP_CHIP_WIN_HEIGHT = { IMAGE_SIZE * MAP_CHIP_NUM_Y };//�E�B���h�E�̏c��

	// �h���b�O�J�n�Ɣ��肷��ړ��ʂ�臒l
	const int DRAG_THRESHOLD = 5;
}

MapChip::MapChip()
	: GameObject(), isUpdate_(false), isInMapChipArea_(false), selectedIndex_(-1)
	, bgHandle(MAP_CHIP_WIDTH* MAP_CHIP_HEIGHT, -1), selected_({ 0,0 }) //�����l��-1��16*12�̔z�������������
{
	LoadDivGraph("./bg.png", MAP_CHIP_WIDTH * MAP_CHIP_HEIGHT,
		MAP_CHIP_WIDTH, MAP_CHIP_HEIGHT,
		IMAGE_SIZE, IMAGE_SIZE, bgHandle.data());
	for (int i = 0; i < MAP_CHIP_NUM_X; i++) {
		for (int j = 0; j < MAP_CHIP_NUM_Y; j++) {
			Rect tmp{
				i * IMAGE_SIZE, j * IMAGE_SIZE,
				IMAGE_SIZE, IMAGE_SIZE
			};
			bgRects_.push_back(tmp);
		}
	}
}


MapChip::~MapChip()
{
	for (int i = 0;i < MAP_CHIP_WIDTH * MAP_CHIP_HEIGHT;i++) {
		if (bgHandle[i] != -1) {
			DeleteGraph(bgHandle[i]);
			bgHandle[i] = -1;
		}
	}
}

void MapChip::Update()
{
	Point mousePos;
	if (GetMousePoint(&mousePos.x, &mousePos.y) == -1) {
		return;
	}

	isInMapChipArea_ = (mousePos.x > Screen::WIDTH - MAP_CHIP_WIN_WIDTH && mousePos.x < Screen::WIDTH &&
		mousePos.y > 0 && mousePos.y < MAP_CHIP_WIN_HEIGHT);


	if (isInMapChipArea_) {
		selected_.x = (mousePos.x - (Screen::WIDTH - MAP_CHIP_WIN_WIDTH)) / IMAGE_SIZE;
		selected_.y = mousePos.y / IMAGE_SIZE;
	}
	else
	{
		isInMapChipArea_ = false;
	}

	ImGui::Begin("config 1");

	ImGui::Text("MouseMode %s", (isInMapChipArea_ ? "true" : "false"));
	//ImGui::Text("Dragging %s", (isDragging_ ? "true" : "false"));
	ImGui::End();
}

void MapChip::Draw()
{
	int TOPLEFT_X = Screen::WIDTH - MAP_CHIP_WIN_WIDTH;
	int TOPLEFT_Y = 0;
	int RIGHTBOTTOM_X = Screen::WIDTH;
	int RIGHTBOTTOM_Y = MAP_CHIP_WIN_HEIGHT;

	for (int i = 0; i < MAP_CHIP_NUM_X; i++) {
		for (int j = 0; j < MAP_CHIP_NUM_Y; j++) {
			DrawGraph(TOPLEFT_X + i * IMAGE_SIZE, TOPLEFT_Y + j * IMAGE_SIZE,
				bgHandle[i + j * MAP_CHIP_NUM_X], TRUE);

		}
	}

	if (isInMapChipArea_)
	{
		int xM = Screen::WIDTH - MAP_CHIP_WIN_WIDTH;
		DrawBox(xM + selected_.x * IMAGE_SIZE, selected_.y * IMAGE_SIZE,
			xM + (selected_.x + 1) * IMAGE_SIZE, (selected_.y + 1) * IMAGE_SIZE,
			GetColor(255, 0, 0), FALSE, 2);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
		DrawBox(xM + selected_.x * IMAGE_SIZE + 1, selected_.y * IMAGE_SIZE - 1,
			xM + (selected_.x + 1) * IMAGE_SIZE - 1, (selected_.y + 1) * IMAGE_SIZE + 1,
			GetColor(255, 255, 0), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);

	}

}
