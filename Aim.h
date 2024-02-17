#pragma once
#include "Engine/GameObject.h"

class Aim : public GameObject
{
    float perspectiveDistance_;     //�ǂ̂��炢��납��f����
    float mouseSensitivity;         //�}�E�X���x
    XMFLOAT3 cameraTarget_;         //�J�����̏œ_�ڕW
    XMFLOAT3 cameraPosition_;       //�J�����̏ꏊ�ڕW
    XMFLOAT3 aimDirection_;         //���݂̎��_�Ɋ�Â����i�s�����x�N�g��
    class Player* pPlayer_;

    void CalcAim();
    void CalcMouseMove();
    XMVECTOR CalcDirection(float x, float y);

public:
    Aim(GameObject* parent);
    ~Aim();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
    void SetPlayer(class Player* p) { pPlayer_ = p; }
    XMFLOAT3 GetAimDirection() { return aimDirection_; }

};

