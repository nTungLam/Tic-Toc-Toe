#ifndef BUTTON_H
#define BUTTON_H

#include "texture.h"
#include "graphics.h"


enum ButtonSprite
{
    BUTTON_SPRITE_MOUSE_OUT,      //Mouse is outside the button
    BUTTON_SPRITE_MOUSE_OVER_MOTION, //Mouse is over the button
    BUTTON_SPRITE_MOUSE_DOWN,        //Button has been pressed on
    BUTTON_SPRITE_TOTAL,             //Total number of sprites
};

class Button
{
private:
    Texture buttonSpriteSheet;
    SDL_Rect spriteClips[BUTTON_SPRITE_TOTAL];
    SDL_Point position;
    int currentSpriteID;
    int buttonWidth;
    int buttonHeight;
public:
    Button();
    ~Button();
    bool buttonWasPressed();


    void setPosition(int x, int y);
    void setDimensions(int width, int height);
    void loadTextureAndSprites(Graphics &graphics, char* fileName);


    void handleEvent(SDL_Event &e);
    bool mouseInButton();

    void render(Graphics &grahpics);
};

#endif //BUTTON_H
