#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), jumpCool_(0), jumpVelocity_(1.0)
{
}

//������
void Player::Initialize()
{
	hModel_ = Model::Load("Slime.fbx");

	ptrans_.position_.x = -3;

	SphereCollider* collision = new SphereCollider(ptrans_.position_, (1.5f));
	AddCollider(collision);

}

//�X�V
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

//�`��
void Player::Draw()
{
	Model::SetTransform(hModel_, ptrans_);
	Model::Draw(hModel_);

	
}

//�J��
void Player::Release()
{
}

//�W�����v����
void Player::Jump(float angle)
{
	gravity_ = 0.02f;         //�d��
	

	if (Input::IsKeyUp(DIK_SPACE))
	{
		movex += 0.01;
	}
	
	//�O��܂ŃW�����v���Ă��Ȃ��Ƃ�
	if (Input::IsKeyUp(DIK_SPACE) && !isJumping_)
	{
		velocity = 0.4f;
		isJumping_ = true;  //�W�����v���Ă���
	}

	if (isJumping_)
	{
		//���t���[�������x-�d�͉����x
		velocity -= gravity_;

		//�ړ��ppos�ɉ����x����
		float pos = velocity;

		ptrans_.position_.y += pos;

		ptrans_.position_.x += movex;


		//�n�ʂɒ��n�����Ƃ�
		if (ptrans_.position_.y <= 0)
		{
			ptrans_.position_.y = 0;   //�n�ʂɍ��킹��
			isJumping_ = false;
		}
	}
}

