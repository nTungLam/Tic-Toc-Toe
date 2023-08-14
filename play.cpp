#include "play.h"
//khởi tạo
Play::Play(Graphics& graphics)
{
    //load images
    background.loadFromFile(graphics, "images/Tic Tac Toe grid.png");
    O.loadFromFile(graphics, "images/O.png");
    X.loadFromFile(graphics, "images/X.png");
    Message_TurnO.loadFromFile(graphics, "images/Player O's Turn.png");
    Message_TurnX.loadFromFile(graphics, "images/Player X's Turn.png");
    Message_WinnerO.loadFromFile(graphics, "images/Player O Wins.png");
    Message_WinnerX.loadFromFile(graphics, "images/Player X Wins.png");
    Message_Tie.loadFromFile(graphics, "images/tie.png");

    setUpButtons(graphics);

    turn = PLAYER_X;
    playerMove.positionID = -1;
    playerMove.coordinates = std::make_pair(0, 0);
    gameOver = false;
    nextStateID = STATE_NULL;
}
//cancel
Play::~Play()
{
    background.free();
    O.free();
    X.free();
    Message_TurnO.free();
    Message_TurnX.free();
    Message_WinnerO.free();
    Message_WinnerX.free();
    Message_Tie.free();

}


void Play::setUpButtons(Graphics &graphics)
{

    for (int i = 0; i < TOTAL_POSITIONS; i++)
    {
        buttons[i].setDimensions(105, 110);
        buttons[i].loadTextureAndSprites(graphics, "images/Button spritesheet.png");
    }

    buttons[POS_1].setPosition(35, 53);
    buttons[POS_2].setPosition(145, 53);
    buttons[POS_3].setPosition(255, 53);
    buttons[POS_4].setPosition(35, 165);
    buttons[POS_5].setPosition(145, 165);
    buttons[POS_6].setPosition(255, 165);
    buttons[POS_7].setPosition(35, 278);
    buttons[POS_8].setPosition(145, 278);
    buttons[POS_9].setPosition(255, 278);
}


int Play::whichButtonWasPressed()
{
    for (int POS_ID = 0; POS_ID < TOTAL_POSITIONS; POS_ID++)
    {
        if (buttons[POS_ID].buttonWasPressed())
        {
            return POS_ID;
        }
    }


    return OUTSIDE_BOARD;
}


void Play::switchTurns()
{
    if (turn == PLAYER_X)
        turn = PLAYER_O;
    else if (turn == PLAYER_O)
        turn = PLAYER_X;
}

void Play::declareWinner(Graphics &graphics)
{

    if (board.boardIsFull() && !board.won())
    {
        Message_Tie.render(graphics, 420, 10);
    }
    else if (turn == PLAYER_O)
    {
        Message_WinnerO.render(graphics, 420, 10);
    }

    else if (turn == PLAYER_X)
    {
        Message_WinnerX.render(graphics, 420, 10);
    }

    SDL_RenderPresent(graphics.getRenderer());
    SDL_Delay(1000);
}


void Play::handleEvents(SDL_Event &e)
{


    while (SDL_PollEvent(&e))
    {

        for (int i = 0; i < TOTAL_POSITIONS; i++)
        {
            buttons[i].handleEvent(e);
        }


        if (e.type == SDL_QUIT)
        {

            requestStateChange(STATE_EXIT);
        }


        else if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            //Check which button was pressed
            switch (whichButtonWasPressed())
            {
            case OUTSIDE_BOARD:
                break;
            case POS_1:
                playerMove = board.getPositionsOnBoard()[0];
                break;
            case POS_2:
                playerMove = board.getPositionsOnBoard()[1];
                break;
            case POS_3:
                playerMove = board.getPositionsOnBoard()[2];
                break;
            case POS_4:
                playerMove = board.getPositionsOnBoard()[3];
                break;
            case POS_5:
                playerMove = board.getPositionsOnBoard()[4];
                break;
            case POS_6:
                playerMove = board.getPositionsOnBoard()[5];
                break;
            case POS_7:
                playerMove = board.getPositionsOnBoard()[6];
                break;
            case POS_8:
                playerMove = board.getPositionsOnBoard()[7];
                break;
            case POS_9:
                playerMove = board.getPositionsOnBoard()[8];
                break;
            }

        }
    }
}


void Play::logic()
{

    if (gameOver)
    {
        requestStateChange(STATE_GAME_OVER);
    }
    else
    {

        if (board.isValidMove(playerMove.positionID))
        {
            board.makeMove(playerMove.positionID, turn);


            if (board.isGameOver())
                gameOver = true;
            else
                switchTurns();
        }

    }

}


void Play::render(Graphics &graphics)
{
    background.render(graphics, 0, 0);

    for (int i = 0; i < 9; i++)
    {
        if (board.getGameBoard()[i] == PLAYER_X)
        {
            X.render(graphics, board.getPositionsOnBoard()[i].coordinates.first,  // = x position
                     board.getPositionsOnBoard()[i].coordinates.second);// = y position
        } //x play
        else if (board.getGameBoard()[i] == PLAYER_O)
        {
            O.render(graphics, board.getPositionsOnBoard()[i].coordinates.first,   // = x position
                     board.getPositionsOnBoard()[i].coordinates.second); // = y position
        } //else if O play
    }

    //Render buttons
    for (int i = 0; i < TOTAL_POSITIONS; i++)
    {
        buttons[i].render(graphics);
    }

    //who has last turn
    if (gameOver)
    {
        declareWinner(graphics);
    } //If game over
    else
    {
        //show who'turn
        if (turn == PLAYER_X)
            Message_TurnX.render(graphics, 400, 15);
        else if (turn == PLAYER_O)
            Message_TurnO.render(graphics, 400, 15);
    }

}
