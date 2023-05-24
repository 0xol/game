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
    }}
}

void engineThreadHandler::mainMenu(void) {
    BeginMode2D(mainMenuCam);

    if (!startMenuDone) {ImGui::SetNextWindowSize(ImVec2(512, 0)); cacheSaveFilenames(); startMenuDone = true;}

    ImGui::Begin("start menu", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
    
    //load save file
    ImGui::BeginChild("ScrollingRegion", ImVec2(0, 200), true, ImGuiWindowFlags_HorizontalScrollbar);
    for (const auto& file : cachedSaveFilenames) {
        if(ImGui::Selectable(file.c_str())) {
            std::cout << file << " selected\n";
            stacktrace.panic("[ERROR]: Save loaded, feature not implemented\n");
        }
    }
    ImGui::EndChild();
    
    //new save button
    if (ImGui::Button("New save", ImVec2(512, 100))) {
        newSave();
    }
    
    ImGui::End();
    EndMode2D();
}