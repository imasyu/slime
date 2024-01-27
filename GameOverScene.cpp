#include "GameOverScene.h"
#include "Engine/Image.h"

//�R���X�g���N�^
GameOverScene::GameOverScene(GameObject* parent)
	: GameObject(parent, "GameOverScene"), hPict_(-1)
{
}

//������
void GameOverScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("dice.png");
}

//�X�V
void GameOverScene::Update()
{
}

//�`��
void GameOverScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void GameOverScene::Release()
{
}