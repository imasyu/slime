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
	if (Input::IsMouseButton(0)) {

		if (transform_.position_.z <= 0) {
			transform_.rotate_.z += 5.0f;
		}
	}
	if (Input::IsMouseButtonUp(0)) {

		if (transform_.position_.z >= 180) {
			transform_.rotate_.z -= 5.0f;
		}
	}
}

void AirObject::Draw()
{
}

void AirObject::Release()
{
}
