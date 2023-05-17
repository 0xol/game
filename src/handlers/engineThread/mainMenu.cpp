#include <handlers/engineThread.hpp>
#include <raylib.h>
#include <iostream>
#include <external/rlImGui.h>
#include <external/imgui.h>
#include <filesystem>
#include <handlers/memoryFunc.hpp>
#include <vector>

bool startMenuDone = false;

std::vector<std::string> cachedSaveFilenames;

void cacheSaveFilenames();//will save them to cachedSaveFilenames

void engineThreadHandler::mainMenu(void) {
    BeginMode2D(mainMenuCam);

    if (!startMenuDone) {ImGui::SetNextWindowSize(ImVec2(512, 512)); startMenuDone = true;}

    ImGui::Begin("start menu", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

    ImGui::End();
    EndMode2D();
}