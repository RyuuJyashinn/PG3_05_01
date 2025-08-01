#pragma once
#include "Command.h"
#include <vector>
#include <thread>
//入力管理クラス
class InputHandler {
private:
	// 入力A
	ICommand* pressKeyA_;

	// 入力D
	ICommand* pressKeyD_;

	ICommand* pressKeyW_;

	// 入力D
	ICommand* pressKeyS_;

public:
	ICommand* HandleInput();

	//Aキー押されて左移動コマンド発生
	void AssignMoveLeftCommand2PressKeyA();

	//Dキー押されて右移動コマンド発生
	void AssignMoveRightCommand2PressKeyD();


	//Wキー押されて左移動コマンド発生
	void AssignMoveUpCommand2PressKeyW();

	//sキー押されて右移動コマンド発生
	void AssignMoveDownCommand2PressKeyS();
	// InputHandler.h
};