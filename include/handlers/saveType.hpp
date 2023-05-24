#pragma once

#include <stdint.h>
#include <string>
#include <vector>

#define SAVE_VERSION 0

typedef struct save {
    uint8_t version;
    std::string saveName; //used for saving the game again
}save;