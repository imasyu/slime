#pragma once
#include "Engine/GameObject.h"
class GameOverScene : public GameObject
{
private:
	int hPict_;  //�摜�ԍ�
	int hModel_;
	int OverSlime_;

	Transform htrans;
	Transform overtrans;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	GameOverScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

