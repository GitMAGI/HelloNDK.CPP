#include <iostream>
#include <chrono>
#include <thread>
#include "custom/util.h"
#include "custom/log.h"

int main(int argc, char* argv[]){
    #if defined _WIN64 || defined _WIN32
        // disable buffering, we want logs immediately
        // even line buffering (setvbuf() with mode _IOLBF) is not sufficient
        setbuf(stdout, NULL);
        setbuf(stderr, NULL);
    #endif
    
    std::chrono::high_resolution_clock::time_point st = std::chrono::high_resolution_clock::now();

    Log::infoLog("Application starting ...");

    std::this_thread::sleep_for(std::chrono::milliseconds(1123));

    end:
    std::chrono::high_resolution_clock::time_point et = std::chrono::high_resolution_clock::now();
    Log::infoLog("Application Completed. ETA %s", Util::getETA(st, et).c_str());

    return 0;
}