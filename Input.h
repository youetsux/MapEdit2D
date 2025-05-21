#pragma once


namespace Input {
	//�L�[�{�[�h�擾�֘A
	void KeyStateUpdate(); //�L�[�̏�Ԃ𖈃t���[���X�V����
	bool IsKeyUP(int keyCode);	//�������u��
	bool IsKeyDown(int keyCode); //�������u��
	int IsKeepKeyDown(int keyCode); //�����Ă����

	bool IsMouseDown(); //�}�E�X�̃{�^���������ꂽ�u��
	bool IsMouseUP(); //�}�E�X�̃{�^���������ꂽ�u��
	bool IsMouseKeep(); //�}�E�X�̃{�^����������Ă����
	bool IsButtonDown(int button); //�{�^���������ꂽ�u��
	bool IsButtonUP(int button); //�{�^���������ꂽ�u��
	bool IsButtonKeep(int button); //�{�^����������Ă����
}

//MOUSE_INPUT_LEFT   => 0x0001 
//MOUSE_INPUT_MIDDLE => 0x0004
//MOUSE_INPUT_RIGHT  => 0x0002