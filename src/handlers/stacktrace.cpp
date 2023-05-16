#include <handlers/stacktrace.hpp>
#include <iostream>
#include <string>

#ifndef _WIN32
#include <boost/stacktrace.hpp>
#endif

void stacktraceHandler::printStackTrace(void) {

    #ifdef _WIN32
    std::cout << "STACKTRACING NOT SUPPORTED ON WIN32" << std::endl;
    #else
    boost::stacktrace::stacktrace stackFrames = boost::stacktrace::stacktrace();
    std::cout << "DUMPING STACKTRACE INFO\n";

    for (boost::stacktrace::frame frame : stackFrames) {
        std::cout << "SYMBOL: " << frame.name() << "@" << frame.address() << std::endl;
    }
    #endif
}

void stacktraceHandler::panic(std::string error) {
    std::cout << error;
    printStackTrace();
    exit(1);
}