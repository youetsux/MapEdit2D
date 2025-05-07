#pragma once
#include "Library/GameObject.h"
#include <vector>
#include "MapChip.h"


class Stage :
    public GameObject
{
	//int *bgHandle; //�w�i�摜�̃n���h���̔z��ւ̃|�C���^�i�z�񎩑́j
	std::vector<int> bgHandle_; //�w�i�摜�̃n���h���̔z��ւ̃|�C���^�i�z�񎩑́j
	MapChip* mapChip_; //�}�b�v�`�b�v�̃|�C���^
public:
	Stage();
	~Stage();
	void Update() override;
	void Draw() override;
};

//playscene��stage�N���X�̃C���X�^���X������āA
//playscene�ɁAbg.png���\�������
