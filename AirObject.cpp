#include "AirObject.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Rod.h"

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

	transform_.position_ = { 0,10,0 };

	Instantiate<Rod>(this);
}

void AirObject::Update()
{
	
}

void AirObject::Draw()
{
}

void AirObject::Release()
{
}
