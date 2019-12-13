//
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
#include "MysqlConnector.h"
#include <windows.h>
#include <mysql.h>

using namespace rapidjson;
using json = nlohmann::json;

INITIALIZE_EASYLOGGINGPP


int main(int argc, const char * argv[])
{
    std::cout<<"Log analyzer masking started\n";

    MYSQL *conn = nullptr;
    MSTRING hostname = "localhost" ;
    MSTRING username = "admin";
    MSTRING password = "admin";
    MSTRING dbname = "substitutiondb";
    int port = 0;
    MysqlConnector mysqlobj;
    conn = mysqlobj.getConnection(hostname, username, password, dbname, port);

    //Tests tt;
    // tt.RunTest6();
    std::string line;
    std::string jsonline;
    //std::ifstream jsonfile ("../FlexibleComputerLanguage/resultJSON.json");
    //std::ifstream jsonfile ("../FlexibleComputerLanguage/norwayresultJSON.json");
    std::ifstream jsonfile ("../FlexibleComputerLanguage/trcfdlogJSON.json");
    if (jsonfile.is_open())
    {
        getline (jsonfile,line);
        jsonline = line;
        jsonfile.close();
    }
    Node* jsonroot = LogJsonParser::LogJSONToNodeTree(jsonline);

    if(conn)
    {
        std::cout<<"Connected\n";
    }
    else
    {
        perror ("The Database could not be connected, Please check the db connection!");
        exit(1);
    }

    std::string scriptline;
    //std::ifstream scriptfile ("../FlexibleComputerLanguage/Masking/maskscript.txt");
    //std::ifstream scriptfile ("../FlexibleComputerLanguage/Masking/norwaymaskscript.txt");
    std::ifstream scriptfile ("../FlexibleComputerLanguage/Masking/trcfdmaskscript.txt");
    std::string script="";

    while(getline(scriptfile,scriptline))
    {
        script+=scriptline;
        script+="\n";
    }

    std::string res = QueryExecuter::run(jsonroot,script,conn);
    std::cout << "\n";
    std::cout <<res;

    LogJsonParser::LogNodeTreetoJsonRecursivly(jsonroot);

    LogJsonParser::LogNodeTreetoLog(jsonroot);


    return 0;
}
