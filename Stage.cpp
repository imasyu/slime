#include "Stage.h"
#include "Engine/Model.h"
//コンストラクタ
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hstage{-1, -1}
{
}

//デストラクタ
Stage::~Stage()
{
}

//初期化
void Stage::Initialize()
{
    hstage[0] = Model::Load("Ground.fbx");
    hstage[1] = Model::Load("SkyBox.fbx");

    
}

//更新
void Stage::Update()
{
    strans2.rotate_.y += 0.1f;
}

//描画
void Stage::Draw()
{
    Model::SetTransform(hstage[0], strans);
    Model::Draw(hstage[0]);

    Model::SetTransform(hstage[1], strans2);
    Model::Draw(hstage[1]);
}

//開放
void Stage::Release()
{
}