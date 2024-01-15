#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
	: GameObject(parent, "TestScene"), hModel_(-1), gravity_(-0.3), jumpCool_(0), jumpVelocity_(1.0)
{
}

//������
void Player::Initialize()
{
	hModel_ = Model::Load("Slime.fbx");
}

//�X�V
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
	float velocity = 5.0f;    //�����x
	float delta = 0.02f;      //�K���ȏ����Ȓl
	gravity_ = -9.81;         //�d��
	static bool isJump_ = true;   //�W�����v�ł��邩
	static float jumpTime = 0.0f; //�W�����v�̌o�ߎ���

	//�W�����v���\�ȏꍇ
	if (Input::IsKeyDown(DIK_SPACE) && isJump_)
	{
		jumpTime = 0.3f;
		isJump_ = false;    //�A���W�����v�h�~�̂��߁A�W�����v�t���O�𖳌���
	}

	if (!jflag && isJump_)
	{
		jumpTime = 0.3f;
		isJump_ = false;    //�A���W�����v�h�~�̂��߁A�W�����v�t���O�𖳌���
	}

	if (!isJump_)
	{
		//�W�����v���Ă���̌o�ߎ���
		jumpTime += delta;

		//���������グ�^��
		float pos = velocity * jumpTime + 0.3f * gravity_ * jumpTime * jumpTime;
		ptrans_.position_.y = pos + 1;

		ptrans_.position_.x += velocity * cos(angle) * delta;

		//����
		velocity += gravity_ * delta;

		//�n�ʂɒ��n�����Ƃ�
		if (ptrans_.position_.y <= 0)
		{
			if (jflag) {
				ptrans_.position_.y = 0;    //�n�ʂɍ��킹��
				isJump_ = true;             //�W�����v�\�ɂ���
			}
			else if (!jflag) {}
		}
	}

}