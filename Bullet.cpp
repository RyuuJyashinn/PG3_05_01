// Bullet.cpp
#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet(Vector2 pos, Type type, float speed)
    : pos_(pos), type_(type), speed_(speed) {
}

void Bullet::Update() {
    pos_.x += (type_ == Type::BLADE) ? -speed_ : speed_;
    if (pos_.x < 0 || pos_.x > 1280) isActive_ = false;
}

void Bullet::Draw(int bladeTexture, int ballTexture) const {
    int texture = (type_ == Type::BLADE) ? bladeTexture : ballTexture;
    Novice::DrawSprite((int)pos_.x, (int)pos_.y, texture, 1, 1, 0.0f, WHITE);
}

