#include "GameClearScene.h"
#include "Engine/Image.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Camera.h"

GameClearScene::GameClearScene(GameObject* parent)
	:GameObject(parent, "Player"), hPict_(-1), hModel_(-1), hSlime_(-1)
{
}

void GameClearScene::Initialize()
{
	//画像データのロード
	hPict_ = Image::Load("ClearSky.png");
	assert(hPict_ >= 0);

	//モデルデータのロード
	hModel_ = Model::Load("GameClearModel.fbx");
	assert(hModel_ >= 0);

	hSlime_ = Model::Load("GameClearModel1.fbx");
	assert(hSlime_ >= 0);

	strans.position_ = { 0, -3, 0 };
	mojitrans.scale_ = { 0.3f, 0.3f, 0.3f };

}

void GameClearScene::Update()
{
	transform_.scale_.x = 2;
	mojitrans.position_.y = -1;

	Camera::SetPosition(XMFLOAT3(0, -2, -10));
	Camera::SetTarget(XMFLOAT3(0, 1, 0));

	if (Input::IsKeyDown(DIK_F))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}

	if (Input::IsKeyDown(DIK_D))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	}
}

void GameClearScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);

	Model::SetTransform(hModel_, mojitrans);
	Model::Draw(hModel_);

	Model::SetTransform(hSlime_, strans);
	Model::Draw(hSlime_);
}

void GameClearScene::Release()
{
}
