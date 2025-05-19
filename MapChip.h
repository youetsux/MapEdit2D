#pragma once
#include "Library/GameObject.h"
#include <vector>

struct Point
{
	int x;
	int y;
};
struct Rect
{
	int x, y;
	int w, h;
};


class MapChip :
    public GameObject
{
	std::vector<int> bgHandle;
	std::vector<Rect> bgRects_;
	bool isUpdate_;
	bool isInMapChipArea_;
	Point selected_;
public:
	MapChip();
	~MapChip();
	void Update() override;
	void Draw() override;
	int GetHandle(int index) { return bgHandle[index]; } //ƒnƒ“ƒhƒ‹‚ðŽæ“¾‚·‚é
};

