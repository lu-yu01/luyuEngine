#include "Window.h"
#include <sstream>

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
)
{
	try
	{
		Window wnd(800, 300, "luyu First Box");
		//Window wnd2(200, 650, "lutyu First Box2");

		MSG msg;
		BOOL gResult;
		while (gResult = GetMessage(&msg, nullptr, 0, 0) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			// do app logic (test)
			while (!wnd.mouse.IsEmpty())
			{
				const auto e = wnd.mouse.Read();
				switch (e.GetType())
				{
				case Mouse::Event::Type::Leave:
					/*wnd.SetTitle("Gone!");
					break;*/
				case Mouse::Event::Type::Move:
				/*	{
					std::ostringstream oss;
					oss << "Mouse Position: (" << e.GetPosX() << "," << e.GetPosY() << ")";
					wnd.SetTitle(oss.str());
					}
					break;*/

				case Mouse::Event::Type::WheelDown:
				{
					std::ostringstream oss;
					oss << "down: (" << wnd.mouse.GetwheelDownCount() << ")";
					wnd.SetTitle(oss.str());
					break;
				}
					
				case Mouse::Event::Type::WheelUp:
				{
					std::ostringstream oss;
					oss << "up: (" << wnd.mouse.GetwheelUpCount() << ")";
					wnd.SetTitle(oss.str());
					break;
				}
	
				}
			/*	if (e.GetType() == Mouse::Event::Type::Move)
				{
					std::ostringstream oss;
					oss << "Mouse Position: (" << e.GetPosX() << "," << e.GetPosY() << ")";
					wnd.SetTitle(oss.str());
				}*/
			}
			/*if (wnd.kbd.KeyIsPressed(VK_MENU))
			{
				MessageBox(nullptr, "Something Happon!","The alt key Was Press", MB_OK | MB_ICONEXCLAMATION);
			}*/
		}
		if (gResult == -1)
		{
			return -1;
		}
		return msg.wParam;
	}
	catch (const luyuException& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available", "Unkonwn Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}