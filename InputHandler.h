#pragma once
#include "Command.h"

//入力管理クラス
class InputHandler {
private:
	// 入力A
	ICommand* pressKeyA_;

	// 入力D
	ICommand* pressKeyD_;

public:
	ICommand* HandleInput();

	//Aキー押されて左移動コマンド発生
	void AssignMoveLeftCommand2PressKeyA();

	//Dキー押されて右移動コマンド発生
	void AssignMoveLeftCommand2PressKeyD();
};