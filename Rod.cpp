#include "Rod.h"
#include "Engine/Model.h"
#include <cmath>

#define PI 3.141592

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

	

	Pendulum();
}

void Rod::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Rod::Release()
{
}

void Rod::Pendulum()
{
	
}
