#include "button.h"

//khởi tạo
Button::Button()
{
    position.x = 0;
    position.y = 0;
    currentSpriteID = BUTTON_SPRITE_MOUSE_OUT;
    buttonWidth = 0;
    buttonHeight = 0;
}
//cancel
Button::~Button()
{
    buttonSpriteSheet.free();
}

void Button::loadTextureAndSprites(Graphics &graphics, char* fileName)
{
    buttonSpriteSheet.loadFromFile(graphics, fileName);
    for (int i = 0; i < BUTTON_SPRITE_TOTAL; i++)
    {
        spriteClips[i].x = 0;
        spriteClips[i].y = i * buttonHeight;
        spriteClips[i].h = buttonHeight;
        spriteClips[i].w = buttonWidth;
    }
}


bool Button::buttonWasPressed()
{
    if (currentSpriteID == BUTTON_SPRITE_MOUSE_DOWN)
    {
        return true;
    }
    else
        return false;
}


void Button::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

void Button::setDimensions(int width, int height)
{
    buttonWidth = width;
    buttonHeight = height;
}

void Button::handleEvent(SDL_Event &e)
{
    //If mouse event happened
    if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
    {
        //Mouse is outside the button
        if (!mouseInButton())
        {
            currentSpriteID = BUTTON_SPRITE_MOUSE_OUT;
        }
        //Mouse is inside button
        else
        {
            //Choose appropriate sprite
            switch (e.type)
            {
            case SDL_MOUSEMOTION:
                currentSpriteID = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                break;

            case SDL_MOUSEBUTTONDOWN:
                //FIX NEEDED: Account for case when mouse is being pressed down and moved at the same
                //            time.
                currentSpriteID = BUTTON_SPRITE_MOUSE_DOWN;
                break;

            case SDL_MOUSEBUTTONUP:
                currentSpriteID = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                break;
            }
        }

    }
}

//Returns true if the mouse is inside the button
bool Button::mouseInButton()
{
    //Get mouse position
    int x = 0, y = 0;
    SDL_GetMouseState(&x, &y);

    //check if mouse is in button
    bool inside = true;

    //Note: Remember that the top left corner of the button is at (0,0);
    //Mouse is left of the button
    if (x < position.x)
    {
        inside = false;
    }
    //Mouse is right of the button
    else if (x > position.x + buttonWidth)
    {
        inside = false;
    }
    //Mouse is above the button
    else if (y < position.y)
    {
        inside = false;
    }
    //Mouse is below the button
    else if (y > position.y + buttonHeight)
    {
        inside = false;
    }

    return inside;
}

void Button::render(Graphics &graphics)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { position.x, position.y,
                            buttonSpriteSheet.getWidth(), buttonSpriteSheet.getHeight()
                          };

    //Set clip rendering dimensions
    renderQuad.w = spriteClips[currentSpriteID].w;
    renderQuad.h = spriteClips[currentSpriteID].h;

    //Render current button sprite to screen
    SDL_RenderCopyEx(graphics.getRenderer(), buttonSpriteSheet.getSDLTexture(), &spriteClips[currentSpriteID],
                     &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
}
