#pragma once

#include "pch.h"
#include <thread>
#include <list>
#include "math/2d_math.h"

enum class  KeyCode : unsigned int
{
	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	H,
	J,
	K,
	L,
	Z,
	X,
	C,
	V,
	B,
	N,
	M
};

class DrawContext
{
public:
	vector2f eye_pos;

	float window_width;
	float window_height;

};

class GameEngine
{

public:
	static GameEngine* instance();

	int init();
	int run();
	int load_resources();

	virtual void update();
	virtual void handle(int key);
	virtual void draw(Graphics& graphics);

	HHOOK m_hook = NULL;
protected:

	GameEngine();
	void update_loop();
	void draw_loop();

private:


	static GameEngine* m_instance;

	std::thread* update_thread;
	std::thread* draw_thread;

	std::list<Sprite*> m_sprites;

	HWND m_hwnd;
	Bitmap* m_screen_buffer;
	DrawContext m_draw_context;
	bool update_enable = true;
	bool draw_enable = true;
	int m_width;
	int m_height;

};