#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


class Texture;

class Graphics
{
private:
    //chỉ ra việc khởi tạo thành công hay ko
    bool initSuccess;
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    Graphics();
    ~Graphics();
    bool init();
    bool initSucceeded();
    void free();

    SDL_Renderer* getRenderer() const;

    //đưa ảnh vào 1 ô rect trên màn hình
    void renderTexture(SDL_Texture* texture, SDL_Rect* rect); //calls SDL_RenderCopy

};

#endif //GRAHIPCS_H
