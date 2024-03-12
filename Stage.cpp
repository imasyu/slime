#include "Stage.h"
#include "Engine/Model.h"
//�R���X�g���N�^
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hstage(-1)
{
}

//�f�X�g���N�^
Stage::~Stage()
{
}

//������
void Stage::Initialize()
{
    hstage = Model::Load("Stage.fbx");
    assert(hstage >= 0);
    
}

//�X�V
void Stage::Update()
{
    transform_.position_.x = 20;;
   
};
   

//�`��
void Stage::Draw()
{
    Model::SetTransform(hstage, transform_);
    Model::Draw(hstage);
}

//�J��
void Stage::Release()
{
}