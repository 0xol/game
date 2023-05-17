#include <handlers/memoryFunc.hpp>
#include <handlers/stacktrace.hpp>
#include <cstring>
#include <stdint.h>

void* resizeArray(void* array, uint64_t cur_size, uint64_t new_size) {
    if (cur_size > new_size) {stacktrace.panic("[ERROR] memoryFunc.cpp: resizeArray: cur_size > new_size\n");}
    
    unsigned char* temp = new unsigned char[new_size];

    std::memcpy(temp, array, cur_size);
    
    return temp;
}