#include <iostream>
#include <chrono>

class Util{
    public:
        static std::string getETA(std::chrono::high_resolution_clock::time_point, std::chrono::high_resolution_clock::time_point);
        static std::string randomString(size_t);
        static std::string ssprintf(const char*, ...);
        static std::string getCurrentTimeStamp();
        static std::string getCurrentTimeStampForFileName();
};