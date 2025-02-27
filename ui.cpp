#include "UI.h"

void GameSystem::UI::init_UI(SDL_Renderer* ren, SDL_Color color, SDL_Rect rect)
{
	UI_Renderer = ren;
	UI_Color = color;
	UI_Box = rect;
}
// setter 
void GameSystem::UI::setColor(int r, int g, int b, int a)
{
	UI_Color.r = r;
	UI_Color.g = g;
	UI_Color.b = b;
	UI_Color.a = a;
}

void GameSystem::UI::setPosition(int x, int y)
{
	UI_Box.x = x;
	UI_Box.y = y;
}

void GameSystem::UI::setSize(int w, int h)
{
	UI_Box.w = w;
	UI_Box.h = h;
}
// getter
SDL_Rect GameSystem::UI::getRect() const
{
	return UI_Box;
}