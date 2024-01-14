#pragma once
#include "Engine/GameObject.h"
#include "time.h"

class Player : public GameObject
{
private:
	int hModel;
	

	float jumpHeight;  //ジャンプの高さ
	float jumpSpeed;   //ジャンプの速さ
	bool isJumping;    //ジャンプ中かのフラグ
	float jumpDistance; //ジャンプ距離を表すメンバ変数
	float fallDistance;

	Transform ptrans;
	

	//ジャンプ処理
	void Jump();
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//ジャンプ開始
	void StartJump();

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

