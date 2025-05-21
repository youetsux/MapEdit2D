#pragma once
#include "Library/GameObject.h"
#include <vector>
#include "MapChip.h"
#include "MapEdit.h"


class Stage :
    public GameObject
{
	//int *bgHandle; //�w�i�摜�̃n���h���̔z��ւ̃|�C���^�i�z�񎩑́j
	//std::vector<int> bgHandle_; //�w�i�摜�̃n���h���̔z��ւ̃|�C���^�i�z�񎩑́j
	MapChip* mapChip_; //�}�b�v�`�b�v�̃|�C���^
	MapEdit* mapEdit_; //�}�b�v�G�f�B�^�̃|�C���^
	POINT mousePos_; //�}�E�X�̍��W
	bool isMouseDown_; //�}�E�X�̏��;
	bool isOldMouseDown_; //1�t���O�̃}�E�X�̏��
	bool isDragging_;
public:
	Stage();
	~Stage();
	void Update() override;
	void Draw() override;
};

//playscene��stage�N���X�̃C���X�^���X������āA
//playscene�ɁAbg.png���\�������
