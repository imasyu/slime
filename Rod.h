#pragma once
#include "Engine/GameObject.h"
#include <chrono>

class Rod : public GameObject
{
	int hModel_;
    float time;  //経過時間
    bool rtflag; //回転方向のフラグ
    std::chrono::steady_clock::time_point lastUpdataTime; //最後に更新された時間
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

