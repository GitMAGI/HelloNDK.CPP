#include <iostream>

enum class LogType
{
    LDEBUG = 0, 
    LINFO = 1,  
    LWARNING = 2,
    LERROR = 3,
    LCRITICAL = 4
};

class Log{
    private:
        static void writeLog(char*, const char*, LogType);
        static char* formatMessage(char*, ...);
    public:
        static void debugLog_(const char*, const char *, ...);
        static void infoLog_(const char*, const char *, ...);
        static void warningLog_(const char*, const char *, ...);
        static void errorLog_(const char*, const char *, ...);
        static void criticalLog_(const char*, const char *, ...);   
};

#define debugLog(format, ...) Log::debugLog_(__FUNCTION__, format, ##__VA_ARGS__)
#define infoLog(format, ...) Log::infoLog_(__FUNCTION__, format, ##__VA_ARGS__)
#define warningLog(format, ...) Log::warningLog_(__FUNCTION__, format, ##__VA_ARGS__)
#define errorLog(format, ...) Log::errorLog_(__FUNCTION__, format, ##__VA_ARGS__)
#define criticalLog(format, ...) Log::criticalLog_(__FUNCTION__, format, ##__VA_ARGS__)     