//inits gameThread memory areas with a blank save

#include <handlers/saveType.hpp>
#include <handlers/gameThread.hpp>
#include <handlers/engineThread.hpp>
#include <handlers/stacktrace.hpp>

void engineThreadHandler::newSave(void) {
    state = GAME;
    if (gameThread.startThread() != 0) {stacktrace.panic("[ERROR] gameThread refused to start\n");}
}