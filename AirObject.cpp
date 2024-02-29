#include "AirObject.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Rod.h"
#include "Player.h"

AirObject::AirObject(GameObject* parent)
	:GameObject(parent, "AirObject"), hModel_(-1), amplitude(45.0f), frequency(0.15f), mpi(3.14159265358979323846)
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
	//現在の時間を取得
	static float time = 0.0f;
	//時間を進める
	time += 0.1f;

	if (Input::IsMouseButton(0)) {
		//回転角度を計算
		transform_.rotate_.z = amplitude * sin(mpi * 1 * frequency * time);
	}
}
