#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Enemy.h"
#include "JumpRamp.h"
#include "Ceiling.h"
#include "SkyBox.h"
#include "Rod.h"
#include "AirObject.h"
#include "Engine/Text.h"

namespace {
	Text* pText = nullptr;
	int timeCount = 0;
}

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
	//Instantiate<JumpRamp>(this);
	Instantiate<Ceiling>(this);
	//Instantiate<SkyBox>(this);
	//Instantiate<AirObject>(this);

	pText = new Text();
	pText->Initialize();
}

void PlayScene::Update()
{
	
}

void PlayScene::Draw()
{
	pText->Draw(30, 30, (timeCount / 60));
	timeCount++;
}

void PlayScene::Release()
{
}
