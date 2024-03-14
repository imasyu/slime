#include "Stage1.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Stage1::Stage1(GameObject* parent)
	:GameObject(parent, "Stage1"), hModel_(-1)
{
}

void Stage1::Initialize()
{
	hModel_ = Model::Load("Stage1.fbx");

	transform_.position_ = { 100, 6, 0 };
	transform_.scale_ = { 1.0f, 2.0f, 1.0f };

	SphereCollider* collision = new SphereCollider(XMFLOAT3(65, 0, 0), 4.0f);
	AddCollider(collision);
}

void Stage1::Update()
{
}

void Stage1::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Stage1::Release()
{
}
