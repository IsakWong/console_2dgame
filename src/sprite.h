#pragma once

#include "pch.h"

class Sprite
{
public:
	Sprite();

public:
	virtual void draw(Graphics& g) {};
	virtual void update(float delta_time) {};

};