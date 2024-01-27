#pragma once
#include "Engine/GameObject.h"

//JumpRampを管理するクラス
class JumpRamp : public GameObject
{
private:
    int hModel_;   //モデル番号
public:
    //コンストラクタ
    JumpRamp(GameObject* parent);

    //デストラクタ
    ~JumpRamp();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};