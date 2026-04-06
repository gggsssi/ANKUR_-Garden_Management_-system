#include "sqlite3.h"
#include <stdexcept>
#include <string>
using std::string;

template<typename G>
G operator+ (G a,G b)
{
    return(a+b);
}



     template<typename G>
     G Calculation_Usage(string a){
     sqlite3_stmt *stmt;
     G h=G();
     G sum;
     sum=G();
     if (a != "Tools" && a != "TOOLS" &&
        a != "Water" && a != "WATER" && a != "water")
        throw std::invalid_argument("Unknown category: '" + a + "'. Use 'Tools' or 'Water'.");
     if (a=="Tools" || a=="TOOLS"){
     const char* sql="Select * from Cost_TRACKER ;";
      sqlite3_prepare_v2(
       DATACENTER::DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
       while(sqlite3_step(stmt)==SQLITE_ROW){
                G h=(G)sqlite3_column_int(stmt,1);
                sum=sum+h;
       }
       sqlite3_finalize(stmt);
       return(sum);
       }

       if (a=="Water" || a=="WATER" || a=="water")
         {
      const char* sql="Select * from Water_task;";
      if (sqlite3_prepare_v2(DATACENTER::DB, sql, -1, &stmt, nullptr) != SQLITE_OK)
            throw std::runtime_error("DB prepare failed (Water): " + string(sqlite3_errmsg(DATACENTER::DB)));
       while(sqlite3_step(stmt)==SQLITE_ROW){
                G h=(G)sqlite3_column_int(stmt,3);
                sum=sum+h;
       }
       sqlite3_finalize(stmt);
       return(sum);
         }
     return sum;
     }

      template<typename G>
      G Calculation_Usage(int task_id,int date){
         sqlite3_stmt *stmt;
     G h;
     if (task_id <= 0)
        throw std::out_of_range("task_id must be positive, got: " + std::to_string(task_id));
    if (date <= 0)
        throw std::out_of_range("date must be positive, got: " + std::to_string(date));

     const char* sql="Select WATER_USAGE from Water_task WHERE task_num =(?) AND DATE =(?);";
     sqlite3_prepare_v2(
       DATACENTER::DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
       sqlite3_bind_int(stmt,1,task_id);
       sqlite3_bind_int(stmt,2,date);
       sqlite3_step(stmt);
        if (sqlite3_step(stmt) == SQLITE_ROW) {
        h = (G)sqlite3_column_int(stmt, 0);
         }
       sqlite3_finalize(stmt);
       return h;
      }
