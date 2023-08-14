#include "graphics.h"
#include "texture.h"
//khởi tạo
Graphics::Graphics()
{
    initSuccess = true;

    if (!init())
    {
        printf("Failed to initialize!\n");
        initSuccess = false;
    }
}
//cancel
Graphics::~Graphics()
{
    free();
}

bool Graphics::init()
{
    //khởi tạo
    bool success = true;

    //khởi tạo SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        //Create window
        window = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Create renderer for window
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}
//check
bool Graphics::initSucceeded()
{
    if (initSuccess)
        return true;
    else
        return false;
}
//cancel
void Graphics::free()
{
    //Destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
//trả về con trỏ
SDL_Renderer* Graphics::getRenderer() const
{
    return renderer;
}
//draw
void Graphics::renderTexture(SDL_Texture* texture, SDL_Rect* rect)
{
    SDL_RenderCopy(renderer, texture, NULL, rect);
}
