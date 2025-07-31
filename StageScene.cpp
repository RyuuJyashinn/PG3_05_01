#include "StageScene.h"
#include"Novice.h"
void StageScene::Initialize() {
    inputHandler_ = new InputHandler();
    inputHandler_->AssignMoveLeftCommand2PressKeyD();
    inputHandler_->AssignMoveLeftCommand2PressKeyA();
    player_ = new Player();
    player_->Initialize();
}

void StageScene::Update(char* keys, char* preKeys) {
    // 示例：按空格键切换到 CLEAR 场景
    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
        TransitionTo(CLEAR);
    }

    iCommand_ = inputHandler_->HandleInput();
    if (iCommand_) iCommand_->Execute(*player_);
    player_->Update();
}

void StageScene::Draw() {
    player_->Draw();
}