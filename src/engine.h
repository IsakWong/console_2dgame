#pragma once

#include "pch.h"
#include <thread>

class GameEngine
{

public:
	static GameEngine* instance();

	int init();
	int run();

	virtual void update();
	virtual void draw(Graphics& graphics);
protected:
	GameEngine();
	void update_loop();
	void draw_loop();
private:
	static GameEngine* m_instance;

	std::thread* update_thread;
	std::thread* draw_thread;

	HWND m_hwnd;
	Bitmap* m_screen_buffer;

	bool update_enable = true;
	bool draw_enable = true;
	int m_width;
	int m_height;

};