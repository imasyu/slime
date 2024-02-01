#include "JumpRamp.h"
#include "Engine/Model.h"

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

	//transform_.position_ = { 3,0,0 };
	//transform_.scale_ = { 100,100,100 };

	Model::SetAnimFrame(hModel_, 1, 60, 1);
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
