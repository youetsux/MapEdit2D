#pragma once
#include "Library\GameObject.h"
#include <vector>

namespace
{
	const int MAP_WIDTH = { 20 };
	const int MAP_HEIGHT = { 20 };
	const int MAP_IMAGE_SIZE = { 32 }; // �摜�̃T�C�Y
}



class MapEdit :
    public GameObject
{
	std::vector<int> myMap; //�}�b�v�̔z��
public:
	MapEdit();
	~MapEdit();
	void Update() override;
	void Draw() override;
};

