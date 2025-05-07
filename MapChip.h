#pragma once
#include "Library/GameObject.h"
#include <vector>

class MapChip :
    public GameObject
{
	std::vector<int> bgHandle;
public:
	MapChip();
	~MapChip();
	void Update() override;
	void Draw() override;
	int GetHandle(int index) { return bgHandle[index]; } //ƒnƒ“ƒhƒ‹‚ðŽæ“¾‚·‚é
};

