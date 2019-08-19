#include "log.h"
#include "util.h"
#include "config.h"
#include <string>
#include <cstdarg>

void Log::writeLog(char* msg, const char* scope, LogType type){
    const char* str = "DEBUG";
    FILE* std = stdout;
	switch(type)
    {
		case LogType::LDEBUG: 
			str = "DEBUG"; 
            std = stdout;       
			break;
		case LogType::LINFO: 
			str = "INFO";
            std = stdout;
			break;
		case LogType::LWARNING: 
			str = "WARNING";
            std = stdout;
			break;
		case LogType::LERROR: 
			str = "ERROR";
            std = stderr;
			break;
		case LogType::LCRITICAL: 
			str = "CRITICAL";
            std = stderr;
			break;
        default:
            str = "DEBUG";
            std = stdout;
    }

    std::string toLog = Util::ssprintf("%s | %s | %s | %s() >>> %s\n", Util::getCurrentTimeStamp().c_str(), str, APPNAME, scope, msg);
    fprintf(std, "%s", toLog.c_str());

    #if defined LOGFILEPATH
        char* fileextension = "log";
        char* filepath = LOGFILEPATH;
        char* filejustname = Util::getCurrentTimeStampForFileName().c_str();

        char* filename = ssprintf("%s%s.%s", filepath, filejustname, fileextension);
		if(!directoryExists(filepath))
			createPath(filepath);

        FILE *fp = fopen(filename, "ab+");
        if(fp){            
            fprintf(fp, toLog);
        }
        else{
			fprintf(stderr, "Logging Error on file %s\n", filename);
        }
    #endif
}

void Log::debugLog_(const char* caller, const char * format, ...)
{
	char * msg = (char*)format;
    va_list argptr;
    va_start(argptr, format);
    size_t bufsz = vsnprintf(NULL, 0, format, argptr);
	msg = (char*)malloc(sizeof(char) *(bufsz + 1));
    vsnprintf(msg, bufsz + 1, format, argptr);
    va_end(argptr);
	
	Log::writeLog(msg, caller, LogType::LWARNING);
}

void Log::infoLog_(const char* caller, const char * format, ...)
{
	char * msg = (char*)format;
    va_list argptr;
    va_start(argptr, format);
    size_t bufsz = vsnprintf(NULL, 0, format, argptr);
	msg = (char*)malloc(sizeof(char) *(bufsz + 1));
    vsnprintf(msg, bufsz + 1, format, argptr);
    va_end(argptr);
	
	Log::writeLog(msg, caller, LogType::LINFO);
}

void Log::warningLog_(const char* caller, const char * format, ...)
{
	char * msg = (char*)format;
    va_list argptr;
    va_start(argptr, format);
    size_t bufsz = vsnprintf(NULL, 0, format, argptr);
	msg = (char*)malloc(sizeof(char) *(bufsz + 1));
    vsnprintf(msg, bufsz + 1, format, argptr);
    va_end(argptr);
	
	Log::writeLog(msg, caller, LogType::LWARNING);
}

void Log::errorLog_(const char* caller, const char * format, ...)
{
	char * msg = (char*)format;
    va_list argptr;
    va_start(argptr, format);
    size_t bufsz = vsnprintf(NULL, 0, format, argptr);
	msg = (char*)malloc(sizeof(char) *(bufsz + 1));
    vsnprintf(msg, bufsz + 1, format, argptr);
    va_end(argptr);
    
    Log::writeLog(msg, caller, LogType::LERROR);
}

void Log::criticalLog_(const char* caller, const char * format, ...)
{
	char * msg = (char*)format;
    va_list argptr;
    va_start(argptr, format);
    size_t bufsz = vsnprintf(NULL, 0, format, argptr);
	msg = (char*)malloc(sizeof(char) *(bufsz + 1));
    vsnprintf(msg, bufsz + 1, format, argptr);
    va_end(argptr);

    Log::writeLog(msg, caller, LogType::LCRITICAL);
}