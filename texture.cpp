#include "texture.h"
#include "graphics.h"

Texture::Texture()
{
    texture = NULL;
    width = 0;
    height = 0;
}

Texture::~Texture()
{
    free();
}
//source :lazyfoo
bool Texture::loadFromFile(Graphics &graphics, char* fileName)
{
    bool success = true;
    free();
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(fileName);
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", fileName, IMG_GetError());
        success = false;
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(), loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", fileName, SDL_GetError());
            success = false;
        }
        else
        {
            width = loadedSurface->w;
            height = loadedSurface->h;
        }

        SDL_FreeSurface(loadedSurface);
    }
    texture = newTexture;
    return success;
}

void Texture::free()
{
    if (texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
        width = 0;
        height = 0;
    }
}


void Texture::render(Graphics &graphics, int x, int y)
{
    SDL_Rect areaToRender = { x, y, width, height };
    graphics.renderTexture(texture, &areaToRender);
}

int Texture::getWidth()
{
    return width;
}

int Texture::getHeight()
{
    return height;
}

SDL_Texture* Texture::getSDLTexture()
{
    return texture;
}
