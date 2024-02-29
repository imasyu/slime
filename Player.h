#pragma once
#include "Engine/GameObject.h"
#include "AirObject.h"

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

	Aim* pAim_;                     // �Ə�
	AirObject* pAirObject;

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

	void SetAirObject(AirObject* airobject) { pAirObject = airobject; }
};

