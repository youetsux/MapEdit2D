#pragma once
#include "Library/GameObject.h"
#include <vector>
#include "globals.h"



class MapChip :
    public GameObject
{
public:
	MapChip();
	~MapChip();
	void Update() override;
	void Draw() override;
	int GetHandle(int index) { return bgHandle[index]; } //�n���h�����擾����
	bool IsHold();//�}�b�v�`�b�v�������Ă��邩�ǂ���
	int  GetHoldImage(); //�����Ă�}�b�v�`�b�v�̃n���h�����擾����
private:
	std::vector<int> bgHandle;
	std::vector<Rect> bgRects_;
	bool isUpdate_;
	bool isInMapChipArea_;
	Point selected_;//�I�������}�b�v�`�b�v�̍��W
	int selectedIndex_;//�I�������}�b�v�`�b�v�̃C���f�b�N�X
	bool isHold_;
};

