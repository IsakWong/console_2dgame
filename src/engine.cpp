#include "pch.h"
#include <conio.h>
#include "engine.h"
#include "sprite.h"
#include "resource.h"
#include <iostream>

GameEngine* GameEngine::m_instance = nullptr;

HHOOK keyboardHook;
LRESULT CALLBACK KeyboardProc(
	_In_ int    code,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
)
{
	::MessageBox(NULL, "按键了", "caption", 0x00000002L);
	return CallNextHookEx(keyboardHook, code, wParam, lParam);//第一个参数一般可以为NULL
}


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
	m_draw_context.window_width = r.right;
	m_draw_context.window_height = r.bottom;
	m_screen_buffer = new Bitmap(m_draw_context.window_width, m_draw_context.window_height);

	load_resources();

	return 1;
}


#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1) 

int GameEngine::run()
{
	//begin thread
	draw_thread = new std::thread(&GameEngine::draw_loop, this);
	update_thread = new std::thread(&GameEngine::update_loop, this);
	DWORD d = GetCurrentThreadId();
	keyboardHook = SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)KeyboardProc, GetModuleHandle(0), GetCurrentThreadId());
	auto error = GetLastError();
	MSG msg;
	while (TRUE)
	{
		if (KEYDOWN(VK_ESCAPE))
		{
			break;
		}
	}
	UnhookWindowsHookEx(m_hook);
	draw_thread->detach();
	update_thread->detach();
	return 1;
}

int GameEngine::load_resources()
{
	ImageResource* tree_image = new ImageResource(L"tree.png", "tree");

	auto t = Resource::GetResource<ImageResource>("tree");
	StaticSprite* sprite = new StaticSprite(t);
	m_sprites.push_back(sprite);
	return 0;
}

void GameEngine::update()
{

}

void GameEngine::handle(int key)
{
	switch (key)
	{
	case 'w':
		break;
	case 's':
		break;
	case 'a':
		break;
	case 'd':
		break;
	}
}

void GameEngine::draw(Graphics & graphics)
{

	for (Sprite* it : m_sprites)
	{
		it->draw(graphics);
	}
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
