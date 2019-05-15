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

class StaticSprite : public Sprite 
{
public:
	StaticSprite(ImageResource* resource);

public:
	void draw(Graphics& g) override;

private:
	ImageResource* m_image;

};