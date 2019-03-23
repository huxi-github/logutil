//
//  Logger4.cpp
//  Logger
//
//  Created by huxi on 2019/3/22.
//  Copyright © 2019 huxi. All rights reserved.
//


#include <iostream>
#include <stdio.h>

#include "Logger4.h"
#include "define.h"
//Logger4::Logger4()
//{
//
//}
//
//Logger4::~Logger4()
//{
//
//}

void Logger4::LogMsgERROR(string msg){
    
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
    string msginfo=timeStamp+"[ERROR]"+msg;
    LogMsg(msginfo);
    LogMsg("\n");
    
}

void Logger4::LogMsgINFO(string msg){
    
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
    string msginfo=timeStamp+"[INFO]"+msg;
    LogMsg(msginfo);
    LogMsg("\n");
}

void Logger4::LogMsg(string msg){
    std::cout<<msg;
    
    const char *logpath="/Users/huxi/Downloads/log.txt";
    
    FILE *flog=fopen(logpath, "a+");//"w+ 会覆盖老文件);
    if(!flog){
        cout<<"日志文件打开失败";
        return ;
    }
    const char *char_msg=msg.c_str();
    fwrite(char_msg, sizeof(char), strlen(char_msg), flog);
    fclose(flog);
    return ;
}
