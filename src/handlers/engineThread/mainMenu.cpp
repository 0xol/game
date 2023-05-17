#include <handlers/engineThread.hpp>
#include <handlers/stacktrace.hpp>
#include <raylib.h>
#include <iostream>
#include <external/rlImGui.h>
#include <external/imgui.h>
#include <filesystem>
#include <handlers/memoryFunc.hpp>
#include <vector>

bool startMenuDone = false;

std::vector<std::string> cachedSaveFilenames;

void cacheSaveFilenames() { //will save them to cachedSaveFilenames
    cachedSaveFilenames.clear();
    if (!std::filesystem::is_directory("saves")) {std::filesystem::create_directories("saves");}
    if (!std::filesystem::is_directory("saves")) {stacktrace.panic("[ERROR] mainMenu.cpp: cachedSaveFilenames: could not make 'saves' dir");}

    for (auto file : std::filesystem::directory_iterator("saves")) {if (file.path().extension() == ".sav") {
        cachedSaveFilenames.push_back(file.path().filename().string());
        std::cout << file.path().filename().string() << std::endl;
    }}
}

void engineThreadHandler::mainMenu(void) {
    BeginMode2D(mainMenuCam);

    if (!startMenuDone) {ImGui::SetNextWindowSize(ImVec2(512, 512)); cacheSaveFilenames(); startMenuDone = true;}

    ImGui::Begin("start menu", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
    ImGui::BeginChild("ScrollingRegion", ImVec2(0, 0), true, ImGuiWindowFlags_HorizontalScrollbar);
    
    for (const auto& file : cachedSaveFilenames) {
        ImGui::Text("%s", file.c_str());
    }
    /*
    
        if (ImGui::Selectable(file.c_str(), false, ImGuiSelectableFlags_AllowDoubleClick)) {
            if (ImGui::IsMouseDoubleClicked(0)) {
                std::cout << file << "selected" << std::endl;
            }
            
        }
    }
    */

    ImGui::EndChild();
    ImGui::End();
    EndMode2D();
}