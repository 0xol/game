#include <raylib.h>
#include <handlers/stacktrace.hpp>
#include <handlers/gameThread.hpp>
#include <handlers/engineThread.hpp>

stacktraceHandler stacktrace;
gameThreadHandler gameThread;
engineThreadHandler engineThread;

int main(void) {
	//if (gameThread.startThread() != 0) {stacktrace.panic("gameThread failed to start\n");} //engineThread will start the gameThread when it is ready for game logic to be started
	//engineThread steals the thread that the application was started on
	engineThread.startThread();
	return 0;
};
