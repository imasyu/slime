#pragma once
#include <DirectXMath.h>

using namespace DirectX;

class Rigibody
{
public:
	XMFLOAT3 velocity;

	Rigibody();

	void AddForce(XMFLOAT3 force);
};

