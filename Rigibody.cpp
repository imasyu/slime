#include "Rigibody.h"

Rigibody::Rigibody() : velocity(0.0f, 0.0f, 0.0f)
{
}

void Rigibody::AddForce(XMFLOAT3 force)
{
	velocity.x += force.x;
	velocity.y += force.y;
	velocity.z += force.z;
}
