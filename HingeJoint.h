#pragma once
class HingeJoint {
public:
	struct JointSpring {
		float targetPosition;
	};

	JointSpring spring;
};