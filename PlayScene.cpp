#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Enemy.h"
#include "JumpRamp.h"
#include "Ceiling.h"
#include "SkyBox.h"
#include "Rod.h"
#include "AirObject.h"
#include "Stage1.h"
#include "Engine/Text.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"

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
	Instantiate<JumpRamp>(this);
	Instantiate<Ceiling>(this);
	Instantiate<SkyBox>(this);
	Instantiate<Stage1>(this);

	pText = new Text();
	pText->Initialize();
}

void PlayScene::Update()
{
	if (Input::IsKeyDown(DIK_F))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
	pText->Draw(30, 30, (timeCount / 60));
	timeCount++;
}

void PlayScene::Release()
{
}
