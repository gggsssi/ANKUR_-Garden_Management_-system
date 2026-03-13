#include <iostream>
#include "sqlite3.h"
using namespace std;

   class DATACENTER{
    static sqlite3* DB;
    char *errMSG=nullptr;
public:
    DATACENTER(){
    if(sqlite3_open("garden.db", &DB)) {
        std::cout << "Error opening database\n";
    }
     else {
        std::cout << "Database opened successfully\n";
    }}
   };

    class DataStorage{

    void registerUsers(){
    const char* Users =
        "CREATE TABLE IF NOT EXISTS users ("
        "registration_id  INTEGER PRIMARY KEY ,"
        "  name VARCHAR(30) NOT NULL,"
        "  course VARCHAR(20) NOT NULL,"
        "  sem_number  INT  NOT NULL "
        ");";
    if(sqlite3_exec(DB,Users,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creating users :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of users  succesful\n";}
    };

    void registerZones(){
    const char* Zones =
        "CREATE TABLE IF NOT EXISTS Zones("
        "zone_num INTEGER PRIMARY KEY ,"
        "zone_name VARCHAR(30) NOT NULL,"
        " nop_zone INT NOT NULL,"
        " density_zone INT NOT NULL,"
        " not_zone  INT  NOT NULL "
        ");";

    if(sqlite3_exec(DB,Zones,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creating zones:"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of zones succesful\n";
     }
    };

    void registerTasks(){
    const char* Tasks=
    " CREATE TABLE IF NOT EXISTS tasks("
    " task_num INT PRIMARY KEY ,"
    "zoneNUM INT ,"
    " task_dscrptn VARCHAR(180) ,"
    "CONSTRAINT fk_registertasks "
    "FOREIGN KEY (zoneNUM) REFERENCES Zones(zone_num)"
    " ON DELETE CASCADE"
    " ON UPDATE CASCADE"
    ");";
     if(sqlite3_exec(DB,Tasks,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creating tasks:"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of taks  succesful\n";
     }
    };

    void assignTasks(){
    const char* Assignd=
    " CREATE TABLE IF NOT EXISTS assignd("
    " regist_num INT PRIMARY KEY,"
    "task_num INT NOT NULL,"
    "FOREIGN KEY (regist_num) REFERENCES Users(registration_id),"
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num) "
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE"";";
     if(sqlite3_exec(DB,Assignd,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at assiging tasks:"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of Assignd succesful\n";
     }
    };

    void ScheduleTasks(){
    const char* Scheduler=
    "CREATE TABLE IF NOT EXISTS Scheduler("
    " task_num INT NOT NULL,"
    "due_date DATE,"
    "time  TIME,"
    "nodl INT ,"
    "lw DATE,"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num) "
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE"";";
    if(sqlite3_exec(DB,Scheduler,0,nullptr,&errMSG)!=SQLITE_OK){
         std::cout<<"error occurred at scheduling tasks:"<< errMSG<<"\n";
        sqlite3_free(errMSG);
     }
    else{
        std::cout<<"table creation of Scheduler succesful\n";
    }
    };


    void Inventory(){
    const char* Inventory=
    "CREATE TABLE IF NOT EXISTS Inventory("
    "tool_num INT PRIMARY KEY ,"
    "tool_name VARCHAR(30) NOT NULL,"
    "nt INT ,"
    "price INT CHECK(PRICE>0),"
    "YOU INT);";
     if(sqlite3_exec(DB,Inventory,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creating inventory table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of inventory  succesful\n";}
    };

    void Tracker(){
    const char* Tracker=
    "CREATE TABLE IF NOT EXISTS Inventory("
    "tool_num INT PRIMARY KEY ,"
    "registration_number INT NOT NULL"";";
         if(sqlite3_exec(DB,Tracker,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creating inventory tracker table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
        else{
          std::cout<<"table creation of inventory tracker  succesful\n";}
    };

    void costTracker(){
    const char* Cost_TRACKER=
    "CREATE TABLE IF NOT EXISTS Cost_TRACKER("
    "tool_NUMBER INT PRIMARY KEY,"
    "TOTAL_COST INT NOT NULL);";

    if(sqlite3_exec(DB,Cost_TRACKER,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at cost tracker table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of cost tracker  succesful\n";}
    };

    void Watertask(){
    const char* Water_task=
    "CREATE TABLE IF NOT EXISTS Water_task("
    "Task_num INT PRIMARY KEY ,"
    "time_done INT NOT NULL,"
    "DATE INT ,"
    "WATER_USAGE INT,"
    "TOOL_NUMBER INT,"
    "WORKER_ID INT,"
    "STATUS VARCHAR(10),"
    "FOREIGN KEY (TOOL_NUMBER) REFERENCES Inventory(tool_num)"
    "ON DELETE CASCADE"
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (WORKER_ID) REFERENCES Users(registration_id)"
    "ON DELETE CASCADE"
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num)"
    "ON DELETE CASCADE"
    "ON UPDATE CASCADE"";";
      if(sqlite3_exec(DB,Water_task,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at water task table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of water task succesful\n";}
    };

     void Grasstrimtask(){
     const char* Grasstrim_task=
    "CREATE TABLE IF NOT EXISTS Grasstrim_task("
    "Task_num INT PRIMARY KEY ,"
    "time_done INT NOT NULL,"
    "DATE INT ,"
    "TOOL_NUMBER INT,"
    "WORKER_ID INT,"
    "STATUS VARCHAR(10),"
    "FOREIGN KEY (TOOL_NUMBER) REFERENCES Inventory(tool_num)"
    "ON DELETE CASCADE"
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (WORKER_ID) REFERENCES Users(registration_id)"
    "ON DELETE CASCADE"
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num)"
    "ON DELETE CASCADE"
    "ON UPDATE CASCADE"";";
     if(sqlite3_exec(DB,Grasstrim_task,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at grasstrim task table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of grasstrim task succesful\n";}
     };

     void Deweedtask(){
     const char* Deweed_task=
    "CREATE TABLE IF NOT EXISTS Deweed_task("
    "Task_num INT PRIMARY KEY ,"
    "time_done INT NOT NULL,"
    "DATE INT ,"
    "TOOL_NUMBER INT,"
    "WORKER_ID INT,"
    "STATUS VARCHAR(10),"
    "FOREIGN KEY (TOOL_NUMBER) REFERENCES Inventory(tool_num)"
    "ON DELETE CASCADE"
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (WORKER_ID) REFERENCES Users(registration_id)"
    "ON DELETE CASCADE"
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num)"
    "ON DELETE CASCADE"
    "ON UPDATE CASCADE"";";
    if(sqlite3_exec(DB,Deweed_task,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at deweed task table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of deweed task succesful\n";}
     };

     void Treeshapetask(){
     const char* Treeshape_task=
    "CREATE TABLE IF NOT EXISTS Treeshape_task("
    "Task_num INT PRIMARY KEY ,"
    "time_done INT NOT NULL,"
    "DATE INT ,"
    "TOOL_NUMBER INT,"
    "WORKER_ID INT,"
    "STATUS VARCHAR(10),"
    "FOREIGN KEY (TOOL_NUMBER) REFERENCES Inventory(tool_num)"
    "ON DELETE CASCADE"
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (WORKER_ID) REFERENCES Users(registration_id)"
    "ON DELETE CASCADE"
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num)"
    "ON DELETE CASCADE"
    "ON UPDATE CASCADE"";";
    if(sqlite3_exec(DB,Treeshape_task,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at treeshape task table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of treeshape task succesful\n";}
     };

     void load(string tbnm){
         sqlite3_stmt *stmt;
         char *sql="Select * from " + std::to_string(tbnm) + ";"; "
         sqlite3_prepare_v2(DB,sql,-1,&stmt,nullptr);
         sqlite3_step(stmt);
         sqlite3_finalize(stmt);
         free sql;
      };

     void database(){
      DataStorage ds;
     ds.load(Users);
     ds.load(Zones);
     ds.load( Tasks);
     ds.load( Assignd);
     ds.load(Scheduler);
     ds.load(Inventory);
     ds.load(Tracker);
     ds.load(Cost_TRACKER);
     ds.load(Water_task);
     ds.load( Grasstrimtask);
     ds.load(Deweedtask);
     ds.load(Treeshape_task);};
    };


    void reclog( string table_name ){
     const std::string logs=
     "CREATE TABLE IF NOT EXISTS LOGS("
     "  log_id INTEGER PRIMARY KEY AUTOINCREMENT,"
     "table_name VARCHAR(20),"
     "action VARCHAR(30),"
      "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP"";";
      if(sqlite3_exec(DB,logs.c_str(),0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creation of logs table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of logs succesful\n";}

    const std::string logsin=
    "CREATE TRIGGER log_" + table_name + "_insert"
     "AFTER INSERT ON " + table_name + ""
    "BEGIN"
     "INSERT INTO logs(table_name, action)"
      "VALUES('" + table_name + "', 'INSERT');"
     "END"";"
     sqlite3_exec(DB,logsin.c_str(),0,nullptr,&errMSG);

    const std::string logsup=
    "CREATE TRIGGER log_" + table_name + "_update"
"AFTER UPDATE ON " + table_name + ""
"BEGIN"
    "INSERT INTO logs(table_name, action)"
    "VALUES( '" + table_name + "', 'UPDATE');"
"END;"";"
     sqlite3_exec(DB,logsup.c_str(),0,nullptr,&errMSG);

     const std::string logsdel=
     "CREATE TRIGGER log_" + table_name + "_delete"
"AFTER DELETE ON " + table_name + ""
"BEGIN"
    "INSERT INTO logs(table_name, action)"
    "VALUES('" + table_name + "', 'DELETE');"
"END;""
     sqlite3_exec(DB,logsdel.c_str(),0,nullptr,&errMSG);
    };
    };

    class DepartmentModule{
   public:
       static string name;
       static int regid;
   virtual void execute(){
   std::cout<<"Enter your name:\n"
   std::cin>>name;
   std:cout<<"Enter your registration id:\n"
   std::cin>>regid;
   };
   };

    class registration:public DepartmentModule{
    public :
        static string course;
        static int sem_number;
        static int zone_num,nop_zone,density_zone,not_zone;
        static string zone_name;
        void registerUser(){
        std::cout<<"Enter your course:\n";
        std::cin>>course;
        std::cout<<"Enter the semester number:\n";
        std::cin>>sem_number;
    DataStorage ds;
    ds.registerUsers();
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO users (name,course,sem_number,registration_id) VALUES (?, ?,?,?);";
    sqlite3_prepare_v2(
    DB,         // database handle
    sql,        // SQL with ? placeholders
    -1,         // length of sql (-1 = auto-detect)
    &stmt,      // prepared statement written here
    nullptr     // pointer to unused portion of sql (usually nullptr)
    );
    sqlite3_bind_int(stmt,1,regid,-1,SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,2,name,-1,SQLITE_TRANSIENT);
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
         DataStorage ds1;
         ds1.registerZones();
        sqlite3_stmt* stmt;
        const char* sql = "INSERT INTO Zones (zone_name,zone_num,nop_zone,density_zone,not_zone) VALUES (?, ?,?,?,?);";
        sqlite3_prepare_v2(
        DB,         // database handle
        sql,        // SQL with ? placeholders
        -1,         // length of sql (-1 = auto-detect)
        &stmt,      // prepared statement written here
        nullptr     // pointer to unused portion of sql (usually nullptr)
        );
         sqlite3_bind_int(stmt,1,zone_num,-1,SQLITE_TRANSIENT);
         sqlite3_bind_text(stmt,2,zone_name,-1,sqlite_transient);
         sqlite3_bind_int(stmt,3,nop_zone,-1,SQLITE_TRANSIENT);
         sqlite3_bind_int(stmt,4,density_zone,-1,SQLITE_TRANSIENT);
         sqlite3_bind_int(stmt,5,not_zone,-1,SQLITE_TRANSIENT)
         sqlite3_step(stmt);
         sqlite3_finalize(stmt);
        free sql;
        };
     void usersshow(){
     DataStorage ds;
     ds.load(Zones);};

     void zonesshow(){
          DataStorage ds;
     ds.load(Zones);
     };
    };
    class TaskManager:public DepartmentModule{
    public:
        static int task_num,zone_num;
        static string task_dscrptn,status;
        int a,b;
        void createTask(){
        std::cout<<"Enter task number:\n";
        std::cin>>task_num;
        std::cout<<"Enter the zone number:\n";
        std::cin>>zone_num;
        std::cout<<"Enter description of the task:\n";
        std::cin>>task_dscrptn;
        Datastorage ds;
        ds.registerTasks();
        sqlite3_stmt* stmt;
        const char* sql = "INSERT INTO tasks (task_num,task_dscrptn) VALUES (?, ?);";
        sqlite3_prepare_v2(
        DB,         // database handle
        sql,        // SQL with ? placeholders
        -1,         // length of sql (-1 = auto-detect)
        &stmt,      // prepared statement written here
        nullptr     // pointer to unused portion of sql (usually nullptr)
        );
        sqlite3_bind_int(stmt,1,task_num,-1,SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt,2,zone_num,-1,sqlite_transient);
        sqlite3_bind_text(stmt,3,task_dscrptn,-1,SQLITE_TRANSIENT);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        free sql;
        };

       void assignTask(){
       std::cout<<"You have opted to assign task to a member\n"
       std::cout<<"Enter the registration id of member to whom task is to be assigned:\n";
       std::cin>>a;
       std::cout<<"Enter the task number:\n";
       std::cin>>b;
       DataStorage ds;
       ds.assignTasks();
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
     void tasklistshow(){
     DataStorage ds;
     ds.load(Zones);
         };
    };

    class Scheduler:public DepartmentModule{
    public:
      void scheduleWork(){
       static string date,time;
       static int nodl,lw;
       int k;
       static string status;
        Datastorage ds;
        ds.ScheduleTasks();
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
       sqlite3_bind_text(stmt,2,date,-1,sqlite_transient);
       sqlite3_bind_text(stmt,3,time,-1,SQLITE_TRANSIENT);
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
      const std::string sql = "select task_num ,status from Scheduler where task_num=" + std::to_string(a) + ";";

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
     void showworkSchedule(){
     DataStorage ds;
     ds.load(Scheduler);
     };
 };
    class ResourceTracker:public DepartmentModule{
     private :
        int h,g;
     public:
        void updateinventory(){
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

       DataStorage ds;
       ds.Inventory();
       sqlite3_stmt* stmt;
       char *sql="Insert into Inventory (tool_num,tool_name,price,you,nt) VALUES(?,?,?,?,?);";
       sqlite3_prepare_v2(
       DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
       sqlite3_bind_int(stmt,1,tool_num,-1,SQLITE_TRANSIENT);
       sqlite3_bind_text(stmt,2,tool_name,-1,SQLITE_TRANSIENT);
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
       Datastorage ds;
       ds. Tracker();
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
      Datastorage ds;
      ds.costTracker();
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
     void Inventoryshow(){
     Datastorage ds;
     ds.load(Zones);
     };
    };
    class ActivityTask:public TaskManager,public Scheduler{
    public:
       void execute(){
        int a,
       public:
       int b,c;
       std::cout<<"Enter the task num:\n";
       std::cin>>b;
       sqlite3_stmt *stmt;
       c="Select zone_num from tasks where task_num = (?);";
       sqlite3_bind_int(stmt,1,b,-1,SQLITE_TRANSIENT);
       sqlite3_prepare_v2(
       DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
       sqlite3_finalize(stmt);
       free sql;
       std::cout<<"Select from the following tasks :\n";
       std::cout<<"1.WaterTask\n">>"2.GrassTrimTask\n">>"3.DeWeedTask\n">>"4.TreeShapeTask\n";
       std::cin>>a
       if(a==1)
        {
            WaterTask wt;
            wt.execute();
        }
      else if(a==2)
      {
          GrassTrimTask gt;
          gt.execute();
      }
      else if(a==3)
      {
       DeWeedTask dw;
       dw.execute();
      }
      else if(a==4)
      {
          TreeShapeTask ts;
          ts.execute();
      }
      else{
        std::cout<<"NO such option available\n";
      }

       };

    };

    class WaterTask: public ActivityTask{
    sqlite3_stmt* stmt;
    sqlite3_stmt* stmt1;
    public:
    int b,c,e,g,h;
    srtring d;
    void execute(){
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
     Datastorage ds;
     ds.Watertask();
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
            }
      };
     sqlite3_bind_int(stmt,1,task_num,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,2,b,-1,sqlite_transient);
     sqlite3_bind_int(stmt,3,e,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,4,c,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,5,g,-1,sqlite_transient);
     sqlite3_bind_int(stmt,6,h,-1,SQLITE_TRANSIENT);
     sqlite3_bind_text(stmt,7,d,-1,sqlite_transient);
     std::cout<<"The task "<<task_num<<"aassigned at zone "<<ActivityTask::c<<"has been completed\n";
     sqlite3_finalize(stmt);
     free sql;
     sqlite3_finalize(stmt1);
     free sql1;
    };
    };

    class GrassTrimTask:public ActivityTask{
    sqlite3_stmt *stmt;
    public:
    int b,c,e,g,h;
    srtring d;
    void execute(){
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
    Datastorage ds;
    ds.Grasstrimtask();
    char *sql="INSERT INTO Grasstrim_task (a,b,e,g,h,d) VALUES(?,?,?,?,?,?);";
    sqlite3_prepare_v2(
       DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );

     sqlite3_bind_int(stmt,1,task_num,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,2,b,-1,sqlite_transient);
     sqlite3_bind_int(stmt,3,e,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,4,g,-1,sqlite_transient);
     sqlite3_bind_int(stmt,5,h,-1,SQLITE_TRANSIENT);
     sqlite3_bind_text(stmt,6,d,-1,sqlite_transient);
     std::cout<<"The task "<<task_num<<"aassigned at zone "<<ActivityTask::c<<"has been completed\n";
     sqlite3_finalize(stmt);
     free sql;
    };
    };

    class DeWeedTask:public ActivityTask{
    public:
    sqlite3_stmt *stmt;
    void execute(){
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
     Datastorage ds;
     ds.Deweedtask();
    char *sql="INSERT INTO Deweed_task (a,b,e,g,h,d) VALUES(?,?,?,?,?,?);";
    sqlite3_prepare_v2(
       DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );

     sqlite3_bind_int(stmt,1,task_num,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,2,b,-1,sqlite_transient);
     sqlite3_bind_int(stmt,3,e,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,4,g,-1,sqlite_transient);
     sqlite3_bind_int(stmt,5,h,-1,SQLITE_TRANSIENT);
     sqlite3_bind_text(stmt,6,d,-1,sqlite_transient);
     std::cout<<"The task "<<task_num<<"aassigned at zone "<<ActivityTask::c<<"has been completed\n";
     sqlite3_finalize(stmt);
     free sql;
    };
    };

    class TreeShapeTask:public ActivityTask{
    sqlite3_stmt *stmt;
    void execute(){
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
    Datastorage ds;
    ds.Treeshapetask();
    char *sql="INSERT INTO Treeshape_task(a,b,e,g,h,d) VALUES(?,?,?,?,?,?);";
    sqlite3_prepare_v2(
       DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );

     sqlite3_bind_int(stmt,1,task_num,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,2,b,-1,sqlite_transient);
     sqlite3_bind_int(stmt,3,e,-1,SQLITE_TRANSIENT);
     sqlite3_bind_int(stmt,4,g,-1,sqlite_transient);
     sqlite3_bind_int(stmt,5,h,-1,SQLITE_TRANSIENT);
     sqlite3_bind_text(stmt,6,d,-1,sqlite_transient);
     std::cout<<"The task "<<task_num<<"aassigned at zone "<<ActivityTask::c<<"has been completed\n";
     sqlite3_finalize(stmt);
     free sql;
    };
    };


    sqlite3_close(DB);
    return 0;

    };

int main(){


}

