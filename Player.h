#pragma once
#include "Engine/GameObject.h"
#include "AirObject.h"
#include "PlayScene.h"

class Aim;
class PlayScene;

class Player : public GameObject
{
private:
	int hModel_;
	XMFLOAT3 move_;
	bool jflag = true;

	float jumpVelocity_;  //ジャンプの速度
	float jumpCool_;      //ジャンプ(クールタイム)
	float gravity_;       //重力加速度

	float velocity = 0.0f;  //上方向の加速度
	float delta = 0.02f;    //適当な小さな値
	float movex = 0.0f;

	bool isJumping_ = false;   //ジャンプしているかどうか
	float jumpTime = 0.0f;     //ジャンプの経過時間
	float angle = DirectX::XMConvertToRadians(45.0f);

	bool chargejump_ = false; 
	float chargejumpPower;   //ジャンプ力を蓄える
	float chargeX = 0.0f;    

	Aim* pAim_;                     // 照準
	AirObject* pAirObject;
	PlayScene* pPlayScene;

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
	void Jump(float angle);

	void TarzanJump(float angle);

	//何かに当たった
   //引数：pTarget 当たった相手
	void OnCollision(GameObject* pTarget) override;

	void SizeChange();

	void SetAirObject(AirObject* airobject) { pAirObject = airobject; }
};

