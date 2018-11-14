#include "GameStateManager.h"

GameStateManager::GameStateManager()
: gameWindow(sf::VideoMode(1440, 900, 32), "One More Sol",sf::Style::Titlebar | sf::Style::Close)

{
    initialize();
}

void GameStateManager::initialize()
{
    playView = new GameViewPlayer();
}

bool GameStateManager::gameViewIsOpen()
{
    bool quit;

    if (currentState == "Start")
    {
        quit = playView -> menuViewIsOpen(gameWindow);
        return quit;
    }
    if (currentState == "Play")
    {
        quit = playView -> gameViewIsOpen(gameWindow);
        cout << "Game View Left" << endl;
        cout << "Quit = " << quit << endl;
        return quit;
    }

    if (currentState == "Lost")
    {
        quit = playView -> lossViewIsOpen(gameWindow);
        return quit;
    }

}

void GameStateManager::setState(std::string state)
{
    currentState = state;
}
