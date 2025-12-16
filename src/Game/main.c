#include "TerminalEngine/Windows/Application.h"

int main() {
    Application app = {420, 120, "Game"};
    createApplication(&app);
    return runApplication(&app);
}