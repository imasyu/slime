#pragma once
#include "Engine/GameObject.h"
class GameClearScene : public GameObject
{
private:
	int hModel_;
	int hSlime_;
	int hPict_;    //�摜�ԍ�

	Transform mojitrans;
	Transform strans;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	GameClearScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

