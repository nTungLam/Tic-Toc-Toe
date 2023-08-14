#ifndef TEXTURE_H
#define TEXTURE_H

#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"

class Graphics;

class Texture
{
private:

    SDL_Texture* texture;

    //image dimensions
    int width;
    int height;

public:
    Texture();
    ~Texture();
    bool loadFromFile(Graphics &graphics, char* fileName);
    void free();
    //render texture taị tọa độ (x,y)
    void render(Graphics &graphics, int x, int y);

    int getWidth();
    int getHeight();
    SDL_Texture* getSDLTexture();

};

#endif //TEXTURE_H
