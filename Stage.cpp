#include "Stage.h"
#include "Input.h"

namespace
{

}

Stage::Stage()
	: GameObject()
{
	mapChip_ = new MapChip(); //�}�b�v�`�b�v�̃C���X�^���X���쐬
	mapEdit_ = new MapEdit(); //�}�b�v�G�f�B�^�̃C���X�^���X���쐬
	//mousePos_.x = -10; //�}�E�X�̍��W��������
	//mousePos_.y = -10;//�}�E�X�̍��W��������	
}

Stage::~Stage()
{
	//for (int i = 0;i < MAP_CHIP_WIDTH * MAP_CHIP_HEIGHT;i++) {
	//	if (bgHandle_[i] != -1) {
	//		DeleteGraph(bgHandle_[i]);
	//		bgHandle_[i] = -1;
	//	}
	//}
	//delete[] bgHandle; //�z��̉�� �����ŎB�������͎̂����ŏ���
	delete mapChip_; //�}�b�v�`�b�v�̃C���X�^���X�����
	//delete mapEdit_; //�}�b�v�G�f�B�^�̃C���X�^���X�����
}

void Stage::Update()
{
	//Point mousePos;
	//if (GetMousePoint(&mousePos.x, &mousePos.y) == -1) {
	//	return;
	//}
	
	//����@mapEditRect_.x, mapEditRect_.y
	//�E��@mapEditRect_.x + mapEditRect_.w, mapEditRect_.y
	//�E��  mapEditRect_.x + mapEditRect_.w, mapEditRect_.y + mapEditRect_.h
	//����  mapEditRect_.x, mapEditRect_.y + mapEditRect_.h
	//	// �O���b�h���W�ɕϊ�
	//if (mapEdit_->IsInMapEditArea()) {
	//	return; //�}�b�v�G�f�B�^�̈�O�Ȃ牽�����Ȃ�
	//}

	//int gridX = (mousePos.x - LEFT_MARGIN) / MAP_IMAGE_SIZE;
	//int gridY = (mousePos.y - TOP_MARGIN) / MAP_IMAGE_SIZE;

	//drawAreaRect_ = { LEFT_MARGIN + gridX * MAP_IMAGE_SIZE, TOP_MARGIN + gridY * MAP_IMAGE_SIZE,
	//	MAP_IMAGE_SIZE, MAP_IMAGE_SIZE };
	//if (mapChip_->GetHoldImage() != -1) //�}�b�v�`�b�v�������Ă���Ȃ�
	//{
	//	//mapEdit_->SetMap(, mapChip_->GetHoldImage());
	//}

}

void Stage::Draw()
{

}


