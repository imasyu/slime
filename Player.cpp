#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include <DirectXMath.h>

Player::Player(GameObject* parent)
	: GameObject(parent, "TestScene"), hModel(-1), hstage(-1), jumpHeight(2.0f), jumpSpeed(5.0f), jumpDistance(1.0f), isJumping(false)
{
}

void Player::Initialize()
{
	hModel = Model::Load("Slime.fbx");

	hstage = Model::Load("Ground.fbx");

}

void Player::Update()
{
	ptrans.position_.y += jumpDistance * isJumping;

	if (Input::IsKeyDown(DIK_SPACE) && !isJumping)
	{
		StartJump();
	}

	if (isJumping)
	{
		Jump();
	}

	
}

void Player::StartJump()
{
	isJumping = true;
}

void Player::Jump()
{
	//ジャンプ中の処理
	float jumpDistance = jumpSpeed * Time::GetDeltaTime();

	float fallDistance = -jumpSpeed * Time::GetDeltaTime();

	//上方向に移動
	if (ptrans.position_.y >= jumpHeight)
	{	
		ptrans.position_.y = jumpHeight;  //ジャンプ中の高さに位置を設定
		isJumping = false;
	}
	else
	{
		ptrans.position_.y += jumpDistance;  //ジャンプ中は上に移動
	}

	//下降処理
	if (!isJumping && ptrans.position_.y > 0.0f)
	{
		ptrans.position_.y += fallDistance;
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel, ptrans);
	Model::Draw(hModel);

	Model::SetTransform(hstage, strans);
	Model::Draw(hstage);
}

void Player::Release()
{
}
