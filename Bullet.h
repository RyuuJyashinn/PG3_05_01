// Bullet.h
#pragma once
#include "MyMath.h"
#include <memory>

class Bullet {
public:
    enum class Type { BLADE, BALL };

    Bullet(Vector2 pos, Type type, float speed);
    void Update();
    bool IsActive() const { return isActive_; }


private:
    Vector2 pos_;
    Type type_;
    float speed_;
    bool isActive_ = true;

   
};