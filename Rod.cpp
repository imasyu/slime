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

	transform_.rotate_ = { 0, 0, 180.0f };
	transform_.position_ = { 0, 2, 0 };
}

void Rod::Update()
{
	
	

	Pendulum();
}

void Rod::Draw()
{
	/*Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);*/
}

void Rod::Release()
{
}

void Rod::Pendulum()
{
	
}
