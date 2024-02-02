#include "Player.h"
#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), jumpCool_(0), jumpVelocity_(1.0)
{
}

//������
void Player::Initialize()
{
	hModel_ = Model::Load("Slime.fbx");

	ptrans_.position_.x = -10;

	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), (0.8f));
	AddCollider(collision);

}

//�X�V
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
	const float MAX_JUMP = 0.55f;	//�ő�W�����v��
	const float MAX_MOVEX = 0.05f;	//�ő剡�ړ�

	if (Input::IsKey(DIK_SPACE) /*&& !isJumping_*/)//�����̃R�����g���O���ƁA�W���u���ɃW�����v�ł���o�O������
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
	
	//�O��܂ŃW�����v���Ă��Ȃ��Ƃ�
	if (Input::IsKeyUp(DIK_SPACE) && !isJumping_)
	{
		movex += 0.2f;
		//velocity = 0.4f;
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
	//�W�����v��ɓ���������
	if (pTarget->GetObjectName() == "JumpRamp")
	{
		movex = 0;
		velocity += 0.2f;
	}
}

