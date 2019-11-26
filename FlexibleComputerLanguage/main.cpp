/*//
//  main.cpp
//  FlexibleComputerLanguage
//
//  Created by Dileepa Jayathilaka on 5/8/18.
//  Copyright (c) 2018 Dileepa Jayathilaka. All rights reserved.
//
// VERSION 2

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "Tests.h"
#include "json.hpp"
#include "MemMan.h"
#include "Node.h"
#include "MetaData.h"
#include "ExecutionTemplateList.h"
#include "ExecutionContext.h"
#include "TestCaseExecuter.h"
#include "Int.h"
#include "OTPParser.h"
#include "LogJsonParser.h"
#include "NamedPipeOperations.h"
#include "easylogging++.h"
#include "Logger.h"
#include <iostream>
#include <memory>
#include <pthread.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "dotenv.h"
#include "EntityList.h"
#include "QueryExecuter.h"

using namespace rapidjson;
using json = nlohmann::json;

INITIALIZE_EASYLOGGINGPP


int main(int argc, const char * argv[])
{
    std::cout << "Started\n";
    //Tests tt;
   // tt.RunTest6();
    std::string line;
    std::string jsonline;
    std::ifstream jsonfile ("D:/99xProjects/MurtazaCode/FlexibleComputerLanguage/FlexibleComputerLanguage/resultJSON.json");
    if (jsonfile.is_open())
    {
        getline (jsonfile,line);
        jsonline = line;
        jsonfile.close();
    }
    Node* jsonroot = LogJsonParser::LogJSONToNodeTree(jsonline);

    std::string scriptline;
    std::ifstream scriptfile ("D:/99xProjects/MurtazaCode/FlexibleComputerLanguage/FlexibleComputerLanguage/Scripts/script.txt");
    //std::ifstream scriptfile ("D:/99xProjects/MurtazaCode/FlexibleComputerLanguage/FlexibleComputerLanguage/Masking/maskscript.txt");
    std::string script="";

    while(getline(scriptfile,scriptline))
    {
        script+=scriptline;
        script+="\n";
    }

    std::string res = QueryExecuter::run(jsonroot,script);
    std::cout << "\n";
    std::cout <<res;

    LogJsonParser::LogNodeTreetoJson(jsonroot);


    return 0;
}*/
#include <iostream>
#include "json.hpp"
#include "Int.h"
#include "OTPParser.h"
#include "NamedPipeOperations.h"
#include "easylogging++.h"
#include <pthread.h>
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <TypeDefs.h>
#include "D:/99xProjects/MurtazaCode/FlexibleComputerLanguage/SQLAPI/include/SQLAPI.h"
#include <random>

INITIALIZE_EASYLOGGINGPP
int main()
{
    // create connection object to connect to database
    //SAConnection con;

    srand(time(NULL)); //generates random seed val
    int outPut;

    for (int i = 0; i < 50; i++) {
        outPut = rand()%((25000 - 10000) + 1) + 10000;
        std::cout << outPut << "  ";
    }
    return 0;
}
/*
int userBeg =1;
int userEnd =30;
int outPut;

srand(time(NULL)); //generates random seed val

for (int i = 0; i < 20; i++) {
outPut = rand()%((userEnd - userBeg) + 1) + userBeg;
std::cout << outPut << "  ";
}*/
