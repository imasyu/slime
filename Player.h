#pragma once
#include "Engine/GameObject.h"
#include "time.h"

class Player : public GameObject
{
private:
	int hModel;
	

	float jumpHeight;  //�W�����v�̍���
	float jumpSpeed;   //�W�����v�̑���
	bool isJumping;    //�W�����v�����̃t���O
	float jumpDistance; //�W�����v������\�������o�ϐ�
	float fallDistance;

	Transform ptrans;
	

	//�W�����v����
	void Jump();
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�W�����v�J�n
	void StartJump();

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

