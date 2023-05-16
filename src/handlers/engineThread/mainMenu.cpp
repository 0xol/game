#include <handlers/engineThread.hpp>
#include <raylib.h>
#include <iostream>

void engineThreadHandler::mainMenu(void) {
    BeginMode2D(mainMenuCam);

    EndMode2D();
}