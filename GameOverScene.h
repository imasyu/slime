#pragma once
#include "Engine/GameObject.h"
class GameOverScene : public GameObject
{
private:
	int hPict_;  //画像番号
	int hModel_;
	int OverSlime_;

	Transform htrans;
	Transform overtrans;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	GameOverScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

