#include "Player.h"
#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"

//コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), jumpCool_(0), jumpVelocity_(1.0)
{
}

//初期化
void Player::Initialize()
{
	hModel_ = Model::Load("Slime.fbx");

	ptrans_.position_.x = -10;

	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), (0.8f));
	AddCollider(collision);

}

//更新
void Player::Update()
{
	Jump(angle);

	transform_ = ptrans_;

	Camera::SetTarget({ ptrans_.position_.x, 0, ptrans_.position_.z });
	XMFLOAT3 camPos = ptrans_.position_;
	camPos.y = 4;
	camPos.z = -20;
	camPos.x = ptrans_.position_.x;
	Camera::SetPosition(camPos);


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
	const float MAX_JUMP = 0.55f;	//最大ジャンプ力
	const float MAX_MOVEX = 0.05f;	//最大横移動

	if (Input::IsKey(DIK_SPACE) /*&& !isJumping_*/)//ここのコメントを外すと、ジャブ中にジャンプできるバグが治る
	{
		movex += 0.001;	
		velocity += 0.02f;

		if (velocity >= MAX_JUMP)
		{
			velocity = MAX_JUMP;
		}

		if (movex >= MAX_MOVEX)
		{
			movex = MAX_MOVEX;
		}
		
	}
	
	//前回までジャンプしていないとき
	if (Input::IsKeyUp(DIK_SPACE) && !isJumping_)
	{
		movex += 0.2f;
		//velocity = 0.4f;
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
			movex = 0;
			velocity = 0;
		}
		else if (ptrans_.position_.y < 0) {
			velocity += gravity_;
		}
			
	}
}

void Player::OnCollision(GameObject* pTarget)
{
	//ジャンプ台に当たった時
	if (pTarget->GetObjectName() == "JumpRamp")
	{
		movex = 0;
		velocity += 0.2f;
	}
}

