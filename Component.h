#pragma once
#include "Engine/GameObject.h"
class Component {
protected:
public:
	GameObject *parent;
	virtual void Start() = 0;
	virtual void Update() = 0;
};