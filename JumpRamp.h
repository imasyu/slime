#pragma once
#include "Engine/GameObject.h"

//JumpRampを管理するクラス
class JumpRamp : public GameObject
{
private:
    int hModel_;   //モデル番号

    float y;          //オブジェクトのy座標
    float mass;       //オブジェクトの質量
    float k;          //ばねの強さ（ばね定数）
    float damp;       //摩擦による減衰率
    float velY;       //y方向のスピード
    float accel;      //加速度
    float force;      //ばねの反発力
    float originY;    //基準点
public:
    //コンストラクタ
    JumpRamp(GameObject* parent);

    //デストラクタ
    ~JumpRamp();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    void Setup();

    void Fade(boolean _fadeFlag);

    //描画
    void Draw() override;

    //開放
    void Release() override;
};