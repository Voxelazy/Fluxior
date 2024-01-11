#pragma once

#include <iostream>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

namespace Sling
{
    class Text
    {
    public:
        // Constructor & Destructor
        Text();
        virtual ~Text();

        // Verifies If The Type Of Font Exists
        bool Verify();

        // Creates Image From Font String
        void LoadFont(const char *filePath, int size);

        // Creates A Text Out Of The Loaded Font
        void CreateText(const char *input, SDL_Renderer *Ren);

        // Sets Up The Font To Whatever The User Types
        void SetPos(int xpos, int ypos);

        // Set Color Modulation
        void SetColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);

        // Renders The Text
        void Render();

        // Destroys The Font Texture
        void Destroy();
        
    private:
        // Font Variables
        static inline SDL_Renderer *renderer;
        static inline TTF_Font *font;
        static inline SDL_Color color;
        static inline SDL_Surface *surface;
        static inline SDL_Texture *texture;

        SDL_Rect axisRect;
    };
}