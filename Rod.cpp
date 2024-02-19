#include "Rod.h"
#include "Engine/Model.h"

Rod::Rod(GameObject* parent)
	:GameObject(parent,"Rod"), hModel_(-1)
{
}

Rod::~Rod()
{
}

void Rod::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Rod.fbx");
}

void Rod::Update()
{
	transform_.position_.y = -1;
}

void Rod::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Rod::Release()
{
}
