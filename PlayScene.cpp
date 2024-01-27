#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Enemy.h"
#include "JumpRamp.h"

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
	Instantiate<JumpRamp>(this);
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
