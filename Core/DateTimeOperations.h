//
//  DateTimeOperations.h
//  FlexibleComputerLanguage
//
//  Created by Murtaza Anverali on 5/31/18.
//  Copyright © 2018 Dileepa Jayathilaka. All rights reserved.
//

#ifndef DateTimeOperations_h
#define DateTimeOperations_h

#include "CommonIncludes.h"
#include <ctime>

class DateTimeOperations
{
public:
    static long StringToUnix(std::string str);
    static int SecondsToMonths(long seconds);
    static int SecondsToDays(long seconds);
    static int SecondsToYears(long seconds);
    static long GetDifferenceByUnix(long date1, long date2);
    static long GetDifferenceByString(std::string date1, std::string date2);
    static std::string StringToReadable(std::string date);
    static long GetDateNow();
    
};


#endif /* DateTimeOperations_h */
