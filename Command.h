#pragma once
#include"Player.h"
//プレイヤークラス参照宣言
class Player;

//コマンドクラス
class ICommand {
public:

	/// 仮想デストラクタ
	virtual ~ICommand();

	/// 実行関数（純粋仮想関数）
	virtual void Execute(Player& player) = 0;
};

//コマンドクラスを継承した右移動クラス
class MoveRightCommand : public ICommand {
public:

	/// ICommandクラスを継承した実行関数
	void Execute(Player& player) override;
};

//コマンドクラスを継承した左移動クラス
class MoveLeftCommand : public ICommand {
public:

	/// 実行(継承)
	void Execute(Player& player) override;
}; 


class MoveUpCommand : public ICommand {
public:

	/// ICommandクラスを継承した実行関数
	void Execute(Player& player) override;
};

//コマンドクラスを継承した左移動クラス
class MoveDownCommand : public ICommand {
public:

	/// 実行(継承)
	void Execute(Player& player) override;
};



