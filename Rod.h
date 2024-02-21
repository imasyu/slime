#pragma once
#include "Engine/GameObject.h"
#include <chrono>

class Rod : public GameObject
{
	int hModel_;
public:
    //�R���X�g���N�^
    Rod(GameObject* parent);

    //�f�X�g���N�^
    ~Rod();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�U��q
    void Pendulum();
};
