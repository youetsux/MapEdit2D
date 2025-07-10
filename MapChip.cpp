#include "MapChip.h"
#include "globals.h"
#include "Source\Screen.h"
#include "Input.h"
#include "ImGui/imgui.h"


namespace
{
	////�������O�̕ϐ��͂��Ƃł܂Ƃ߂܂��傤
	//const int IMAGE_SIZE = { 32 }; // �摜�̃T�C�Y
	//const int MAP_CHIP_WIDTH = { 16 };//�`�b�v�̉����ѐ�
	//const int MAP_CHIP_HEIGHT = { 12 };//�`�b�v�̏c���ѐ�
	//const int MAP_CHIP_NUM_X = { 8 };//�}�b�v�`�b�v�E�B���h�E�̉����ѐ�
	//const int MAP_CHIP_NUM_Y = { 24 };//�}�b�v�`�b�v�E�B���h�E�̏c���ѐ�
	//const int MAP_CHIP_WIN_WIDTH = { IMAGE_SIZE * MAP_CHIP_NUM_X };//�E�B���h�E�̉���
	//const int MAP_CHIP_WIN_HEIGHT = { IMAGE_SIZE * MAP_CHIP_NUM_Y };//�E�B���h�E�̏c��

}

MapChip::MapChip()
	: GameObject(), isUpdate_(false), isInMapChipArea_(false), selectedIndex_(-1)
	, cfg_(GetMapChipConfig()), selected_({ 0,0 }) //�����l��-1��16*12�̔z�������������
{


	bgHandle.resize(cfg_.TILE_PIX_SIZE * cfg_.TILES_X * cfg_.TILES_Y, -1);


	LoadDivGraph("./bg.png", cfg_.TILES_X * cfg_.TILES_Y,
		cfg_.TILES_X, cfg_.TILES_Y,
		cfg_.TILE_PIX_SIZE, cfg_.TILE_PIX_SIZE, bgHandle.data());


	//LUT(Look Up Table) �쐬
	for (int i = 0; i < bgHandle.size();i++)
	{
		HandleToIndex[bgHandle[i]] = i;
	}
}


MapChip::~MapChip()
{
	for (int i = 0;i < cfg_.TILES_X * cfg_.TILES_Y;i++) {
		if (bgHandle[i] != -1) {
			DeleteGraph(bgHandle[i]);
			bgHandle[i] = -1;
		}
	}
}

Point MapChip::GetViewOrigin() const {
	return { Screen::WIDTH - cfg_.MAPCHIP_WIN_WIDTH,0 };
}

bool MapChip::IsInChipArea(const Point& mouse) const
{
	return (mouse.x >= GetViewOrigin().x &&
		mouse.x < Screen::WIDTH &&
		mouse.y >= 0 &&
		mouse.y < cfg_.MAPCHIP_WIN_HEIGHT);
}

Point MapChip::ScreenToChipIndex(const Point& mouse) const
{
	int localX = (mouse.x - GetViewOrigin().x) / cfg_.TILE_PIX_SIZE;
	int localY = mouse.y / cfg_.TILE_PIX_SIZE;
	return { localX, localY };
}

void MapChip::Update()
{

	Point mousePos;
	if (GetMousePoint(&mousePos.x, &mousePos.y) == -1) return;


	isInMapChipArea_ = IsInChipArea(mousePos);


	if (isInMapChipArea_) {
		//�}�E�X�̍��W���}�b�v�`�b�v�̃C���f�b�N�X�ɕϊ�
		selected_ = ScreenToChipIndex(mousePos);


		int index = selected_.y * cfg_.TILES_X + selected_.x;

		//�}�E�X�̍��W���}�b�v�`�b�v�͈͓̔��ɂ��邩�ǂ������`�F�b�N
		if (index >= 0 && index < bgHandle.size() && Input::IsButtonDown(MOUSE_INPUT_LEFT)) {
			selectedIndex_ = bgHandle[index];
			isHold_ = true;
		}
	}
	else {
		isInMapChipArea_ = false;
	}


}

void MapChip::Draw()
{
	const int originX = GetViewOrigin().x;
	const int originY = GetViewOrigin().y;

	// �`�b�v�\��
	for (int y = 0; y < cfg_.TILES_Y; y++) {
		for (int x = 0; x < cfg_.TILES_X; x++) {
			int index = y * cfg_.TILES_X + x;
			DrawGraph(originX + x * cfg_.TILE_PIX_SIZE,
				originY + y * cfg_.TILE_PIX_SIZE,
				bgHandle[index], TRUE);
		}
	}


	// �n�C���C�g�`��
	if (isInMapChipArea_) {
		int x = originX + selected_.x * cfg_.TILE_PIX_SIZE;
		int y = selected_.y * cfg_.TILE_PIX_SIZE;
		int size = cfg_.TILE_PIX_SIZE;

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
		DrawBox(x + 1, y - 1, x + size - 1, y + size + 1, GetColor(255, 255, 0), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawBox(x, y, x + size, y + size, GetColor(255, 0, 0), FALSE, 2);
	}


	// �z�[���h���`�b�v�̕`��
	if (isHold_) {
		Point mousePos;
		if (GetMousePoint(&mousePos.x, &mousePos.y) != -1) {
			DrawExtendGraph(mousePos.x, mousePos.y,
				mousePos.x + cfg_.TILE_PIX_SIZE,
				mousePos.y + cfg_.TILE_PIX_SIZE,
				selectedIndex_, TRUE);
		}
		if (Input::IsButtonUP(MOUSE_INPUT_RIGHT)) {
			isHold_ = false;
			selectedIndex_ = -1;
		}
	}

}

bool MapChip::IsHold()
{
	return isHold_;
}

int MapChip::GetHoldImage()
{
	if (isHold_)
	{
		return selectedIndex_;
	}
	else
	{
		return -1; //�����Ă��Ȃ��ꍇ��-1��Ԃ�
	}
}

int MapChip::GetChipIndex(int handle)
{

	return HandleToIndex[handle];

	//for (int i = 0;i < bgHandle.size();i++)
	//{
	//	if (handle == bgHandle[i])
	//		return i;
	//}
	//int a = HandleToIndex[handle];
	//if(HandleToIndex[handle])

}
