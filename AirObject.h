#pragma once
#include "Engine/GameObject.h"

class AirObject : public GameObject
{
    int hModel_;

    float amplitude;
    float frequency;
public:
    //コンストラクタ
    AirObject(GameObject* parent);

    //デストラクタ
    ~AirObject();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};