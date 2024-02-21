#include "AirObject.h"
#include "Engine/Model.h"

AirObject::AirObject(GameObject* parent)
	:GameObject(parent, "AirObject"), hModel_(-1)
{
}

AirObject::~AirObject()
{
}

void AirObject::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("AirRod.fbx");

	transform_.position_ = { 0,5.8,0 };
}

void AirObject::Update()
{
}

void AirObject::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void AirObject::Release()
{
}
