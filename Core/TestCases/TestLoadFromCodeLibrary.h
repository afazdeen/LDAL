//
//  TestLoadFromCodeLibrary.h
//  FlexibleComputerLanguage
//
//  Created by Dileepa Jayathilaka on 5/24/18.
//  Copyright (c) 2018 Dileepa Jayathilaka. All rights reserved.
//

#ifndef __FlexibleComputerLanguage__TestLoadFromCodeLibrary__
#define __FlexibleComputerLanguage__TestLoadFromCodeLibrary__

#include <iostream>
#include "TestCaseBase.h"
#include <windows.h>
#include <mysql.h>

class TestLoadFromCodeLibrary : public TestCaseBase {
    virtual TestCaseExecutionResult Execute(TestCaseArgument* arg,MYSQL* conn);
};

#endif /* defined(__FlexibleComputerLanguage__TestLoadFromCodeLibrary__) */
