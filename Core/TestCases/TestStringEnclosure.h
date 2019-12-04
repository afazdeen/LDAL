//
//  TestStringEnclosure.h
//  FlexibleComputerLanguage
//
//  Created by Dileepa Jayathilaka on 5/26/18.
//  Copyright (c) 2018 Dileepa Jayathilaka. All rights reserved.
//

#ifndef __FlexibleComputerLanguage__TestStringEnclosure__
#define __FlexibleComputerLanguage__TestStringEnclosure__

#include <iostream>
#include "TestCaseBase.h"
#include <windows.h>
#include <mysql.h>

class TestStringEnclosure : public TestCaseBase {
    virtual TestCaseExecutionResult Execute(TestCaseArgument* arg,MYSQL* conn);
};

#endif /* defined(__FlexibleComputerLanguage__TestStringEnclosure__) */
