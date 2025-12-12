#include <Windows.h>
#include <time.h>
#include "Application.h"
#include "Input.h"
#include "TerminalEngine/Renderer/Renderer.h"

bool createApplication(Application* app) {
    SetConsoleTitle(app->title);
    return true;
}

bool runApplication(Application* app) {
    Renderer renderer = {app->screenWidth, app->screenHeight, NULL};
    createRenderer(&renderer);

    int oldTime = clock();

    double x = 0;

    // Game Loop
    while(true) {
        int deltaTime = clock() - oldTime;
        oldTime = clock();

        x += deltaTime * 0.01f;

        // Scene Drawing
        clear(&renderer);

        Vec2 pA = {15.0f, 10.0f + (int)(10 * sin(x))};
        Vec2 pB = {80.0f + (int)(10 * sin(x)), 30.0f};
        drawLine(&renderer, &pA, &pB);

        // End Scene
        render(&renderer);
    }

    destroyRenderer(&renderer);
}
