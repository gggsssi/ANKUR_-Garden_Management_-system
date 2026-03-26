#include "sqlite3.h"
#include <string>
using std::string;
namespace ALTER{
    void del_row(string tbname, string parameter,G a){
        sqlite3_stmt *stmt;
        char *sql="DELETE FROM " + tbname + " WHERE " + parameter + "=?;";
        sqlite3_prepare_v2(DATACENTER::DB,sql,-1,&stmt,nullptr);
        void bind(sqlite3_stmt* stmt, int index, int value) {
                        sqlite3_bind_int(stmt, index, value);
            }
        void bind(sqlite3_stmt* stmt, int index, const string& value) {
             sqlite3_bind_text(stmt, index, value.c_str(), -1, SQLITE_TRANSIENT);
             }
        bind(stmt,1,a);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }

    void drop_col(string tbname, string parameter){
    sqlite3_stmt *stmt;
    char *sql="ALTER TABLE " + tbname + " DROP COLUMN " + parameter + ";";
    sqlite3_prepare_v2(DATACENTER::DB,sql,-1,&stmt,nullptr);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    }

    void drop_table(string tbname){
    sqlite3_stmt *stmt;
    char *sql="DROP TABLE " + tbname ";";
    sqlite3_prepare_v2(DATACENTER::DB,sql,-1,&stmt,nullptr);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    }
}

namespace ALTER{
class ADDITION{
public:
    template<typename G>
    void update(string tbname,string parameter,G value){
    sqlite3_stmt *stmt;
    string *sql="UPDATE " + tbname + " SET " + parameter + " = ?;";
    sqlite3_prepare_v2(DATACENTER::DB,sql.c_str(),-1,&stmt,nullptr);
    sqlite3_bind_int(stmt, 1, value);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    }

    void rename_clnnm(string tbname,string clnname,string newclnname){
    sqlite3_stmt *stmt;
    string *sql="ALTER TABLE" + tbname + " RENAME COLUMN " + clnname + " TO " + newclnname + ";";
    sqlite3_prepare_v2(DATACENTER::DB,sql.c_str(),-1,&stmt,nullptr);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    }

    void rename_tbn(string tbname,string nwtbn);
};
}
void rename_tbn(string tbname,string nwtbn){
    sqlite3_stmt *stmt;
    string *sql="ALTER TABLE" + tbname + " RENAME TO " + nwtbn + ";";
    sqlite3_prepare_v2(DATACENTER::DB,sql.c_str(),-1,&stmt,nullptr);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    }
