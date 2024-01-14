#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"

PlayScene::PlayScene(GameObject* parent)
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
