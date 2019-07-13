//
//  main.cpp
//  Logger
//
//  Created by huxi on 2019/3/22.
//  Copyright © 2019 huxi. All rights reserved.
//

#include <iostream>
#include "Logger4.h"
//change in father
int main(int argc, const char * argv[]) {
    
            Logger4::LogMsgE(LERROR,"a info msg");
    
            Logger4::LogMsgE(LINFO,"a error msg");
    
            Logger4::LogMsgE(LINFO,"a error msg %d,%s",10000,"hahaha");
    return 0;
}
