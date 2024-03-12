#include "GameOverScene.h"
#include "Engine/Image.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Camera.h"

//�R���X�g���N�^
GameOverScene::GameOverScene(GameObject* parent)
	: GameObject(parent, "GameOverScene"), hPict_(-1), hModel_(-1), OverSlime_(-1)
{
}

//������
void GameOverScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("BackBlack.png");

	hModel_ = Model::Load("GameOverModel.fbx");
	OverSlime_ = Model::Load("GameOverModel1.fbx");

	htrans.scale_ = { 0.2f, 0.2f, 0.2f };
	overtrans.position_ = { 0, -3, 0 };
}

//�X�V
void GameOverScene::Update()
{
	transform_ = overtrans;

	transform_.scale_.x = 2;

	Camera::SetTarget({overtrans.position_.x, overtrans.position_.y, overtrans.position_.z  });
	XMFLOAT3 campos = overtrans.position_;
	campos.y = 1;
	Camera::SetTarget(campos);

	if (Input::IsKeyDown(DIK_G))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
}

//�`��
void GameOverScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);

	Model::SetTransform(hModel_, htrans);
	Model::Draw(hModel_);

	Model::SetTransform(OverSlime_, overtrans);
	Model::Draw(OverSlime_);
}

//�J��
void GameOverScene::Release()
{
}