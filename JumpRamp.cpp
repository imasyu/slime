#include "JumpRamp.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

JumpRamp::JumpRamp(GameObject* parent)
	:GameObject(parent, "JumpRamp"), hModel_(-1)
{
}

JumpRamp::~JumpRamp()
{
}

void JumpRamp::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("spring.fbx");  
	assert(hModel_ >= 0);

	transform_.position_ = { 5,0,0 };
	transform_.scale_ = { 0.5f,0.5f,0.5f };

	Model::SetAnimFrame(hModel_, 1, 60, 1);

	BoxCollider* collision = new BoxCollider(transform_.position_, XMFLOAT3(3, 2, 1));
	AddCollider(collision);
}

void JumpRamp::Update()
{
}

void JumpRamp::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void JumpRamp::Release()
{
}
