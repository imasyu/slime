#include "Ceiling.h"
#include "Engine/Model.h"

Ceiling::Ceiling(GameObject* parent) 
	: GameObject(parent, "Ceiling"), hModel_(-1)
{
}

Ceiling::~Ceiling()
{
}

void Ceiling::Initialize()
{
	hModel_ = Model::Load("Stage2.fbx");
	assert(hModel_ >= 0);

	transform_.position_ = { 70,28,0 };
	transform_.scale_ = { 15.0f, 1.0f, 1.0f };
}

void Ceiling::Update()
{
	
}

void Ceiling::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Ceiling::Release()
{
}
