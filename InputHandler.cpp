#include "InputHandler.h"
#include <Novice.h>

ICommand* InputHandler::HandleInput() {

	if (Novice::CheckHitKey(DIK_A)) {
		return pressKeyA_;
	}

	if (Novice::CheckHitKey(DIK_D)) {
		return pressKeyD_;
	}


	if (Novice::CheckHitKey(DIK_W)) {
		return pressKeyW_;
	}

	if (Novice::CheckHitKey(DIK_S)) {
		return pressKeyS_;
	}

	return nullptr;
}



//Aキー押されて左移動コマンド発生
void InputHandler::AssignMoveLeftCommand2PressKeyA() {

	ICommand* command = new MoveLeftCommand();
	this->pressKeyA_ = command;
}

//Dキー押されて右移動コマンド発生
void InputHandler::AssignMoveRightCommand2PressKeyD() {

	ICommand* command = new MoveRightCommand();
	this->pressKeyD_ = command;
}


void InputHandler::AssignMoveUpCommand2PressKeyW() {

	ICommand* command = new MoveUpCommand();
	this->pressKeyW_ = command;
}

void InputHandler::AssignMoveDownCommand2PressKeyS() {

	ICommand* command = new MoveDownCommand();
	this->pressKeyS_ = command;
}


