#pragma once
#include "Window.h"
#include "luyuTimer.h" 

class App
{
public:
	App();
	// master frame / message loop
	int Go();

private:
	void DoFrame();
private:
	Window wnd;
	luyuTimer timer;
};

