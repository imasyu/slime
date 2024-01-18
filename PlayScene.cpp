#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Enemy.h"

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
	Instantiate<Enemy>(this);
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
