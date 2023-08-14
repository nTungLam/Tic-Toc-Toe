#ifndef MIXER_H
#define MIXER_H

#include <stdio.h>
#include "SDL.h"
#include "SDL_mixer.h"
#include<string>

class Graphics;

class Mixer
{
private:
    Mix_Music* music ;


public:
    Mixer();
    ~Mixer();
    bool loadMedia(); //haven't used return bool value yet!
    void free(); //deallocates texture
    Mix_Music* getMusic();
    void playMusic();


};

#endif //MIXER_H
