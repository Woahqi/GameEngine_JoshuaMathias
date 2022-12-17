#pragma once
class States
{
private:
	static bool bPaused;
public:
	static bool getPausedState();
	static void setPausedState(bool bPaused);
};

