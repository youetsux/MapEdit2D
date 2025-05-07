#pragma once

//https://inemaru.hatenablog.com/entry/2018/05/10/031815
namespace Input {
	//�L�[�{�[�h�擾�֘A
	void KeyStateUpdate();
	bool IsKeyUP(int keyCode);
	bool IsKeyDown(int keyCode);
	int IsKeepKeyDown(int keyCode);

	bool IsMouseDown();
	int GetMouseX();
	int GetMouseY();
	
}