#pragma once
#include"MyMath.h"
#include"Bullet.h"
#include <vector>
#include <memory>
#include <mutex>
class Player {
private:

	// 位置
	Vector2 position_;

	// 速さ
	float speed_ = 2.0f;
	std::vector<std::unique_ptr<Bullet>> bullets_;
	std::mutex bulletsMutex_;

	int bulletGraphBlade_;
	int bulletGraphBall_;
public:

	void Initialize();

	void Update();

	void Draw();

	/// 右移動
	void MoveRight();

	/// 左移動
	void MoveLeft();

	void MoveUp();

	void MoveDown();

	void LoadResource();

	void FireBullets();
	void UpdateBullets();
	void DrawBullets();
private:
	int playergraphL[4];
};