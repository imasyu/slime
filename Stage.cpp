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
    hstage[0] = Model::Load("Ground.fbx");
    hstage[1] = Model::Load("SkyBox.fbx");

    
}

//�X�V
void Stage::Update()
{
    strans2.rotate_.y += 0.1f;
}

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