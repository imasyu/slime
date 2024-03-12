#include "TitleScene.h"
#include "SkyBox.h"
#include "Engine/Model.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent, "TitleScene"), hModel_(-1), hSky_(-1)
{
}

void TitleScene::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("TitleModel.fbx");
	assert(hModel_ >= 0);

	hSky_ = Model::Load("SkyBox.fbx");
	assert(hSky_ >= 0);

	transform_.position_ = { 0, -7, 10 };
}

void TitleScene::Update()
{
	ttrans.rotate_.y += 0.1f;

	Camera::SetTarget({ transform_.position_.x, transform_.position_.y, transform_.position_.z });
	XMFLOAT3 campos = transform_.position_;
	campos.y = 1;
	Camera::SetTarget(campos);

	if (Input::IsKeyDown(DIK_RETURN))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAYSCENE);
	}
}

void TitleScene::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

	Model::SetTransform(hSky_, ttrans);
	Model::Draw(hSky_);
}

void TitleScene::Release()
{
}
