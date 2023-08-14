#include "gameOver.h"
//khởi tạo
GameOver::GameOver(Graphics &graphics)
{
    if (!gameOverScreen.loadFromFile(graphics, "images/Game Over.png"))
        printf("Failed to load Title Screen!\n");
    nextStateID = STATE_NULL;
}
//cancel
GameOver::~GameOver()
{
    gameOverScreen.free();
}

void GameOver::handleEvents(SDL_Event &e)
{

    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            requestStateChange(STATE_EXIT);
        }
//enter
        else if ((e.type == SDL_KEYDOWN) && (e.key.keysym.sym == SDLK_RETURN))
        {
            requestStateChange(STATE_TITLE);
        }
//backspace
        else if ((e.type == SDL_KEYDOWN) && (e.key.keysym.sym == SDLK_BACKSPACE))
        {
            requestStateChange(STATE_EXIT);
        }
    }
}

void GameOver::logic()
{
}

void GameOver::render(Graphics &graphics)
{
    gameOverScreen.render(graphics, 0, 0);
}
