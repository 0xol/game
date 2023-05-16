#include <handlers/engineThread.hpp>
#include <raylib.h>
#include <iostream>
#include <external/rlImGui.h>
#include <external/imgui.h>

void engineThreadHandler::mainMenu(void) {
    BeginMode2D(mainMenuCam);

    ImGui::Begin("start menu", nullptr, ImGuiWindowFlags_MenuBar);

    ImGui::End();
    EndMode2D();
}