#pragma once
#include "Engine/GameObject.h"

//JumpRamp���Ǘ�����N���X
class JumpRamp : public GameObject
{
private:
    int hModel_;   //���f���ԍ�
public:
    //�R���X�g���N�^
    JumpRamp(GameObject* parent);

    //�f�X�g���N�^
    ~JumpRamp();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};