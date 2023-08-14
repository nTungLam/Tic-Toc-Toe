#include "intro.h"
//khởi tạo
Intro::Intro(Graphics &graphics)
{
    if (!introImage.loadFromFile(graphics, "images/intro.jpg"))
        printf("Failed to initialize Intro!\n");
    nextStateID = STATE_NULL;
}
//cancel
Intro::~Intro()
{
    introImage.free();
}

void Intro::handleEvents(SDL_Event &e)
{

    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            requestStateChange(STATE_EXIT);
        }
        else if ((e.type == SDL_KEYDOWN) && (e.key.keysym.sym == SDLK_RETURN))
        {
            requestStateChange(STATE_TITLE);
        }
    }
}

void Intro::logic()
{
    if ( SDL_GetTicks() >= 5000 )
    {
        requestStateChange(STATE_TITLE);
    }
}

void Intro::render(Graphics &graphics)
{
    //draw
    introImage.render(graphics, 0, 0);
}
