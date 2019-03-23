//
//  Logger4.h
//  Logger
//
//  Created by huxi on 2019/3/22.
//  Copyright © 2019 huxi. All rights reserved.
//

#ifndef Logger4_hpp
#define Logger4_hpp

#include <stdio.h>
#include <string>
using namespace std;

enum LOGTYPE
{
    LERROR = 1,
    LDEBUG,
    LINFO,
};
class Logger4
{
public:
 
    static void LogMsgERROR(string msg);
    static void LogMsgINFO(string msg);
    
protected:
private:
    static void LogMsg(string msg);
};

#endif /* Logger4_hpp */
