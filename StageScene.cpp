#include "StageScene.h"
#include"Novice.h"
void StageScene::Initialize() {
    inputHandler_ = new InputHandler();
    inputHandler_->AssignMoveRightCommand2PressKeyD();
    inputHandler_->AssignMoveLeftCommand2PressKeyA();
    inputHandler_->AssignMoveUpCommand2PressKeyW();
    inputHandler_->AssignMoveDownCommand2PressKeyS();

    player_ = new Player();
    player_->Initialize();
    LoadResource();
}

void StageScene::Update(char* keys, char* preKeys) {
    // 示例：按空格键切换到 CLEAR 场景
    if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
        TransitionTo(CLEAR);
    }

    iCommand_ = inputHandler_->HandleInput();
    if (iCommand_) iCommand_->Execute(*player_);
    player_->Update();

    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
        player_->FireBullets();
    }
    player_->UpdateBullets();
}

void StageScene::Draw() {
 
    Novice::DrawSprite(0, 0, stageGraph_, 1.0f, 1.0f, 0.0f, WHITE);

    player_->Draw();
    player_->DrawBullets();
}

void StageScene::LoadResource() {


    stageGraph_ = Novice::LoadTexture("./images/ui/room.png");
}