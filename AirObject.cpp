#include "AirObject.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
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
	XMFLOAT3 mousePosition = Input::GetMousePosition();

	XMVECTOR screenPosition = XMVectorSet(mousePosition.x, mousePosition.y, 0.0f, 0.0f);

	XMVECTOR unprojectedPoint = XMVector3Unproject(
		XMVectorSet(mousePosition.x)
	)
}

void AirObject::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void AirObject::Release()
{
}
