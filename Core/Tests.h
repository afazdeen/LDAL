#ifndef _TESTS_H
#define _TESTS_H

#include "CommonIncludes.h"
#include <windows.h>
#include <mysql.h>

class Tests
{
public:
	void RunTest1(MYSQL* conn);
	void RunTest2(MYSQL* conn);
	void RunTest3(MYSQL* conn);
	void RunTest4(MYSQL* conn);
    void RunTest5(MYSQL* conn);
    void RunTest6(MYSQL* conn);
};



#endif