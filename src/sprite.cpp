// pch.cpp: 与预编译标头对应的源文件；编译成功所必需的

#include "pch.h"
#include "sprite.h"
#include "resource.h"
// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。

StaticSprite::StaticSprite(ImageResource * resource)
	:m_image(resource)
{
}

void StaticSprite::draw(Graphics & g)
{
	RectF rect(0, 0, 200, 200);
	g.DrawImage(m_image->get_image(), 0, 0, 100, 100);
}

Sprite::Sprite()
{
}
