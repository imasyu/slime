#pragma once
#include "Engine/GameObject.h"

//Ceiling���Ǘ�����N���X
class Ceiling : public GameObject
{
private:
    int hModel_;
public:
    //�R���X�g���N�^
    Ceiling(GameObject* parent);

    //�f�X�g���N�^
    ~Ceiling();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

     int GetModeHandle() { return hModel_; }
};