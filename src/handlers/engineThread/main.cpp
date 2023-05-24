#define RAYLIB_NUKLEAR_IMPLEMENTATION

#include <handlers/engineThread.hpp>
#include <raylib.h>
#include <iostream>
#include <handlers/stacktrace.hpp>
#include <external/rlImGui.h>
#include <external/imgui.h>

void engineThreadHandler::startThread(void) {
    InitWindow(1280, 720, "Midnight");
    SetTargetFPS(60);
    rlImGuiSetup(true);

    state = MAIN_MENU;

    //init mainMenuCam
    mainMenuCam.target.x = 0;
    mainMenuCam.target.y = 0;
    mainMenuCam.offset.x = 0 + (GetScreenWidth() / 2);
    mainMenuCam.offset.y = 0 + (GetScreenHeight() / 2);

    while (!WindowShouldClose() & (state != STOP)) {
        BeginDrawing();
        ClearBackground(GRAY);
        rlImGuiBegin();

        switch (state) {
        case MAIN_MENU:
        mainMenu();
        break;
        case GAME:
        
        break;
        default:
        stacktrace.panic("[ERROR] engineHandlerThread::state is invalid\n");
        break;
        }

        rlImGuiEnd();
        EndDrawing();
    }
    rlImGuiShutdown();
    CloseWindow();
    exitSafely();
}

float engineThreadHandler::deltaTime(void) {return GetFrameTime();}
void engineThreadHandler::stopThread(void) {state = STOP;}

void engineThreadHandler::exitSafely(void) {}