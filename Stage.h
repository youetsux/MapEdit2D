#pragma once
#include "Library/GameObject.h"

class Stage :
    public GameObject
{
	int bgHandle; //�w�i�摜�̃n���h��
public:
	Stage();
	~Stage();
	void Update() override;
	void Draw() override;
};

//playscene��stage�N���X�̃C���X�^���X������āA
//playscene�ɁAbg.png���\�������
