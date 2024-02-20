#include "Rod.h"
#include "Engine/Model.h"
#include <cmath>

#define PI 3.141592

Rod::Rod(GameObject* parent)
	:GameObject(parent,"Rod"), hModel_(-1), time(0.0f), rtflag(false)
{
	lastUpdataTime = std::chrono::steady_clock::now();
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

	auto now = std::chrono::steady_clock::now();
	float deltaTime = std::chrono::duration_cast<std::chrono::duration<float>>(now - lastUpdataTime).count();
	lastUpdataTime = now;

	time += deltaTime;

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
	if (time > 2.0f)
	{
		time = 0;
		rtflag = !rtflag;
	}

	float rotationAngle = rtflag ? 1.0f : -1.0f;
	transform_.rotate_.z += rotationAngle;
}
