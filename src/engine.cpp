#include "pch.h"
#include "engine.h"
#include <conio.h>


GameEngine* GameEngine::m_instance = nullptr;


GameEngine * GameEngine::instance()
{
	return m_instance != nullptr ? m_instance : m_instance = new GameEngine();
}

int GameEngine::init()
{
	//init gdi plus
	GdiplusStartupInput gdiplusStartupinput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupinput, NULL);
	//init hwnd and screen buffer
	m_hwnd = GetConsoleWindow();
	RECT r;
	GetClientRect(m_hwnd, &r);
	m_width = r.right;
	m_height = r.bottom;
	m_screen_buffer = new Bitmap(m_width, m_height);
	return 1;
}

int GameEngine::run()
{
	//begin thread
	draw_thread = new std::thread(&GameEngine::draw_loop, this);
	update_thread = new std::thread(&GameEngine::update_loop, this);
	while (true) {
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 'q')
				break;
		}
	}
	draw_thread->detach();
	update_thread->detach();
	return 1;
}

void GameEngine::update()
{
}

void GameEngine::draw(Graphics & graphics)
{
}

GameEngine::GameEngine()
{
}

void GameEngine::update_loop()
{
	while (update_enable)
	{
		update();
		Sleep(40.0f);
	}
}

void GameEngine::draw_loop()
{
	while (draw_enable)
	{
		Graphics g(m_screen_buffer);
		g.Clear(Color(75, 182, 238));
		draw(g);
		HDC hdc = GetDC(m_hwnd);
		Graphics g2(hdc);
		g2.DrawImage(m_screen_buffer, 0, 0);
		ReleaseDC(m_hwnd, hdc);
		Sleep(30.0f);		
	}
}
