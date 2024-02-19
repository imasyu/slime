#include "Stage.h"
#include "Engine/Model.h"
//�R���X�g���N�^
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hstage{-1, -1}
{
}

//�f�X�g���N�^
Stage::~Stage()
{
}

//������
void Stage::Initialize()
{
    hstage[0] = Model::Load("Stage.fbx");
    assert(hstage[0] >= 0);

    hstage[1] = Model::Load("Stage.fbx");
    assert(hstage[1] >= 0);
    
}

//�X�V
void Stage::Update()
{
    //strans.position_.y = -5;
    strans2.position_.x = 20;
    //strans2.position_.y = -5;
   
};
   

//�`��
void Stage::Draw()
{
    Model::SetTransform(hstage[0], strans);
    Model::Draw(hstage[0]);

    Model::SetTransform(hstage[1], strans2);
    Model::Draw(hstage[1]);
}

//�J��
void Stage::Release()
{
}