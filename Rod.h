#pragma once
#include "Engine/GameObject.h"
#include <chrono>

class Rod : public GameObject
{
	int hModel_;
public:
    //コンストラクタ
    Rod(GameObject* parent);

    //デストラクタ
    ~Rod();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //振り子
    void Pendulum();
};

