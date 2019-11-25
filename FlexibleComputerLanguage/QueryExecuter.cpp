//
// Created by AfazD on 14-Nov-19.
//

#include <string>
#include <Node.h>
#include <DefFileReader.h>
#include <ScriptReader.h>
#include <ExecutionContext.h>
#include "QueryExecuter.h"
#include "ResultGenerator.h"

// shared data
int id = 0;
MSTRING QueryExecuter::run(Node *root, MSTRING querycode)
{

    DefFileReader dfr;
    // CAUTION: This file path is hardcoded and can cause crashes. You have been warned!
    MetaData *pMD = dfr.Read("D:/99xProjects/MurtazaCode/FlexibleComputerLanguage/FlexibleComputerLanguage/Defs.txt");
    ScriptReader sr;
    ScriptReaderOutput op;
    //bool bSucc = sr.ProcessScript(pMD->s_RuleFileName, pMD, op);
    bool bSucc = sr.ProcessScript(pMD, op, querycode);
    if (!bSucc)
    {
        std::wcout << "\nFailed to read script\n";
    }
    ExecutionContext ec;
    ec.p_mapFunctions = &op.map_Functions;
    ec.p_MD = pMD;
    Node *pY = MemoryManager::Inst.CreateNode(++id);
    Node *pRESULT = MemoryManager::Inst.CreateNode(++id);
    std::string s = "52";
    root->SetValue((char *)s.c_str());
    ec.map_Var["X"] = root;
    ec.map_Var["Y"] = pY;
    ec.map_Var["RESULT"] = pRESULT;
    op.p_ETL->Execute(&ec);
    return ResultGenerator::CreateResult(pRESULT);

}
