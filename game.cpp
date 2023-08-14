#include "game.h"
//khởi tạo
Game::Game()
{
    currentState = NULL;
    currentStateID = STATE_NULL;
    nextState = STATE_NULL;
}
//cancel
Game::~Game()
{
    graphics.free();
    delete currentState;
}
//check
bool Game::initSucceeded()
{
    if (graphics.initSucceeded())
        return true;
    else
        return false;
}

//Main game loop
void Game::gameLoop()
{


    currentStateID = STATE_TITLE;
    nextState = STATE_NULL;

    currentState = new Title(graphics);


    SDL_Event e;


    while (currentStateID != STATE_EXIT)
    {
        if(a.loadMedia()== true)
        {
            a.playMusic();
        }

        currentState->handleEvents(e);


        currentState->logic();


        nextState = currentState->getNextStateID();
        if(nextState != STATE_NULL)
            changeState();
        currentState->render(graphics);
        draw();

    }
}


void Game::changeState()
{

    if (nextState != STATE_NULL)
    {

        if (nextState != STATE_EXIT)
        {
            delete currentState;
        }
        switch (nextState)
        {
        case STATE_TITLE:
            currentState = new Title(graphics);
            break;
        case STATE_PLAY:
            currentState = new Play(graphics);
            break;
        case STATE_PLAY_BOT:
            currentState = new PlayBot(graphics);
            break;
        case STATE_GAME_OVER:
            currentState = new GameOver(graphics);
            break;
        }

        currentStateID = nextState;
        nextState = STATE_NULL;
    }
}

//Updates the screen
void Game::draw()
{
    //Clear screen
    SDL_SetRenderDrawColor(graphics.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(graphics.getRenderer());

    //Render background texture to screen
    currentState->render(graphics);

    //Update screen ->This is what displays what was drawn/rendered
    SDL_RenderPresent(graphics.getRenderer());
}


