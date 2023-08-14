#ifndef BOARD_H
#define BOARD_H
#include <utility>
#include "SDL.h"

#define EMPTY_SPACE '*'
#define PLAYER_X 'x'
#define PLAYER_O 'o'


/*
Sử dụng mảng 1 chiều để lưu vị trí các ô theo thứ tự sau :
   1|2|3
   -----
   4|5|6
   -----
   7|8|9

*/
enum BoardPositionIDs
{
    POS_1, //0
    POS_2,
    POS_3,
    POS_4,
    POS_5,
    POS_6,
    POS_7,
    POS_8,
    POS_9,
    TOTAL_POSITIONS = 9,
    OUTSIDE_BOARD = -1, //xử lý các vị trí ngoài board
};

//Position coordinates (x,y) lưu vị trí các ô trên board và ID của chúng
struct PositionCoordinates
{
    int positionID;
    std::pair <int, int> coordinates; //<x,y>
    PositionCoordinates();
};


class Board
{
private:
    char gameBoard[9];
    PositionCoordinates positionsOnBoard[9];

public:
    Board();
    ~Board();
    bool isGameOver();
    PositionCoordinates* getPositionsOnBoard();
    char* getGameBoard();

    //Functions for checking if game is over
    bool won();
    bool allEqual(char A, char B, char C);
    bool rowWin();
    bool columnWin();

    bool diagonalWin();
    bool leftDiagonalWin();
    bool rightDiagonalWin();

    bool boardIsFull();
    char checkBoard(int move);
    //kiểm tra ô này đã được đánh chưa
    bool isValidMove(int move);
    void makeMove(int move, char turn);

};

#endif //BOARD_H
