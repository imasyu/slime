#pragma once
#include "Engine/GameObject.h"

//Stage���Ǘ�����N���X
class Stage : public GameObject
{
private:
    int hstage[3];

    Transform strans;
    Transform strans2;
    Transform strans3;
public:
    //�R���X�g���N�^
    Stage(GameObject* parent);

    //�f�X�g���N�^
    ~Stage();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    int GetModeHandle() { return hstage[3]; }
};