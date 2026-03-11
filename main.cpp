#include <iostream>
#include "sqlite3.h"
using namespace std;

    sqlite3* DB;
    char *errMSG=nullptr;
    if (sqlite3_open("garden.db", &DB)) {
        std::cout << "Error opening database\n";
    } else {
        std::cout << "Database opened successfully\n";
    }
    void DataStorage(sqlite3* DB){
    const char* Users =
        "CREATE TABLE IF NOT EXISTS users ("
        "registration_id  INTEGER PRIMARY KEY ,"
        "  name VARCHAR(30) NOT NULL,"
        "  course VARCHAR(20) NOT NULL,"
        "  sem_number  INT  NOT NULL "
        ");";

    const char* Zones =
        "CREATE TABLE IF NOT EXISTS users ("
        "zone_num INTEGER PRIMARY KEY ,"
        "zone_name VARCHAR(30) NOT NULL,"
        " nop_zone INT NOT NULL,"
        " density_zone INT NOT NULL,"
        " not_zone  INT  NOT NULL "
        ");";

    const char* Tasks=
    " CREATE TABLE IF NOT EXISTS tasks("
    " task_num INT PRIMARY KEY ,"
    "zoneNUM INT ,"
    " task_dscrptn VARCHAR(180) ,"
    "FOREIGN KEY (zoneNUM) REFERENCES Zones(zone_num)"
    ");";

    const char* Assignd=
    " CREATE TABLE IF NOT EXISTS assignd("
    " regist_num INT PRIMARY KEY,"
    "task_num INT NOT NULL,"
    "FOREIGN KEY (regist_num) REFERENCES Users(registration_id),"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num)"";";

    const char* Scheduler=
    "CREATE TABLE IF NOT EXISTS Scheduler("
    " task_num INT NOT NULL,"
    "due_date DATE,"
    "time  TIME,"
    "nodl INT ,"
    "lw DATE,"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num)"";";

    const char* Inventory=
    "CREATE TABLE IF NOT EXISTS Inventory("
    "tool_num INT PRIMARY KEY ,"
    "tool_name VARCHAR(30) NOT NULL,"
    "nt INT ,"
    "price INT CHECK(PRICE>0),"
    "YOU INT"";";

    const char* Cost_TRACKER=
    "CREATE TABLE IF NOT EXISTS Cost_TRACKER("
    "tool_NUMBER INT PRIMARY KEY,"
    "TOTAL_COST INT NOT NULL"";";

    const char* Water_task=
    "CREATE TABLE IF NOT EXISTS Water_task("
    "Task_num INT PRIMARY KEY ,"
    "time_done INT NOT NULL,"
    "DATE INT ,"
    "WATER_USAGE INT,"
    "TOOL_NUMBER INT,"
    "WORKER_ID INT,"
    "STATUS VARCHAR(10),"
    "FOREIGN KEY (TOOL_NUMBER) REFERENCES Inventory(tool_num),"
    "FOREIGN KEY (WORKER_ID) REFERENCES Users(registration_id),"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num)"";";

     const char* Grasstrim_task=
    "CREATE TABLE IF NOT EXISTS Grasstrim_task("
    "Task_num INT PRIMARY KEY ,"
    "time_done INT NOT NULL,"
    "DATE INT ,"
    "TOOL_NUMBER INT,"
    "WORKER_ID INT,"
    "STATUS VARCHAR(10),"
    "FOREIGN KEY (TOOL_NUMBER) REFERENCES Inventory(tool_num),"
    "FOREIGN KEY (WORKER_ID) REFERENCES Users(registration_id),"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num)"";";

     const char* Deweed_task=
    "CREATE TABLE IF NOT EXISTS Deweed_task("
    "Task_num INT PRIMARY KEY ,"
    "time_done INT NOT NULL,"
    "DATE INT ,"
    "TOOL_NUMBER INT,"
    "WORKER_ID INT,"
    "STATUS VARCHAR(10),"
    "FOREIGN KEY (TOOL_NUMBER) REFERENCES Inventory(tool_num),"
    "FOREIGN KEY (WORKER_ID) REFERENCES Users(registration_id),"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num)"";";

     const char* Treeshape_task=
    "CREATE TABLE IF NOT EXISTS Treeshape_task("
    "Task_num INT PRIMARY KEY ,"
    "time_done INT NOT NULL,"
    "DATE INT ,"
    "TOOL_NUMBER INT,"
    "WORKER_ID INT,"
    "STATUS VARCHAR(10),"
    "FOREIGN KEY (TOOL_NUMBER) REFERENCES Inventory(tool_num),"
    "FOREIGN KEY (WORKER_ID) REFERENCES Users(registration_id),"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num)"";";



    if(sqlite3_exec(DB,Users,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creating users :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of users  succesful\n";}

    if(sqlite3_exec(DB,Zones,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creating zones:"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of zones succesful\n";
     }

    if(sqlite3_exec(DB,Tasks,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creating tasks:"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of taks  succesful\n";
     }

    if(sqlite3_exec(DB,Assignd,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at assiging tasks:"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of Assignd succesful\n";
     }

    if(sqlite3_exec(DB,Scheduler,0,nullptr,&errMSG)!=SQLITE_OK){
         std::cout<<"error occurred at assiging tasks:"<< errMSG<<"\n";
        sqlite3_free(errMSG);
     }
    else{
        std::cout<<"table creation of Scheduler succesful\n";
    }

    if(sqlite3_exec(DB,Inventory,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creating inventory table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of inventory  succesful\n";}

    if(sqlite3_exec(DB,Cost_TRACKER,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at cost tracker table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of cost tracker  succesful\n";}


    if(sqlite3_exec(DB,Water_task,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at water task table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of water task succesful\n";}

     if(sqlite3_exec(DB,Grasstrim_task,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at grasstrim task table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of grasstrim task succesful\n";}

      if(sqlite3_exec(DB,Deweed_task,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at deweed task table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of deweed task succesful\n";}

        if(sqlite3_exec(DB,Treeshape_task,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at treeshape task table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of treeshape task succesful\n";}


    };

    class registration{
    public :
        static string name,course;
        static int sem_number,registration_id;
        static int zone_num,nop_zone,density_zone,not_zone;
        static string zone_name;
        void user_process(){
        std::cout<<"Enter your name:\n";
        std::cin>>name;
        std::cout<<"Enter your course:\n";
        std::cin>>course;
        std::cout<<"Enter the semester number:\n";
        std::cin>>sem_number;
        std::cout<<"Enter the registration_id:\n"
        std::cin>>registration_id;

    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO users (name,course,sem_number,registration_id) VALUES (?, ?,?,?);";
    sqlite3_prepare_v2(
    DB,         // database handle
    sql,        // SQL with ? placeholders
    -1,         // length of sql (-1 = auto-detect)
    &stmt,      // prepared statement written here
    nullptr     // pointer to unused portion of sql (usually nullptr)
    );
    sqlite3_bind_int(stmt,1,registration_id,-1,SQLITE_TRANSIENT)
    sqlite3_bind_text(stmt,2,name,-1,sqlite_transient);
    sqlite3_bind_text(stmt,3,course,-1,SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt,4,sem_number,-1,SQLITE_TRANSIENT);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    free sql;
    };
    void Zone_process(){   //in future add option to see zones before adding new zone
        std::cout<<"Enter the zone number:\n";
        std::cin>>zone_num;
        std::cout<<"Enter no of plants in the zone:\n";
        std::cin>>nop_zone;
        std::cout<<"Enter the density of the zone:\n";
        std::cin>>density_zone;
        std::cout<<"Enter the no of trees of the zone:\n";
        std::cin>>not_zone;
        std::cout<<"Enter the name of the zone:\n";
        std::cin>>zone_name;
        sqlite3_stmt* stmt;
        const char* sql = "INSERT INTO zone (zone_name,zone_num,nop_zone,density_zone,not_zone) VALUES (?, ?,?,?,?);";
        sqlite3_prepare_v2(
        DB,         // database handle
        sql,        // SQL with ? placeholders
        -1,         // length of sql (-1 = auto-detect)
        &stmt,      // prepared statement written here
        nullptr     // pointer to unused portion of sql (usually nullptr)
        );
         sqlite3_bind_int(stmt,1,zone_num,-1,SQLITE_TRANSIENT)
         sqlite3_bind_text(stmt,2,zone_name,-1,sqlite_transient);
         sqlite3_bind_int(stmt,3,nop_zone,-1,SQLITE_TRANSIENT);
         sqlite3_bind_int(stmt,4,density_zone,-1,SQLITE_TRANSIENT);
         sqlite3_bind_int(stmt,5,not_zone,-1,SQLITE_TRANSIENT)
         sqlite3_step(stmt);
         sqlite3_finalize(stmt);
        free sql;
        };
    }
    class Tasks{
    public:
        static int task_num,zi;
        static string task_dscrptn,status;
        int a,b;
        void insert_tasks(){
        std::cout<<"Enter task number:\n";
        std::cin>>task_num;
        std::cout<<"Enter description of the task:\n";
        std::cin>>task_dscrptn;

        sqlite3_stmt* stmt;
        const char* sql = "INSERT INTO tasks (task_num,task_dscrptn) VALUES (?, ?);";
        sqlite3_prepare_v2(
        DB,         // database handle
        sql,        // SQL with ? placeholders
        -1,         // length of sql (-1 = auto-detect)
        &stmt,      // prepared statement written here
        nullptr     // pointer to unused portion of sql (usually nullptr)
        );
        sqlite3_bind_int(stmt,1,task_num,-1,SQLITE_TRANSIENT)
        sqlite3_bind_int(stmt,2,zone_num,-1,sqlite_transient);
        sqlite3_bind_text(stmt,3,task_dscrptn,-1,SQLITE_TRANSIENT);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        free sql;
        };

       void assign_tasks(){
       std:cout<<"You have opted to assign task to a member\n"
       std::cout<<"Enter the registration id of member to whom task is to be assigned:\n";
       std::cin>>a;
       std::cout<<"Enter the task number:\n";
       std::cin>>b;
       sqlite3_stmt* stmt;
       const char* sql = "INSERT INTO tasks (a,b) VALUES (?, ?);";
       sqlite3_prepare_v2(
       DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
       sqlite3_bind_int(stmt,1,regist_num,-1,SQLITE_TRANSIENT);
       sqlite3_bind_int(stmt,2,task_num,-1,sqlite_transient);
       sqlite3_step(stmt);
       sqlite3_finalize(stmt);
       free sql;

       };

         }
    class scheduler{
    public:
      void schedule_work(){
       static string date,time
       static int nodl,lw;
       int k;
       static string status;
       std::cout<<"Enter the task_num:\n";
       std::cin>>k;
       std::cout<<"Enter the due date:\n";
       std::cin>>date;
       std::cout<<"Enter number of days left(enter 0):\n";
       std::cin>>nodl;
       std::cout<<"Enter the time you wish to do work in next session:\n";
       std::cin>>time;
       std::cout<<"enter the last date worked on(0 if not yet started):\n";
       std::cin>>lw;
       std::cout<<"Enter the status of the task:\n";
       std::cin>>status;
       sqlite3_stmt* stmt;
       const char* sql = "INSERT INTO Scheduler (k,date,time,nodl,lw,status) VALUES (?, ?,?,?,?,?);";
       sqlite3_prepare_v2(
       DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
       sqlite3_bind_int(stmt,1,task_num,-1,SQLITE_TRANSIENT);
       sqlite3_bind_int(stmt,2,date,-1,sqlite_transient);
       sqlite3_bind_int(stmt,3,time,-1,SQLITE_TRANSIENT);
       sqlite3_bind_int(stmt,4,nodl,-1,sqlite_transient);
       sqlite3_bind_int(stmt,5,lw,-1,SQLITE_TRANSIENT);
       sqlite3_bind_text(stmt,6,status,-1,SQLITE_TRANSIENT);
       sqlite3_step(stmt);
       sqlite3_finalize(stmt);
       free sql;
    };
    void check_status(){
      int a;
      std::cout<<"Enter task number:\n";
      std::cin>>a;
      sqlite3_stmt* stmt;
      const char* sql = "select task_num ,status from Scheduler where task_num="
      +std::to_string(a)+";";

      sqlite3_prepare_v2(
       DB,         // database handle
       sql.cstr(),
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
       while(sqlite3_step(stmt)==SQLITE_ROW){
        std::cout<<"TASK NUM:"<<sqlite3_column_int(stmt, 0);
        std::cout<<"STATUS:"<<sqlite3_column_text(stmt,1);
       }
      };
 };
    class Resources{
     private :
        int h,g;
    public:
        void Inventory_mgmnt(){
            static int tool_num,you,price,nt;
            static string tool_name;
            std::cout<<"Enter the tool number:\n";
            std::cin>>tool_num;
            std::cout<<"Enter the tool name:\n";
            std::cin>>tool_name;
            std::cout<<"Enter the number of tools:\n";
            std::cin>>nt;
            std::cout<<"Enter the price of tool(in rs) at time of buying:\n";
            std::cin>>price;
            std::cout<<"Enter the number of years the tool had been used:\n";
            std::cin>>you;

       sqlite3_stmt* stmt;
       char *sql="Insert into Inventory (tool_num,tool_name,price,you,nt) VALUES(?,?,?,?,?);";
       sqlite3_prepare_v2(
       DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
       qlite3_bind_int(stmt,1,tool_num,-1,SQLITE_TRANSIENT);
       sqlite3_bind_text(stmt,2,tool_name,-1,sqlite_transient);
       sqlite3_bind_int(stmt,3,price,-1,SQLITE_TRANSIENT);
       sqlite3_bind_int(stmt,4,you,-1,sqlite_transient);
       sqlite3_bind_int(stmt,5,nt,-1,SQLITE_TRANSIENT);
       sqlite3_step(stmt);
       sqlite3_finalize(stmt);
       free sql;
        };

     void Inventory_tracker(){
      std::cout<<"Enter the tool number being used:\n";
      std::cin>>h;
      std::cout<<"Enter the task number:\n";
      std::cin>>g;
      sqlite3_stmt* stmt;
      char* sql="INSERT INTO TRACKER (h,g) VALUES(?,?);";
      sqlite3_prepare_v2(
       DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
       sqlite3_bind_int(stmt,1,h,-1,SQLITE_TRANSIENT);
       sqlite3_bind_int(stmt,2,g,-1,sqlite_transient);
       sqlite3_step(stmt);
       sqlite3_finalize(stmt);
       free sql;
        };

      void Inventory_calculation(){
      sqlite3_stmt* stmt;
      sqlite3_stmt* stmt1;
      int a,b;
      char *sql="Select * from Inventory tool_num,tool_name,nt,price,nt*price AS TOTAL_COST FROM Inventory;";
      sqlite3_prepare_v2(
       DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
       char* sql1="INSERT INTO Cost_TRACKER (a,b) VALUES(?,?);";
       sqlite3_prepare_v2(
       DB,         // database handle
       sql1,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt1,      // prepared statement written here
       nullptr );
       while(sqlite3_step(stmt)==SQLITE_ROW){
        std::cout<<"TOOL NAME:"<<sqlite3_column_text(stmt, 0);
        std::cout<<"TOOL NUMBER:"<<sqlite3_column_int(stmt,1);
        a=sqlite3_column_int(stmt,1);
        sqlite3_bind_int(stmt1,1,a,-1,SQLITE_TRANSIENT);
        std::cout<<"No of tools:"<<sqlite3_column_int(stmt,2);
        std::cout<<"PRICE OF EACH TOOL:"<<sqlite3_column_int(stmt,3);
        std::cout<<"TOTAL COST:"<<sqlite3_column_int(stmt,4);
        b=sqlite3_column_int(stmt,4);
        sqlite3_bind_int(stmt1,2,b,-1,SQLITE_TRANSIENT);
       };
       sqlite3_finalize(stmt);
       free sql;
       sqlite3_finalize(stmt1);
       free sql1;
       };
    };
    class Works{
    void water_task(){
    sqlite3_stmt* stmt;
    sqlite3_stmt* stmt1;
    int a,b,c,e,g,h;
    srtring d;
    std::cout<<"Enter the id of water task:\n";
    std::cin>>a;
    std::cout<<"Enter time of task being done(starting):\n";
    std::cin>>b;
    std::cout<<"Enter the status\n";
    std::cin>>d;
    std::cout<<"Enter the date of task being done:\n";
    std::cin>>e;
    std::cout<<"Enter the tool number:\n";
    std::cin>>g;
    std::cout<<"Enter the registration ID:\n";
    std::cin>>h;
    char *sql="INSERT INTO Water_task (a,b,e,c,g,h,d) VALUES(?,?,?,?,?,?,?);";
    sqlite3_prepare_v2(
       DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
     char *sql1="SELECT zone_num,(nop_zone*0.5+not_zone*10)*(1+density_zone*0.2) AS WATER_USAGE FROM Zones;";
      while(sqlite3_step(stmt1)==SQLITE_ROW){
            if(f==sqlite_column_int(stmt1,1)){
                c=sqlite3_column_int(stmt1,2);
            };
      };
     sqlite3_bind_int(stmt,1,a,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,2,b,-1,sqlite_transient);
     sqlite3_bind_int(stmt,3,e,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,4,c,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,5,g,-1,sqlite_transient);
     sqlite3_bind_int(stmt,6,h,-1,SQLITE_TRANSIENT);
     sqlite3_bind_text(stmt,7,d,-1,sqlite_transient);
     sqlite3_finalize(stmt);
     free sql;
     sqlite3_finalize(stmt1);
     free sql1;
    };

    void GrassTrim(){
    sqlite3_stmt *stmt;
    std::cout<<"Enter the id of grass trim task:\n";
    std::cin>>a;
    std::cout<<"Enter time of task being done(starting):\n";
    std::cin>>b;
    std::cout<<"Enter the status\n";
    std::cin>>d;
    std::cout<<"Enter the date of task being done:\n";
    std::cin>>e;
    std::cout<<"Enter the tool number:\n";
    std::cin>>g;
    std::cout<<"Enter the registration ID:\n";
    std::cin>>h;
    char *sql="INSERT INTO Grasstrim_task (a,b,e,g,h,d) VALUES(?,?,?,?,?,?);";
    sqlite3_prepare_v2(
       DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
    }
    sqlite3_bind_int(stmt,1,a,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,2,b,-1,sqlite_transient);
     sqlite3_bind_int(stmt,3,e,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,4,g,-1,sqlite_transient);
     sqlite3_bind_int(stmt,5,h,-1,SQLITE_TRANSIENT);
     sqlite3_bind_text(stmt,6,d,-1,sqlite_transient);
     sqlite3_finalize(stmt);
     free sql;
    };

    void Deweed_task(){
    sqlite3_stmt *stmt;
    std::cout<<"Enter the id of deweed task:\n";
    std::cin>>a;
    std::cout<<"Enter time of task being done(starting):\n";
    std::cin>>b;
    std::cout<<"Enter the status\n";
    std::cin>>d;
    std::cout<<"Enter the date of task being done:\n";
    std::cin>>e;
    std::cout<<"Enter the tool number:\n";
    std::cin>>g;
    std::cout<<"Enter the registration ID:\n";
    std::cin>>h;
    char *sql="INSERT INTO Deweed_task (a,b,e,g,h,d) VALUES(?,?,?,?,?,?);";
    sqlite3_prepare_v2(
       DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
    }
     sqlite3_bind_int(stmt,1,a,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,2,b,-1,sqlite_transient);
     sqlite3_bind_int(stmt,3,e,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,4,g,-1,sqlite_transient);
     sqlite3_bind_int(stmt,5,h,-1,SQLITE_TRANSIENT);
     sqlite3_bind_text(stmt,6,d,-1,sqlite_transient);
     sqlite3_finalize(stmt);
     free sql;
    };

    void Treeshape_task(){
    sqlite3_stmt *stmt;
    std::cout<<"Enter the id of tree shaping task:\n";
    std::cin>>a;
    std::cout<<"Enter time of task being done(starting):\n";
    std::cin>>b;
    std::cout<<"Enter the status\n";
    std::cin>>d;
    std::cout<<"Enter the date of task being done:\n";
    std::cin>>e;
    std::cout<<"Enter the tool number:\n";
    std::cin>>g;
    std::cout<<"Enter the registration ID:\n";
    std::cin>>h;
    char *sql="INSERT INTO Treeshape_task(a,b,e,g,h,d) VALUES(?,?,?,?,?,?);";
    sqlite3_prepare_v2(
       DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
    }
     sqlite3_bind_int(stmt,1,a,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,2,b,-1,sqlite_transient);
     sqlite3_bind_int(stmt,3,e,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,4,g,-1,sqlite_transient);
     sqlite3_bind_int(stmt,5,h,-1,SQLITE_TRANSIENT);
     sqlite3_bind_text(stmt,6,d,-1,sqlite_transient);
     sqlite3_finalize(stmt);
     free sql;
    };


    sqlite3_close(DB);
    return 0;


}
