#pragma once
#include "Engine/GameObject.h"
#include "time.h"

class Player : public GameObject
{
private:
	int hModel_;
	bool jflag = true;

	float jumpVelocity_;  //ジャンプの速度
	float jumpCool_;      //ジャンプ(クールタイム)
	float gravity_;       //重力


	Transform ptrans_;
	

	
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//ジャンプ処理
	void Jump();
};

