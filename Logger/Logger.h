#ifndef _LOGGER_H_
#define _LOGGER_H_

//#include "boost/thread/mutex.hpp"

class Logger  //新增一个Logger类，有一个LogMsgE 方法，日后还可已添加LogINFO(级别的)
{
public:
	Logger();
	static void LogMsgE(const char* format,...);
//  static void LogINFO(const char* format,...);
private:
	static void LogMsg(const char* fname,const char* msg);
//    static boost::mutex mut;
};

#endif //_LOGGER_H_
