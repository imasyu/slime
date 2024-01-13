#pragma once
class Time
{
public:
	static float GetDeltaTime() { return deltaTime; }
	static void SetDeltaTime(float dt){deltaTime = dt;}
private:
	static float deltaTime;
};

