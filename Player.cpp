#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), jumpCool_(0), jumpVelocity_(1.0)
{
}

//初期化
void Player::Initialize()
{
	hModel_ = Model::Load("Slime.fbx");

	ptrans_.position_.x = -3;

	SphereCollider* collision = new SphereCollider(ptrans_.position_, (1.5f));
	AddCollider(collision);

}

//更新
void Player::Update()
{
	Jump(angle);

	

	Camera::SetPosition(XMFLOAT3(0, 3, -8));
	Camera::SetTarget(ptrans_.position_);


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
	gravity_ = 0.02f;         //重力
	

	if (Input::IsKeyUp(DIK_SPACE))
	{
		movex += 0.01;
	}
	
	//前回までジャンプしていないとき
	if (Input::IsKeyUp(DIK_SPACE) && !isJumping_)
	{
		velocity = 0.4f;
		isJumping_ = true;  //ジャンプしている
	}

	if (isJumping_)
	{
		//毎フレーム加速度-重力加速度
		velocity -= gravity_;

		//移動用posに加速度を代入
		float pos = velocity;

		ptrans_.position_.y += pos;

		ptrans_.position_.x += movex;


		//地面に着地したとき
		if (ptrans_.position_.y <= 0)
		{
			ptrans_.position_.y = 0;   //地面に合わせる
			isJumping_ = false;
		}
	}
}

