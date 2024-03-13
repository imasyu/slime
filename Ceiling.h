#pragma once
#include "Engine/GameObject.h"

//Ceilingを管理するクラス
class Ceiling : public GameObject
{
private:
    int hModel_;
public:
    //コンストラクタ
    Ceiling(GameObject* parent);

    //デストラクタ
    ~Ceiling();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

     int GetModeHandle() { return hModel_; }
};