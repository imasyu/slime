#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Enemy::Enemy(GameObject* parent)
	: GameObject(parent, "Enemy"), henemy_(-1)
{
}

//������
void Enemy::Initialize()
{
	henemy_ = Model::Load("Enemy.fbx");

	Model::SetAnimFrame(henemy_, 1, 60, 1);

	BoxCollider* collision = new BoxCollider(etrans_.position_, XMFLOAT3(1, 2, 1));
	AddCollider(collision);
}

//�X�V
void Enemy::Update()
{
	if (Input::IsKey(DIK_RIGHT))
	{
		etrans_.position_.x += 0.2f;
	}
}

//�`��
void Enemy::Draw()
{
	Model::SetTransform(henemy_, etrans_);
	Model::Draw(henemy_);
}

//�J��
void Enemy::Release()
{
}

//�����ɓ�������
void Enemy::OnCollision(GameObject* pTarget)
{
	//�����������̏���
	if (pTarget->GetObjectName() == "Player")
	{
		KillMe();
	}
}