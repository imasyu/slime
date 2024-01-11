#pragma once
#include "Engine/GameObject.h"

class Player : public GameObject
{
private:
	int hModel;
	int hstage;

	Transform ptrans;
	Transform strans;
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
};

