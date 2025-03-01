#include "Menu.h"

void GameSystem::Menu::initButtons()
{
	m_PlayButton = new Button(m_Renderer, "Play", "assets/TTF_Font/Pacifico.ttf");
	m_QuitButton = new Button(m_Renderer, "Quit", "assets/TTF_Font/Pacifico.ttf");
}

void GameSystem::Menu::setButtonProperty()
{
	m_PlayButton->setFontSize(50);
	m_QuitButton->setFontSize(50);
	// Play button 
	m_PlayButton->setPosition(100, 100);
	// Quit button
	m_QuitButton->setPosition(100, 400);

}

GameSystem::Menu::Menu(SDL_Renderer* p_Renderer)
	: m_Renderer(p_Renderer)
{
	initButtons();
	setButtonProperty();
	// later add texture to the Background and button 
}

void GameSystem::Menu::DisplayMenu()
{
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_Renderer);

	m_PlayButton->render();
	m_QuitButton->render();


	SDL_RenderPresent(m_Renderer);
}
// window for Gameover
void GameSystem::Menu::DisplayGameOver(std::string p_Winner)
{
	// do it later f


}

/*void GameSystem::Menu::Update()
{
}
*/

const Menu_State GameSystem::Menu::getMenuState() const
{
	SDL_Event event;
	if (SDL_WaitEvent(&event))
	{
		if (m_PlayButton->IsButtonClick(&event))
		{
			return Menu_State::PLAY;
		}
		else if (m_QuitButton->IsButtonClick(&event))
		{
			return Menu_State::QUIT;
		}
		if (event.type == SDL_QUIT)
			return Menu_State::QUIT;
	}
	return Menu_State::NONE;
}