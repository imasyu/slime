#pragma once
#include "Engine/GameObject.h"

class Aim;

class Player : public GameObject
{
private:
	int hModel_;
	XMFLOAT3 move_;
	bool jflag = true;

	float jumpVelocity_;  //�W�����v�̑��x
	float jumpCool_;      //�W�����v(�N�[���^�C��)
	float gravity_;       //�d�͉����x

	float velocity = 0.0f;  //������̉����x
	float delta = 0.02f;    //�K���ȏ����Ȓl
	float movex = 0.0f;

	bool isJumping_ = false;   //�W�����v���Ă��邩�ǂ���
	float jumpTime = 0.0f;     //�W�����v�̌o�ߎ���
	float angle = DirectX::XMConvertToRadians(45.0f);
	float rotateTime = 0.0f;   //��]�̌o�ߎ���
	float rotateInterval = 2.0f; //��]���s���Ԋu(�b)
	bool rotateflag = false;     //���݉�]���Ă��邩�̃t���O
	Aim* pAim_;                     // �Ə�

	Transform ptrans_;
	
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�W�����v����
	void Jump(float angle);

	//�����ɓ�������
   //�����FpTarget ������������
	void OnCollision(GameObject* pTarget) override;

};

