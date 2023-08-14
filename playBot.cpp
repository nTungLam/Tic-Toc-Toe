
#include "playBot.h"
#include<vector>
PlayBot::PlayBot(Graphics& graphics)
{

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
    botMove.positionID = -1;
    botMove.coordinates = std::make_pair(0,0);
    gameOver = false;
    nextStateID = STATE_NULL;
}


PlayBot::~PlayBot()
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

void PlayBot::setUpButtons(Graphics &graphics)
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

int PlayBot::whichButtonWasPressed()
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

void PlayBot::switchTurns()
{
    if (turn == PLAYER_X)
        turn = PLAYER_O;
    else if (turn == PLAYER_O)
        turn = PLAYER_X;
}

void PlayBot::declareWinner(Graphics &graphics)
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

void PlayBot::bot_Move()
{    botMove.positionID = -1;
    if( board.checkBoard(4)==EMPTY_SPACE && (board.checkBoard(0) == PLAYER_X ||board.checkBoard(1) == PLAYER_X || board.checkBoard(2) == PLAYER_X||board.checkBoard(3) == PLAYER_X||
            board.checkBoard(5) == PLAYER_X|| board.checkBoard(6) == PLAYER_X || board.checkBoard(7) == PLAYER_X||board.checkBoard(8) == PLAYER_X))
    {
        botMove = board.getPositionsOnBoard()[4];
    }
    if( board.checkBoard(4) == PLAYER_X && board.checkBoard(0) == EMPTY_SPACE && board.checkBoard(1) == EMPTY_SPACE && board.checkBoard(2) == EMPTY_SPACE&&board.checkBoard(3) == EMPTY_SPACE &&
            board.checkBoard(5) == EMPTY_SPACE && board.checkBoard(6) == EMPTY_SPACE && board.checkBoard(7) == EMPTY_SPACE && board.checkBoard(8) && EMPTY_SPACE)
    {
        botMove = board.getPositionsOnBoard()[0];
    }

    for(int i=0 ; i<7 ; i=i+3)
    {
        if(board.checkBoard(i) == PLAYER_X  && board.checkBoard(i+1) == PLAYER_X && board.checkBoard(i+2) == EMPTY_SPACE)
        {
            botMove = board.getPositionsOnBoard()[i+2];
        }
        if(board.checkBoard(i+1) == PLAYER_X  && board.checkBoard(i+2) == PLAYER_X && board.checkBoard(i) == EMPTY_SPACE)
        {
            botMove = board.getPositionsOnBoard()[i];
        }
        if(board.checkBoard(i) == PLAYER_X  && board.checkBoard(i+2) == PLAYER_X && board.checkBoard(i+1) == EMPTY_SPACE)
        {
            botMove = board.getPositionsOnBoard()[i+1];
        }
    }
    for(int i=0 ; i<3 ; i=i+1)
    {
        if(board.checkBoard(i) == PLAYER_X  && board.checkBoard(i+3) == PLAYER_X && board.checkBoard(i+6) == EMPTY_SPACE)
        {
            botMove = board.getPositionsOnBoard()[i+6];
        }
        if(board.checkBoard(i+3) == PLAYER_X  && board.checkBoard(i+6) == PLAYER_X && board.checkBoard(i) == EMPTY_SPACE)
        {
            botMove = board.getPositionsOnBoard()[i];
        }
        if(board.checkBoard(i) == PLAYER_X  && board.checkBoard(i+6) == PLAYER_X && board.checkBoard(i+3) == EMPTY_SPACE)
        {
            botMove = board.getPositionsOnBoard()[i+3];
        }
    }
    if(board.checkBoard(0) == PLAYER_X  && board.checkBoard(4) == PLAYER_X && board.checkBoard(8) == EMPTY_SPACE)
    {
        botMove = board.getPositionsOnBoard()[8];
    }
    if(board.checkBoard(4) == PLAYER_X  && board.checkBoard(8) == PLAYER_X && board.checkBoard(0) == EMPTY_SPACE)
    {
        botMove = board.getPositionsOnBoard()[0];
    }
    if(board.checkBoard(0) == PLAYER_X  && board.checkBoard(8) == PLAYER_X && board.checkBoard(4) == EMPTY_SPACE)
    {
        botMove = board.getPositionsOnBoard()[4];
    }

    if(board.checkBoard(2) == PLAYER_X  && board.checkBoard(4) == PLAYER_X && board.checkBoard(6) == EMPTY_SPACE)
    {
        botMove = board.getPositionsOnBoard()[6];
    }
    if(board.checkBoard(4) == PLAYER_X  && board.checkBoard(6) == PLAYER_X && board.checkBoard(2) == EMPTY_SPACE)
    {
        botMove = board.getPositionsOnBoard()[2];
    }
    if(board.checkBoard(2) == PLAYER_X  && board.checkBoard(6) == PLAYER_X && board.checkBoard(4) == EMPTY_SPACE)
    {
        botMove = board.getPositionsOnBoard()[4];
    }


}
/*
void PlayBot::bot_Move()
{

    srand(static_cast<unsigned int>(time(nullptr)));


    std::vector<int> availablePositions;
    for (int i = 0; i < TOTAL_POSITIONS; i++)
    {
        if (board.checkBoard(i) == EMPTY_SPACE)
        {
            availablePositions.push_back(i);
        }
    }


    if (!availablePositions.empty())
    {
        int randomIndex = rand() % availablePositions.size();
        botMove = board.getPositionsOnBoard()[availablePositions[randomIndex]];
    }
    else
    {

        botMove.positionID = -1;
    }
}
*/

void PlayBot::handleEvents(SDL_Event &e)
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
            //neu nguoi choi khong chon o giua


        }
        bot_Move();



    }
}
/*
void PlayBot::handleEvents(SDL_Event &e)
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
            int clickedPosition = whichButtonWasPressed();
            if (clickedPosition != OUTSIDE_BOARD)
            {
                if (board.isValidMove(clickedPosition))
                {
                    playerMove = board.getPositionsOnBoard()[clickedPosition];
                    bot_Move(); // Calculate bot's move
                }
            }
        }
    }
}

*/
void PlayBot::logic()
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
        else if(board.isValidMove(botMove.positionID))
        {
            board.makeMove(botMove.positionID, turn);

            if (board.isGameOver())
                gameOver = true;
            else
                switchTurns();
        }
    }

}
/*
void PlayBot::logic()
{
    if (gameOver)
    {
        requestStateChange(STATE_GAME_OVER);
    }
    else
    {
        if (turn == PLAYER_X)
        {
            if (board.isValidMove(playerMove.positionID))
            {
                board.makeMove(playerMove.positionID, turn);
                if (board.isGameOver())
                {
                    gameOver = true;
                }
                else
                {
                    switchTurns();
                    bot_Move(); // Calculate bot's move after player's move
                    if (board.isValidMove(botMove.positionID))
                    {
                        board.makeMove(botMove.positionID, turn);
                        if (board.isGameOver())
                        {
                            gameOver = true;
                        }
                        else
                        {
                            switchTurns();
                        }
                    }
                }
            }
        }
    }
}
*/

void PlayBot::render(Graphics &graphics)
{
    background.render(graphics, 0, 0);


    for (int i = 0; i < 9; i++)
    {
        if (board.getGameBoard()[i] == PLAYER_X)
        {
            X.render(graphics, board.getPositionsOnBoard()[i].coordinates.first,
                     board.getPositionsOnBoard()[i].coordinates.second);
        }
        else if (board.getGameBoard()[i] == PLAYER_O)
        {
            O.render(graphics, board.getPositionsOnBoard()[i].coordinates.first,
                     board.getPositionsOnBoard()[i].coordinates.second);
        }
    }


    for (int i = 0; i < TOTAL_POSITIONS; i++)
    {
        buttons[i].render(graphics);
    }
    if (gameOver)
    {
        declareWinner(graphics);
    }
    else
    {

        if (turn == PLAYER_X)
            Message_TurnX.render(graphics, 400, 15);
        else if (turn == PLAYER_O)
            Message_TurnO.render(graphics, 400, 15);
    }

}

