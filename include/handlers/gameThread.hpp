#pragma once

#include <chrono>
#include <thread>

class gameThreadHandler {
    public:
        int startThread(void);
        void init(void);
};
extern gameThreadHandler gameThread;