#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "TestScene"), hModel_(-1), gravity_(-0.3), jumpCool_(0), jumpVelocity_(1.0)
{
}

//初期化
void Player::Initialize()
{
	hModel_ = Model::Load("Slime.fbx");
}

//更新
void Player::Update()
{
	Jump(angle);

	if (Input::IsKey(DIK_RIGHT))
	{
		ptrans_.position_.x += 0.2f;
	}
	if (Input::IsKey(DIK_LEFT))
	{
		ptrans_.position_.x -= 0.2f;
	}

	if (Input::IsKeyUp(DIK_RETURN))
	{
		static int cnt = 0;
		cnt++;
		if (cnt >= 1)
		{
			PostQuitMessage(0);
		}
	}
}

//描画
void Player::Draw()
{
	Model::SetTransform(hModel_, ptrans_);
	Model::Draw(hModel_);

	
}

//開放
void Player::Release()
{
}

//ジャンプ処理
void Player::Jump(float angle)
{
	float velocity = 5.0f;    //初速度
	float delta = 0.02f;      //適当な小さな値
	gravity_ = -9.81;         //重力
	static bool isJump_ = true;   //ジャンプできるか
	static float jumpTime = 0.0f; //ジャンプの経過時間

	//ジャンプが可能な場合
	if (Input::IsKeyDown(DIK_SPACE) && isJump_)
	{
		jumpTime = 0.3f;
		isJump_ = false;    //連続ジャンプ防止のため、ジャンプフラグを無効化
	}

	if (!jflag && isJump_)
	{
		jumpTime = 0.3f;
		isJump_ = false;    //連続ジャンプ防止のため、ジャンプフラグを無効化
	}

	if (!isJump_)
	{
		//ジャンプしてからの経過時間
		jumpTime += delta;

		//鉛直投げ上げ運動
		float pos = velocity * jumpTime + 0.3f * gravity_ * jumpTime * jumpTime;
		ptrans_.position_.y = pos + 1;

		ptrans_.position_.x += velocity * cos(angle) * delta;

		//落下
		velocity += gravity_ * delta;

		//地面に着地したとき
		if (ptrans_.position_.y <= 0)
		{
			if (jflag) {
				ptrans_.position_.y = 0;    //地面に合わせる
				isJump_ = true;             //ジャンプ可能にする
			}
			else if (!jflag) {}
		}
	}

}