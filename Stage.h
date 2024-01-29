#pragma once
#include "Engine/GameObject.h"

//Stageを管理するクラス
class Stage : public GameObject
{
private:
    int hstage[3];

    Transform strans;
    Transform strans2;
    Transform strans3;
public:
    //コンストラクタ
    Stage(GameObject* parent);

    //デストラクタ
    ~Stage();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    int GetModeHandle() { return hstage[3]; }
};