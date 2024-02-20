#pragma once
#include "Engine/GameObject.h"
#include <chrono>

class Rod : public GameObject
{
	int hModel_;
    float time;  //�o�ߎ���
    bool rtflag; //��]�����̃t���O
    std::chrono::steady_clock::time_point lastUpdataTime; //�Ō�ɍX�V���ꂽ����
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

