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
    hstage[1] = Model::Load("Ground1.fbx");

    strans2.position_ = { 10,0,-10 };
    strans2.rotate_ = { 0,90,0 };
}

//更新
void Stage::Update()
{
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