#pragma once
#include "Component.h"
#include "HingeJoint.h"

class RodMove : public Component
{
private:
	HingeJoint* hj;
	HingeJoint::JointSpring sp;
	float beginPos;
	float shotPos;
public:
	RodMove();

	void Start() override;

	void Update() override;
};

