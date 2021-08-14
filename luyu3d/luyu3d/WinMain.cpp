#include "Window.h"


int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
)
{
	Window wnd(800, 300, "lutyu First Box");
	Window wnd2(200, 650, "lutyu First Box2");

	MSG msg;
	BOOL gResult;
	while (gResult = GetMessage(& msg, nullptr, 0 ,0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (gResult == -1)
	{
		return -1;
	}
}