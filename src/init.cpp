#include <raylib.h>
#include <handlers/stacktrace.hpp>

stacktraceHandler stacktrace;

int main(void) {
	InitWindow(100, 100, "Midnight");
	stacktrace.panic("ERROR\n");
	return 0;
};
