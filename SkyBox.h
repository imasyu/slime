#pragma once
#include "Engine/GameObject.h"
class SkyBox : public GameObject
{
    int hModel_;      //モデル番号
public:
    //コンストラクタ
    SkyBox(GameObject* parent);

    //デストラクタ
    ~SkyBox();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

