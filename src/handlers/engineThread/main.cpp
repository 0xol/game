#define RAYLIB_NUKLEAR_IMPLEMENTATION

#include <handlers/engineThread.hpp>
#include <raylib.h>
#include <iostream>
#include <handlers/stacktrace.hpp>

void engineThreadHandler::startThread(void) {
    InitWindow(1280, 720, "Midnight");
    SetTargetFPS(60);

    state = MAIN_MENU;

    //init mainMenuCam
    mainMenuCam.target.x = 0;
    mainMenuCam.target.y = 0;
    mainMenuCam.offset.x = 0 + (GetScreenWidth() / 2);
    mainMenuCam.offset.y = 0 + (GetScreenHeight() / 2);

    while (!WindowShouldClose() & (state != STOP)) {

        BeginDrawing();
        ClearBackground(WHITE);

        switch (state) {
        case MAIN_MENU:
        mainMenu();
        break;
        default:
        stacktrace.panic("[ERROR] engineHandlerThread::state is invalid\n");
        break;
        }

        EndDrawing();
    }
    CloseWindow();
    exitSafely();
}

float engineThreadHandler::deltaTime(void) {return GetFrameTime();}
void engineThreadHandler::stopThread(void) {state = STOP;}

void engineThreadHandler::exitSafely(void) {}