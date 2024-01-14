#pragma once
#include "Engine/GameObject.h"
#include "time.h"

class Player : public GameObject
{
private:
	int hModel_;
	bool jflag = true;

	float jumpVelocity_;  //�W�����v�̑��x
	float jumpCool_;      //�W�����v(�N�[���^�C��)
	float gravity_;       //�d��


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
	void Jump();
};

