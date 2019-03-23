//
//  Logger4.cpp
//  Logger
//
//  Created by huxi on 2019/3/22.
//  Copyright © 2019 huxi. All rights reserved.
//


#include <iostream>
#include "Logger4.h"
#include "define.h"


void Logger4::LogMsgE(LOGTYPE level,string msg){
    
    tm *sysTime = NULL;
    time_t t = time(NULL);
    sysTime = localtime(&t);
    char tmp[1024] = { 0 };  //栈上分配的内存1024 bytes
    sprintf(tmp,"[Time: %02d-%02d-%02d %02d:%02d:%02d]",
            sysTime->tm_year,
            sysTime->tm_mon,
            sysTime->tm_mday,
            sysTime->tm_hour,
            sysTime->tm_min,
            sysTime->tm_sec);
    string timeStamp(tmp);
    
    string eLevel=getLevelSymbol(level);
    
    string msginfo=timeStamp+eLevel+msg;
    LogMsg(msginfo);
    LogMsg("\n");
    
}

void Logger4::LogMsg(string msg){
    std::cout<<msg;    
    const char *logpath="/Users/huxi/Downloads/log.txt";
    
    FILE *flog=fopen(logpath, "a+");//"w+ 会覆盖老文件);
    if(flog==NULL){
        cout<<"日志文件打开失败";
        return ;
    }
    const char *char_msg=msg.c_str();
    fwrite(char_msg, sizeof(char), strlen(char_msg), flog);
    fclose(flog);
}


string Logger4::getLevelSymbol(LOGTYPE level){
    string levelStr;//栈上分配
    switch (level) {
        case LERROR:
            levelStr="[E]";
            break;
        case LINFO:
            levelStr="[I]";
            break;
        case LDEBUG:
           levelStr="[D]";
            break;
        default:
            break;
    }
    
    return levelStr;
    
}
