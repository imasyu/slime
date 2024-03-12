#include "Player.h"
#include "Ceiling.h"
#include "Stage.h"
#include "Rod.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Aim.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"
#include "Engine/Text.h"

namespace {
	Text* pText = nullptr;

}

//�R���X�g���N�^
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), jumpCool_(0), jumpVelocity_(1.0), pAirObject(nullptr) {
}

//������
void Player::Initialize()
{
	hModel_ = Model::Load("Slime.fbx");

	ptrans_.position_.x = -20;

	/*pAim_ = Instantiate<Aim>(this);
	pAim_->SetPlayer(this);*/

	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), (1.0f));
	AddCollider(collision);

	pText = new Text();
	pText->Initialize();
}

//�X�V
void Player::Update()
{
	Jump(angle);

	transform_ = ptrans_;

	Camera::SetTarget({ ptrans_.position_.x, ptrans_.position_.y, ptrans_.position_.z });
	XMFLOAT3 camPos = ptrans_.position_;
	camPos.y = 4;
	camPos.z = -20;
	camPos.x = ptrans_.position_.x;
	Camera::SetPosition(camPos);

	Ceiling* pCeiling = (Ceiling*)FindObject("Ceiling");   //�X�e�[�W�I�u�W�F�N�g��T��
	int hGroundModel = pCeiling->GetModeHandle();     //���f���ԍ����擾

	RayCastData data;
	data.start = ptrans_.position_;    //���C�̔��ˈʒu
	data.dir = XMFLOAT3(0, 1, 0);         //���C�̕���
	Model::RayCast(hGroundModel, &data);  //���C�𔭎�

	if (pAirObject != nullptr) {
		ptrans_.rotate_ = pAirObject->GetRotate();
	}

	if (Input::IsKeyDown(DIK_P))
	{
		AirObject* airobject = Instantiate<AirObject>(this);
		SetAirObject(airobject);
		airobject->Pendulum();

		//���C������������
		if (data.hit)
		{
			//���̕�������
			ptrans_.position_.y += data.dist - 5;

			
		}
	}

	TarzanJump(angle);

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

	pText->Draw(30, 100, transform_.position_.x);
	pText->Draw(30, 140, transform_.position_.z);
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

	if (Input::IsKey(DIK_SPACE) && !isJumping_)//�����̃R�����g���O���ƁA�W���u���ɃW�����v�ł���o�O������
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

void Player::TarzanJump(float angle)
{
	//gravity_ = 0.02f;
	chargejumpPower = 0.01f;
	const float MAX_CHARGE = 0.55f;  //�ő�~�ω\�ȃW�����v��
	const float CHARGE_RATE = 0.02f;//1�t���[��������̑�����
	const float MAX_CHARGE_X = 0.3f; //�������̍ő�\�~�ϗ�
	const float CHARGE_RATE_X = 0.015f;//�������̑�����

	if (Input::IsMouseButtonDown(0))
	{
		chargejumpPower += CHARGE_RATE;
		if (chargejumpPower > MAX_CHARGE)
		{
			chargejumpPower = MAX_CHARGE; //�~�ϗʂ𒴂��Ȃ��悤�ɂ���
		}

		chargeX += CHARGE_RATE_X;
		if (chargeX > MAX_CHARGE_X) {
			chargeX = MAX_CHARGE_X;
		}
	}
	else if (Input::IsMouseButtonUp(0) && !isJumping_ )
	{
			//�~�ς����W�����v�͂��g��
			velocity = chargejumpPower;

			ptrans_.position_.x += jumpDirection.x * chargeX;
			ptrans_.position_.y += jumpDirection.y * chargeX;

			isJumping_ = true;

			chargejumpPower = 0.0f;
			chargeX = 0.0f;
	}

}

void Player::OnCollision(GameObject* pTarget)
{
	//�W�����v��ɓ���������
	if (pTarget->GetObjectName() == "JumpRamp")
	{
		movex = 0.3f;
		velocity += 0.1f;
	}
}

void Player::SizeChange()
{
	
}
