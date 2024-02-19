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
	hModel_ = Model::Load("Stage1.fbx");
	assert(hModel_ >= 0);
}

void Ceiling::Update()
{
	transform_.position_ = { 3,10,0 };
}

void Ceiling::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Ceiling::Release()
{
}
