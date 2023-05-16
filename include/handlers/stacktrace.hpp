#pragma once

#include <stdint.h>
#include <string>

class stacktraceHandler {
    public:
        void printStackTrace(void);
        void panic(std::string error);
};
extern stacktraceHandler stacktrace;
