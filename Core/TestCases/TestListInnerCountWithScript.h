//
//  TestListInnerCountWithScript.h
//  LogAnalyzer
//
//  Created by Dileepa Jayathilaka on 1/15/15.
//  Copyright (c) 2015 99x Eurocenter. All rights reserved.
//

#ifndef __LogAnalyzer__TestListInnerCountWithScript__
#define __LogAnalyzer__TestListInnerCountWithScript__

#include <iostream>
#include "TestCaseBase.h"
#include <windows.h>
#include <mysql.h>

class TestListInnerCountWithScript : public TestCaseBase {
public:
    virtual TestCaseExecutionResult Execute(TestCaseArgument* arg,MYSQL* conn);
};

#endif /* defined(__LogAnalyzer__TestListInnerCountWithScript__) */
