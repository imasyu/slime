#include "SkyBox.h"
#include "Engine/Model.h"

SkyBox::SkyBox(GameObject* parent) 
	:GameObject(parent, "Player"), hModel_(-1)
{
}

SkyBox::~SkyBox()
{
}

void SkyBox::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("SkyBox.fbx");
}

void SkyBox::Update()
{
	transform_.rotate_.y += 0.1f;
}

void SkyBox::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void SkyBox::Release()
{
}
