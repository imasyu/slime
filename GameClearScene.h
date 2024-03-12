#pragma once
#include "Engine/GameObject.h"
class GameClearScene : public GameObject
{
private:
	int hModel_;
	int hSlime_;
	int hPict_;    //画像番号

	Transform mojitrans;
	Transform strans;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	GameClearScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

