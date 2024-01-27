#include "GameOverScene.h"
#include "Engine/Image.h"

//コンストラクタ
GameOverScene::GameOverScene(GameObject* parent)
	: GameObject(parent, "GameOverScene"), hPict_(-1)
{
}

//初期化
void GameOverScene::Initialize()
{
	//画像データのロード
	hPict_ = Image::Load("dice.png");
}

//更新
void GameOverScene::Update()
{
}

//描画
void GameOverScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void GameOverScene::Release()
{
}