//1 abstract class quản lý các bước của chương trình :title,gameplay..

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "SDL.h"

class Graphics;

enum GameStates
{
    STATE_NULL,
    STATE_TITLE,
    STATE_PLAY,
    STATE_PLAY_BOT,
    STATE_GAME_OVER,
    STATE_EXIT,
};

class GameState
{
protected:

    int nextStateID;
public:
    //dùng khi muốn chuyển sang state kế tiếp
    int getNextStateID()
    {
        return nextStateID;
    }
    // khi cần chuyển state hàm này sẽ được gọi để đưa giá trị mới cho newstateID
    void requestStateChange(int newStateID)
    {
        nextStateID = newStateID;
    }

    //Main loop functions
    virtual void handleEvents(SDL_Event &e) = 0;
    virtual void logic() = 0;
    virtual void render(Graphics &graphics) = 0;
    virtual ~GameState() {};
};

#endif //GAME_STATE_H
