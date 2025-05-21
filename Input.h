#pragma once


namespace Input {
	//キーボード取得関連
	void KeyStateUpdate(); //キーの状態を毎フレーム更新する
	bool IsKeyUP(int keyCode);	//離した瞬間
	bool IsKeyDown(int keyCode); //押した瞬間
	int IsKeepKeyDown(int keyCode); //押している間

	bool IsMouseDown(); //マウスのボタンが押された瞬間
	bool IsMouseUP(); //マウスのボタンが離された瞬間
	bool IsMouseKeep(); //マウスのボタンが押されている間
	bool IsButtonDown(int button); //ボタンが押された瞬間
	bool IsButtonUP(int button); //ボタンが離された瞬間
	bool IsButtonKeep(int button); //ボタンが押されている間
}

//MOUSE_INPUT_LEFT   => 0x0001 
//MOUSE_INPUT_MIDDLE => 0x0004
//MOUSE_INPUT_RIGHT  => 0x0002