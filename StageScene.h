#pragma once
#include "InputHandler.h"
#include "Command.h"
#include "Player.h"
#include "IScene.h"

class StageScene : public IScene {
public:
    void Initialize() override;
    void Update(char* keys, char* preKeys) override;
    void Draw() override;
    ~StageScene() override {
        delete inputHandler_;
        delete player_;
    }
    void LoadResource();

private:
    InputHandler* inputHandler_ = nullptr;
    ICommand* iCommand_ = nullptr;
    Player* player_ = nullptr;
    int stageGraph_ = 0;
};