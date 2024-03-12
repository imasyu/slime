#include "TitleScene.h"
#include "Engine/Model.h"
#include "Engine/SceneManager.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent, "TitleScene"), hModel_(-1)
{
}

void TitleScene::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("TitleModel.fbx");
	assert(hModel_ >= 0);

	transform_.scale_ = { 0.5f, 0.5f, 0.5f };
	//transform_.position_ = { -4, 0, 5 };
}

void TitleScene::Update()
{
}

void TitleScene::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TitleScene::Release()
{
}
