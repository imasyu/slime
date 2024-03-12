#include "Stage.h"
#include "Engine/Model.h"
//コンストラクタ
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hstage(-1)
{
}

//デストラクタ
Stage::~Stage()
{
}

//初期化
void Stage::Initialize()
{
    hstage = Model::Load("Stage.fbx");
    assert(hstage >= 0);
    
}

//更新
void Stage::Update()
{
    transform_.position_.x = 20;;
   
};
   

//描画
void Stage::Draw()
{
    Model::SetTransform(hstage, transform_);
    Model::Draw(hstage);
}

//開放
void Stage::Release()
{
}