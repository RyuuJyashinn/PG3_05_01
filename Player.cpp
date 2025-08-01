#include "Player.h"
#include <Novice.h>


void Player::Initialize() {
	position_ = { 200.0f,200.0f };
	LoadResource();
}


void Player::Update() { UpdateBullets(); }

//描画
void Player::Draw() {
    
    static int frameCounter = 0;
    static int currentFrame = 0;
    const int animationSpeed = 8; 
    const int totalFrames = 4;   

    frameCounter++;
    if (frameCounter >= animationSpeed) {
        frameCounter = 0;
        currentFrame = (currentFrame + 1) % totalFrames;
    }


    Novice::DrawSprite(
        (int)position_.x - 16,  
        (int)position_.y - 16,  
        playergraphL[currentFrame],
        1, 1, 
        0.0f, 
        WHITE 
    );
}

//右移動
void Player::MoveRight() {
	this->position_.x += speed_;
}

//左移動
void Player::MoveLeft() {
	this->position_.x -= speed_;
}

//上移動
void Player::MoveUp() {
	this->position_.y -= speed_;
}

//下移動
void Player::MoveDown() {
	this->position_.y += speed_;
}

void Player::LoadResource() {
	playergraphL[0] = Novice::LoadTexture("./images/player/UMARINER1.png");
	playergraphL[1] = Novice::LoadTexture("./images/player/UMARINER2.png");
	playergraphL[2] = Novice::LoadTexture("./images/player/UMARINER3.png");
	playergraphL[3] = Novice::LoadTexture("./images/player/UMARINER4.png");
    bulletGraphBlade_ = Novice::LoadTexture("./images/player/flyblade.png");
    bulletGraphBall_ = Novice::LoadTexture("./images/player/fireball.png");
}

void Player::FireBullets() {
    auto fireBullet = [this](Bullet::Type type) {
        auto bullet = std::make_unique<Bullet>(
            position_,
            type,
            5.0f  // 子弹速度
        );

        std::lock_guard<std::mutex> lock(bulletsMutex_);
        bullets_.push_back(std::move(bullet));
        };

    // 并行发射两种子弹
    std::thread bladeThread(fireBullet, Bullet::Type::BLADE);
    std::thread ballThread(fireBullet, Bullet::Type::BALL);
    bladeThread.join();
    ballThread.join();
}

void Player::UpdateBullets() {
    std::lock_guard<std::mutex> lock(bulletsMutex_);
    bullets_.erase(
        std::remove_if(bullets_.begin(), bullets_.end(),
            [](const auto& bullet) { return !bullet->IsActive(); }),
        bullets_.end());

    for (auto& bullet : bullets_) {
        bullet->Update();
    }
}

void Player::DrawBullets() {
    std::lock_guard<std::mutex> lock(bulletsMutex_);
    for (auto& bullet : bullets_) {
        bullet->Draw(bulletGraphBlade_, bulletGraphBall_);
    }
}