#include <handlers/gameThread.hpp>
#include <chrono>
#include <thread>
#include <handlers/stacktrace.hpp>

using namespace std;

int gameThreadHandler::startThread(void){
    
    thread test(&gameThreadHandler::init, this);
    
    return 0;
}

void gameThreadHandler::init(void) {
    stacktrace.panic("shitting myself from another thread\n");
}