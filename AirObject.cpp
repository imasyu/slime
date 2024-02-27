#define _USE_MATH_DEFINES



#include "AirObject.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Rod.h"
#include <math.h>
#include "Player.h"

AirObject::AirObject(GameObject* parent)
	:GameObject(parent, "AirObject"), hModel_(-1), amplitude(45.0f), frequency(0.15f)
{
}

AirObject::~AirObject()
{
}

void AirObject::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("AirRod.fbx");

	transform_.position_ = { 0,5,0 };

	Instantiate<Rod>(this);
}

void AirObject::Update()
{
	Pendulum();
}

void AirObject::Draw()
{
	
}

void AirObject::Release()
{
}

void AirObject::Pendulum()
{
	static float time = 0.0f;
	time += 0.1f;

	if (Input::IsMouseButton(0)) {
		transform_.rotate_.z = amplitude * sin(M_PI * 2 * frequency * time);
	}
}
