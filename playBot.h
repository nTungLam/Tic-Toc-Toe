
#ifndef PLAYBOT_H
#define PLAYBOT_H
#include <stdlib.h>
#include<iostream>
#include "gameState.h"
#include "texture.h"
#include "board.h"
#include "graphics.h"
#include "button.h"

class PlayBot : public GameState
{
private:
    bool flag = true;
    Texture background;
    Texture X;
    Texture O;
    Texture Message_TurnX;
    Texture Message_TurnO;
    Texture Message_WinnerX;
    Texture Message_WinnerO;
    Texture Message_Tie;


    Button buttons[TOTAL_POSITIONS];


    Board board;
    PositionCoordinates playerMove;
    PositionCoordinates botMove;
    char turn;
    bool gameOver;

    void setUpButtons(Graphics &graphics);
public:
    PlayBot(Graphics &graphics);
    ~PlayBot();
    int whichButtonWasPressed();
    void switchTurns();
    void declareWinner(Graphics &graphics);
    void bot_Move() ;
    //Main loop functions
    void handleEvents(SDL_Event &e);
    void logic();
    void render(Graphics &graphics);
};

#endif //PLAYBOT_H

