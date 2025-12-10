#include "Renderer.h"

void createRenderer(Renderer* renderer) {
    // 2D Array of unicode characters which acts as the screen buffer that will be printed on the console
    renderer->screen = (wchar_t*) malloc(sizeof(wchar_t) * renderer->screenWidth * renderer->screenHeight);
    // Create a handle to the console
    renderer->hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(renderer->hConsole);
}

void render(Renderer* renderer) {
    DWORD dwBytesWritten = 0;

    for(int y = 0; y < renderer->screenHeight; y++) {
        for(int x = 0; x < renderer->screenWidth; x++) {
            drawSolid(renderer, x, y);
            //renderer->screen[y*renderer->screenWidth + x] = '#';
        }
    }

    // Null terminate
    renderer->screen[renderer->screenWidth * renderer->screenHeight - 1] = '\0';
    static const COORD topRight = {0, 0};
    // Output screen buffer to console
    WriteConsoleOutputCharacterW(renderer->hConsole, renderer->screen, renderer->screenWidth * renderer->screenHeight, topRight, &dwBytesWritten);
}
    
void destroyRenderer(Renderer* renderer) {
    free(renderer->screen);
}

void draw(Renderer* renderer, Fragment* frag) {
    renderer->screen[renderer->screenWidth * frag->y + frag->x] = frag->type;
}

void drawSolid(Renderer* renderer, int x, int y) {
    Fragment frag = {x, y, 0x2588, 0};
    draw(renderer, &frag);
}