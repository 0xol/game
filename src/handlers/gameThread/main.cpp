#include <handlers/gameThread.hpp>
#include <chrono>
#include <thread>
#include <handlers/stacktrace.hpp>
#include <iostream>

using namespace std;

bool shutdownGameThread = false;

#define TICKFRAME_MS 16.66 //slightly less than the full time frame
#define TICKFRAME_NS TICKFRAME_MS * 1000000

int gameThreadHandler::startThread(void){
    thread test(&gameThreadHandler::init, this);
    test.detach();

    return 0;
}

void gameThreadHandler::init() {
    while (!shutdownGameThread) {
        auto tickStart = chrono::high_resolution_clock::now();

        //do sctuhc here

        auto tickEnd = std::chrono::high_resolution_clock::now();
        auto tickDuration = chrono::duration_cast<chrono::nanoseconds>(tickEnd - tickStart);

        long long sleepTime = TICKFRAME_NS - tickDuration.count();
        if (sleepTime > 0) {
            this_thread::sleep_for(chrono::nanoseconds(sleepTime));
        }
        else {
            //game tick took more than 16.66ms
        }
    }
}