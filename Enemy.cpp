#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"
#include "Engine/Input.h"

//コンストラクタ
Enemy::Enemy(GameObject* parent)
	: GameObject(parent, "Enemy"), henemy_(-1)
{
}

//初期化
void Enemy::Initialize()
{
	henemy_ = Model::Load("Enemy.fbx");

	Model::SetAnimFrame(henemy_, 1, 60, 1);

	BoxCollider* collision = new BoxCollider(etrans_.position_, XMFLOAT3(0.4, 1, 0));
	AddCollider(collision);
}

//更新
void Enemy::Update()
{
	
}

//描画
void Enemy::Draw()
{
	Model::SetTransform(henemy_, etrans_);
	Model::Draw(henemy_);
}

//開放
void Enemy::Release()
{
}

//何かに当たった
void Enemy::OnCollision(GameObject* pTarget)
{
	//当たった時の処理
	if (pTarget->GetObjectName() == "Player")
	{
		KillMe();
	}
}