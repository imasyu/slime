#pragma once
#include "Engine/GameObject.h"

class AirObject : public GameObject
{
    int hModel_;

    float amplitude;
    float frequency;
public:
    //�R���X�g���N�^
    AirObject(GameObject* parent);

    //�f�X�g���N�^
    ~AirObject();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};