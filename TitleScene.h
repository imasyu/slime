#pragma once
#include "Engine/GameObject.h"
#include "Engine/Camera.h"
class TitleScene : public GameObject
{
private:
	int hModel_;  
	int hSky_;
	XMFLOAT3 camPos_;

	Transform ttrans;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TitleScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

