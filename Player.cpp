#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include <DirectXMath.h>

Player::Player(GameObject* parent)
	: GameObject(parent, "TestScene"), hModel(-1), jumpHeight(2.0f), jumpSpeed(5.0f), jumpDistance(1.0f), fallDistance(1.0f), isJumping(false)
{
}

void Player::Initialize()
{
	hModel = Model::Load("Slime.fbx");

	

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
	else if (!isJumping && ptrans.position_.y > 0.0f)
	{
		float fallDistance = jumpSpeed * Time::GetDeltaTime();
		ptrans.position_.y -= fallDistance;
	}
}

void Player::StartJump()
{
	isJumping = true;
}

void Player::Jump()
{
	//�W�����v���̏���
	float jumpDistance = jumpSpeed * Time::GetDeltaTime();


	//������Ɉړ�
	XMVECTOR jumpVector = XMVectorSet(0.0f, jumpDistance, 0.0f, 0.0f);

	if (ptrans.position_.y >= jumpHeight)
	{	
		isJumping = false;
		ptrans.position_.y = jumpHeight;  //�W�����v���̍����Ɉʒu��ݒ�
	}
	else
	{
		ptrans.position_.y += jumpDistance;  //�W�����v���͏�Ɉړ�
	}

	
}

void Player::Draw()
{
	Model::SetTransform(hModel, ptrans);
	Model::Draw(hModel);

	
}

void Player::Release()
{
}
