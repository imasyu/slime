#pragma once
#include "Engine/GameObject.h"

//JumpRamp���Ǘ�����N���X
class JumpRamp : public GameObject
{
private:
    int hModel_;   //���f���ԍ�

    float y;          //�I�u�W�F�N�g��y���W
    float mass;       //�I�u�W�F�N�g�̎���
    float k;          //�΂˂̋����i�΂˒萔�j
    float damp;       //���C�ɂ�錸����
    float velY;       //y�����̃X�s�[�h
    float accel;      //�����x
    float force;      //�΂˂̔�����
    float originY;    //��_
public:
    //�R���X�g���N�^
    JumpRamp(GameObject* parent);

    //�f�X�g���N�^
    ~JumpRamp();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    void Setup();

    void Fade(boolean _fadeFlag);

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};