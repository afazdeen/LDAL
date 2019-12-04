//
//  TestCustomStrFilterShorthand.h
//  LogAnalyzer
//
//  Created by Dileepa Jayathilaka on 1/26/15.
//  Copyright (c) 2015 99x Eurocenter. All rights reserved.
//

#ifndef __LogAnalyzer__TestCustomStrFilterShorthand__
#define __LogAnalyzer__TestCustomStrFilterShorthand__

#include <iostream>
#include "TestCaseBase.h"
#include <windows.h>
#include <mysql.h>

class TestCustomStrFilterShorthand : public TestCaseBase {
    virtual TestCaseExecutionResult Execute(TestCaseArgument* arg,MYSQL* conn);
};

#endif /* defined(__LogAnalyzer__TestCustomStrFilterShorthand__) */
