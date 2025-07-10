#pragma once
#include "Library/GameObject.h"
#include <vector>
#include "globals.h"
#include <map>
#include "MapChipConfig.h"

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
	int  GetChipIndex(int handle);
	Point GetViewOrigin() const;
	bool IsInChipArea(const Point& mouse) const;
	Point ScreenToChipIndex(const Point& mouse) const;

	MapChipConfig cfg_;//�}�b�v�`�b�v�̐ݒ��ێ�����
	std::vector<int> bgHandle;
	std::map<int, int> HandleToIndex;

	//std::vector<Rect> bgRects_;
	bool isUpdate_;
	bool isInMapChipArea_;
	Point selected_;//�I�������}�b�v�`�b�v�̍��W
	int selectedIndex_;//�I�������}�b�v�`�b�v�̃C���f�b�N�X
	bool isHold_;
	Point ScrollOffset_; //�X�N���[���I�t�Z�b�g
};

