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

	//if (Input::IsMouseDown()) {
	//	//�}�E�X�������ꂽ�u�Ԃ̏���
	//	DxLib::printfDx("�������ꂽ�I�I�F");
	//}
	//if (Input::IsButtonDown(MOUSE_INPUT_RIGHT)) {
	//	//�}�E�X�������ꂽ�u�Ԃ̏���
	//	DxLib::printfDx("�E�����ꂽ�I�I�F");
	//}
	//if (Input::IsButtonKeep(MOUSE_INPUT_LEFT)) {
	//	//�}�E�X��������Ă���Ԃ̏���
	//	DxLib::printfDx("��������Ă���I�I�F");
	//}
	//if (Input::IsButtonKeep(MOUSE_INPUT_RIGHT)) {
	//	//�}�E�X��������Ă���Ԃ̏���
	//	DxLib::printfDx("�E������Ă���I�I�F");
	//}
	//if (Input::IsButtonUP(MOUSE_INPUT_LEFT)) {
	//	//�}�E�X�������ꂽ�u�Ԃ̏���
	//	DxLib::printfDx("�������ꂽ�I�I�F");
	//}
	//if (Input::IsButtonUP(MOUSE_INPUT_RIGHT)) {
	//	//�}�E�X�������ꂽ�u�Ԃ̏���
	//	DxLib::printfDx("�E�����ꂽ�I�I�F");
	//}
	//int mx=-1, my=-1;
	//if (GetMousePoint(&mx, &my) == 0)
	//{
	//	//�}�E�X�̍��W���擾
	//	DxLib::printfDx("�}�E�X�̍��W(%d,%d)\n", mx, my);
	//}
	//else {
	//	DxLib::printfDx("�}�E�X�̍��W�擾���s\n");
	//}

}

void Stage::Draw()
{

}


