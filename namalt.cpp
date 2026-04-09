#include "sqlite3.h"
#include <string>
#include <stdexcept>
using std::string;
namespace ALTER{
    template<typename G>
    void del_row(string tbname, string parameter,G a){
          if (tbname.empty())
            throw std::invalid_argument("Table name cannot be empty");
        if (parameter.empty())
            throw std::invalid_argument("Parameter name cannot be empty");

        sqlite3_stmt *stmt;
        string sql="DELETE FROM " + tbname + " WHERE " + parameter + "=?;";
        sqlite3_prepare_v2(DATACENTER::DB,sql.c_str(),-1,&stmt,nullptr);
        auto bind_int=[](sqlite3_stmt* stmt, int index, int value) {
                        sqlite3_bind_int(stmt, index, value);
            };
        auto bind_text=[](sqlite3_stmt* stmt, int index, const string& value) {
             sqlite3_bind_text(stmt, index, value.c_str(), -1, SQLITE_TRANSIENT);
             };

        if constexpr (std::is_same_v<G, int>)
           bind_int(stmt, 1, a);
        else
           bind_text(stmt, 1, a);

         if (sqlite3_step(stmt) != SQLITE_DONE)
            throw std::runtime_error("del_row execution failed: " + string(sqlite3_errmsg(DATACENTER::DB)));
        sqlite3_finalize(stmt);
    }

    void drop_col(string tbname, string parameter){
    if (tbname.empty())
        throw std::invalid_argument("Table name cannot be empty");
    if (parameter.empty())
        throw std::invalid_argument("Column name cannot be empty");
    sqlite3_stmt *stmt;
    string sql="ALTER TABLE " + tbname + " DROP COLUMN " + parameter + ";";
    sqlite3_prepare_v2(DATACENTER::DB,sql.c_str(),-1,&stmt,nullptr);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    }

    void drop_table(string tbname){
     if (tbname.empty())
        throw std::invalid_argument("Table name cannot be empty");
     sqlite3_stmt *stmt;
    string sql="DROP TABLE " + tbname + ";";
      if (sqlite3_prepare_v2(DATACENTER::DB, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
            throw std::runtime_error("drop_col prepare failed: " + string(sqlite3_errmsg(DATACENTER::DB)));
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    }
}

namespace ALTER{
class ADDITION{
public:
    template<typename G>
    void update(string tbname,string parameter,G value){
      if (tbname.empty())
         throw std::invalid_argument("Table name cannot be empty");
      if (parameter.empty())
         throw std::invalid_argument("Column name cannot be empty");
    sqlite3_stmt *stmt;
    string sql="UPDATE " + tbname + " SET " + parameter + " = ?;";
    sqlite3_prepare_v2(DATACENTER::DB,sql.c_str(),-1,&stmt,nullptr);
    sqlite3_bind_int(stmt, 1, value);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    }

    void rename_clnnm(string tbname,string clnname,string newclnname){
      if (tbname.empty() || clnname.empty() || newclnname.empty())
           throw std::invalid_argument("Table/column names cannot be empty");
      if (newclnname.size() > 64)
           throw std::out_of_range("New column name too long (max 64 chars): " + newclnname);
    sqlite3_stmt *stmt;
    string sql="ALTER TABLE " + tbname + " RENAME COLUMN " + clnname + " TO " + newclnname + ";";
    sqlite3_prepare_v2(DATACENTER::DB,sql.c_str(),-1,&stmt,nullptr);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    }

    void rename_tbn(string tbname,string nwtbn);
};
}
void ALTER::ADDITION::rename_tbn(string tbname,string nwtbn){
    if (tbname.empty() || nwtbn.empty())
         throw std::invalid_argument("Table names cannot be empty");
    if (nwtbn.size() > 64)
         throw std::out_of_range("New table name too long (max 64 chars): " + nwtbn);
    sqlite3_stmt *stmt;
    string sql="ALTER TABLE " + tbname + " RENAME TO " + nwtbn + ";";
    sqlite3_prepare_v2(DATACENTER::DB,sql.c_str(),-1,&stmt,nullptr);
    if (sqlite3_step(stmt) != SQLITE_DONE)
          throw std::runtime_error("rename_tbn execution failed: " + string(sqlite3_errmsg(DATACENTER::DB)));
    sqlite3_finalize(stmt);
    }
