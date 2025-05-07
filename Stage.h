#pragma once
#include "Library/GameObject.h"
#include "vector"

class Stage :
    public GameObject
{
	std::vector<int> bgHandle; //背景画像のハンドル
public:
	Stage();
	~Stage();
	void Update() override;
	void Draw() override;
};

//playsceneでstageクラスのインスタンスを作って、
//playsceneに、bg.pngが表示される
