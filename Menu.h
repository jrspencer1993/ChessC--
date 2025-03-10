#pragma once 
#include <string>
#include "Button.h"
#include "MenuDef.h"
#include <vector>

namespace GameSystem
{
	class Menu
	{
	public:
		Menu(SDL_Renderer* p_Renderer);
		void DisplayMenu();
		void DisplayGameOver(std::string p_Winner);
		void Update(SDL_Window* p_Window);

		const Menu_State getMenuState()const;

	private:
		void initButtons();
		void setButtonProperty();
		Button* m_PlayButton;
		Button* m_QuitButton;
		SDL_Renderer* m_Renderer;
		SDL_Event m_Event;
	};
};