//
// Created by AfazD on 02-Dec-19.
//
#include <windows.h>
#include <mysql.h>
#include <string>
#include "MysqlConnector.h"
#include "MemMan.h"

MYSQL* MysqlConnector::getConnection(MSTRING hostname,MSTRING username,MSTRING password,MSTRING dbname,int port)
{
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,hostname.c_str(), username.c_str(), password.c_str(), dbname.c_str(), port, NULL, 0);

    return  conn;
}
void MysqlConnector::insertQuery(MYSQL* conn)
{
    int qstate=0;
    MSTRING name= "Jack";
    MSTRING query ="INSERT INTO test_table(name) VALUES('"+name+"')";
    qstate = mysql_query(conn,query.c_str());
    if(qstate == 0){
        std::cout<<"Record Inserted...." ;
    }else{
        std::cout<<"Failed" ;
    }
}
MSTRING MysqlConnector::selectPostalCode(MYSQL *conn, int id)
{
    MYSQL_RES *res; /* holds the result set */
    MYSQL_ROW row;
    MSTRING query = "SELECT postalcode FROM postalcodetable WHERE id = "+std::to_string(id);
    mysql_query(conn,query.c_str());
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);
    MSTRING result =row[0];
    return result;
}
MSTRING MysqlConnector::selectFirstName(MYSQL *conn, int id)
{
    MYSQL_RES *res; /* holds the result set */
    MYSQL_ROW row;
    MSTRING query = "SELECT name FROM test_table WHERE id = "+std::to_string(id);
    mysql_query(conn,query.c_str());
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);
    MSTRING result =row[0];
    return result;
}
MSTRING MysqlConnector::selectLastName(MYSQL *conn, int id)
{
    MYSQL_RES *res; /* holds the result set */
    MYSQL_ROW row;
    MSTRING query = "SELECT LastName FROM norwaylastname WHERE ID = "+std::to_string(id);
    mysql_query(conn,query.c_str());
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);
    MSTRING result =row[0];
    return result;
}
MSTRING MysqlConnector::selectAddress(MYSQL *conn, int id)
{
    MYSQL_RES *res; /* holds the result set */
    MYSQL_ROW row;
    MSTRING query = "SELECT placeName FROM lookupaddresstable WHERE AddressID = "+std::to_string(id);
    mysql_query(conn,query.c_str());
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);
    MSTRING result =row[0];
    return result;
}
MSTRING MysqlConnector::selectCityCode(MYSQL *conn, int id)
{
    MYSQL_RES *res; /* holds the result set */
    MYSQL_ROW row;
    MSTRING query = "SELECT code FROM citycode WHERE id = "+std::to_string(id);
    mysql_query(conn,query.c_str());
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);
    MSTRING result =row[0];
    return result;
}
