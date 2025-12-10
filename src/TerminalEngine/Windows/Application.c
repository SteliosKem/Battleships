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

    // Game Loop
    while(true) {
        int deltaTime = clock() - oldTime;
        oldTime = clock();

        render(&renderer);
    }

    destroyRenderer(&renderer);
}
