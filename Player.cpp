#include "Player.h"
#include <Novice.h>

//初期化
void Player::Initialize() {
	position_ = { 200.0f,200.0f };
}

//更新
void Player::Update() {}

//描画
void Player::Draw() {
	Novice::DrawBox((int)position_.x, (int)position_.y, 100, 100, 0.0f, WHITE, kFillModeSolid);
}

//右移動
void Player::MoveRight() {
	this->position_.x += speed_;
}

//左移動
void Player::MoveLeft() {
	this->position_.x -= speed_;
}