#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

Player::Player(GameObject* parent)
	: GameObject(parent, "TestScene"), hModel(-1), hstage(-1)
{
}

void Player::Initialize()
{
	hModel = Model::Load("Slime.fbx");

	hstage = Model::Load("Ground.fbx");

}

void Player::Update()
{
	if (Input::IsKey(DIK_RIGHT))
	{
		ptrans.position_.x += 0.2f;
	}
	if (Input::IsKey(DIK_LEFT))
	{
		ptrans.position_.x -= 0.2f;
	}
	if (Input::IsKey(DIK_SPACE))
	{
		ptrans.position_.y = 2;

		if (ptrans.position_.y >= 2)
		{
			ptrans.position_.y -= 0.2f;
		}
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
