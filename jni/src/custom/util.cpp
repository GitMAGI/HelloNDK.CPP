#include <iostream>
#include <chrono>
#include <string>
#include <memory>
#include <cstdarg>
#include <cmath>
#include "util.h"

std::string Util::ssprintf(const char* format, ...)
{
    va_list argptr;

    va_start(argptr, format);
    size_t bufsz = vsnprintf(NULL, 0, format, argptr);
	char* buf = (char*)malloc(sizeof(char) * (bufsz + 1));
    vsnprintf(buf, bufsz + 1, format, argptr);
    va_end(argptr);

    //fprintf(stdout, "%s\n", buf);

    return buf;
}

std::string Util::getETA(std::chrono::high_resolution_clock::time_point start, std::chrono::high_resolution_clock::time_point end){
    int usecs = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    int secs = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

    uint32_t out_usecs = (uint32_t)(usecs % 1000);
    uint32_t out_msecs = (uint32_t)((usecs / 1000) % 1000);
    uint32_t out_secs = (uint32_t)(secs % 60);
    uint32_t out_mins = (uint32_t)((secs / 60) % 60);
    uint32_t out_hrs = (uint32_t)(secs / 3600);

    //fprintf(stdout, "%d hrs %02d mins %02d secs %03d ms %03d us\n", out_hrs, out_mins, out_secs, out_msecs, out_usecs);
    std::string out = Util::ssprintf("%d hrs %02d mins %02d secs %03d ms %03d us", out_hrs, out_mins, out_secs, out_msecs, out_usecs);

    //fprintf(stdout, "%s\n", out);

    return out;
}

std::string Util::randomString(size_t size)
{
    std::string str = "";

    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str += charset[key];
        }
        str += '\0';
    }
    return str;
}

std::string Util::getCurrentTimeStamp(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	const char *format = "%d-%02d-%02d %02d:%02d:%02d";	
	return Util::ssprintf(format, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

std::string Util::getCurrentTimeStampForFileName(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	const char *format = "%d-%02d-%02d";
	return Util::ssprintf(format, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}