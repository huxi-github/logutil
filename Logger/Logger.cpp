#include "Logger.h"
#include <stdarg.h>
#include <stdio.h>
#include <memory.h>
#include <time.h>
#include <string.h>
//boost::mutex Logger::mut;
//master changes
Logger::Logger()
{
}

void Logger::LogMsgE(const char* format,...)
{
    #ifdef __ANDROID__
	    const char * fname = "/sdcard/Log_CXSMail.txt";

    #elif _WIN32
	    const char * fname = "C:\\Westone\\bin\\Log_CXSMail_Plugin.txt";
    #elif __linux__
	    const char * fname = "/tmp/Log_CXSMail.txt";
     #elif __APPLE__
     const char * fname = "/Users/huxi/Desktop/Log_CXSMail.txt";
    #endif

	if (format == NULL)
	{
		FILE * fLog = fopen(fname, "w+");

		if (fLog != NULL)
		{
			fclose(fLog);
		}

		return;
	}

	char tmp[1024] = {0};
    
	time_t t = time(NULL);
	tm * sysTime = localtime(&t);
	sprintf(tmp,"[Time: %02d-%02d-%02d %02d:%02d:%02d]  ",
	    			sysTime->tm_year,
	    			sysTime->tm_mon,
	    			sysTime->tm_mday,
	    			sysTime->tm_hour,
	    			sysTime->tm_min,
					sysTime->tm_sec);

	LogMsg(fname,tmp);
	memset(tmp, 0, 1024);
	va_list arg_ptr;
	va_start(arg_ptr, format);
	vsnprintf(tmp, sizeof(tmp)-1, format, arg_ptr);

	LogMsg(fname,tmp);
	LogMsg(fname,"\n");
}

void Logger::LogMsg(const char* fname,const char* msg)
{
//    mut.lock();
	FILE * fLog = fopen(fname,"a+");

	if(fLog == NULL)
	{
		return;
	}

	fwrite(msg,sizeof(char),strlen(msg),fLog);
	fclose(fLog);
//    mut.unlock();
}
