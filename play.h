#ifndef PLAY_H
#define PLAY_H
#include <stdlib.h>
#include "gameState.h"
#include "texture.h"
#include "board.h"
#include "graphics.h"
#include "button.h"

class Play : public GameState
{
private:
    Texture background;
    Texture X;
    Texture O;
    Texture Message_TurnX;
    Texture Message_TurnO;
    Texture Message_WinnerX;
    Texture Message_WinnerO;
    Texture Message_Tie;

    //Buttons: có 9 button trên board
    Button buttons[TOTAL_POSITIONS];


    Board board; //board  3x3
    PositionCoordinates playerMove; //chứa Position ID
    char turn;
    bool gameOver;

    void setUpButtons(Graphics &graphics);
public:

    Play(Graphics &graphics);
    ~Play();
    int whichButtonWasPressed(); // trả về ID của các button được nhấn trên board
    //đổi lượt
    void switchTurns();
    void declareWinner(Graphics &graphics);

    //Main loop functions
    void handleEvents(SDL_Event &e);
    void logic();
    void render(Graphics &graphics);
};

#endif //PLAY_H
