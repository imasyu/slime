#pragma once
#include "Engine/GameObject.h"
class SkyBox : public GameObject
{
    int hModel_;      //���f���ԍ�
public:
    //�R���X�g���N�^
    SkyBox(GameObject* parent);

    //�f�X�g���N�^
    ~SkyBox();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

