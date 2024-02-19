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
    hstage[0] = Model::Load("Stage.fbx");
    assert(hstage[0] >= 0);

    hstage[1] = Model::Load("Stage.fbx");
    assert(hstage[1] >= 0);
    
}

//更新
void Stage::Update()
{
    //strans.position_.y = -5;
    strans2.position_.x = 20;
    //strans2.position_.y = -5;
   
};
   

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