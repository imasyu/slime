#include "JumpRamp.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

JumpRamp::JumpRamp(GameObject* parent)
	:GameObject(parent, "JumpRamp"), hModel_(-1), mass(10.1), k(0.3), damp(0.97), velY(0.0), accel(0), force(0)
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

	
}

void JumpRamp::Update()
{
}

void JumpRamp::Setup()
{
}

void JumpRamp::Fade(boolean _fadeFlag)
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
