#ifndef TE_RENDERER_H
#define TE_RENDERER_H

#include <Windows.h>

typedef struct Renderer {
    int screenWidth;
    int screenHeight;
    wchar_t* screen;
    HANDLE hConsole;
} Renderer;

// Initializes the renderer struct.
void createRenderer(Renderer* renderer);

// Outputs to the terminal.
void render(Renderer* render);

// Frees memory held by the struct.
void destroyRenderer(Renderer* renderer);

#endif