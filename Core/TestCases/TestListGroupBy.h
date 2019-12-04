//
//  TestListGroupBy.h
//  LogAnalyzer
//
//  Created by Dileepa Jayathilaka on 1/25/15.
//  Copyright (c) 2015 99x Eurocenter. All rights reserved.
//

#ifndef __LogAnalyzer__TestListGroupBy__
#define __LogAnalyzer__TestListGroupBy__

#include <iostream>
#include "TestCaseBase.h"
#include <windows.h>
#include <mysql.h>

class TestListGroupBy : public TestCaseBase {
    virtual TestCaseExecutionResult Execute(TestCaseArgument* arg,MYSQL* conn);
};

#endif /* defined(__LogAnalyzer__TestListGroupBy__) */
