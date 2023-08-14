
#include "mixer.h"
#include "graphics.h"
//khởi tạo
Mixer::Mixer()
{


    music = NULL;
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        //   success = false;
    }
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        //     success = false;
    }
}

Mixer::~Mixer()
{
    free();
}

bool Mixer::loadMedia()
{
    //khởi tạo
    bool success = true;

    //Load music
    music = Mix_LoadMUS( "music.wav" );
    if( music == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    return success;
}
//cancel
void Mixer::free()
{
    if (music != NULL)
    {
        Mix_FreeMusic( music );
        music = NULL;
    }
}
//trả về con trỏ
Mix_Music* Mixer::getMusic()
{
    return music;
}
//reload music
void Mixer::playMusic()
{
    if( Mix_PlayingMusic() == 0 )
    {
        //repeat
        Mix_PlayMusic( music, -1 );
    }
}
