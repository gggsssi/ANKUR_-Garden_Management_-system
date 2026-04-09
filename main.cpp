#include <iostream>
#include <stdexcept>
#include "sqlite3.h"
#include<fstream>
using std::string;

   class DATACENTER{
    public:
    static sqlite3* DB;
    char *errMSG=nullptr;
    public:
    DATACENTER(){
    if(sqlite3_open("garden.db", &DB)) {
        throw string("!!THERE WAS A PROBLEM SETTING UP DATABASE!!\n");
        std::cout << "Error opening database\n";
        sqlite3_free(errMSG);
    }
     else {
        sqlite3_exec(DB, "PRAGMA foreign_keys = ON;", 0, 0, 0);
        std::cout << "Database opened successfully\n";
    }}
   };

    class DataStorage{
    public:
    void registerUsers(){
    const char* Users =
        "CREATE TABLE IF NOT EXISTS users ("
        "registration_id  INTEGER PRIMARY KEY ,"
        "  name VARCHAR(30) NOT NULL,"
        "  course VARCHAR(20) NOT NULL,"
        "  sem_number  INT  NOT NULL "
        ");";
    char *errMSG=nullptr;
    if(sqlite3_exec(DATACENTER::DB,Users,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creating users :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of users  succesful\n";}
    }

    void registerZones(){
    const char* Zones =
        "CREATE TABLE IF NOT EXISTS Zones("
        "zone_num INTEGER PRIMARY KEY ,"
        "zone_name VARCHAR(30) NOT NULL,"
        " nop_zone INT NOT NULL,"
        " density_zone INT NOT NULL,"
        " not_zone  INT  NOT NULL "
        ");";

    char *errMSG=nullptr;
    if(sqlite3_exec(DATACENTER::DB,Zones,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creating zones:"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of zones succesful\n";
     }
    }

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
     char *errMSG=nullptr;
     if(sqlite3_exec(DATACENTER::DB,Tasks,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creating tasks:"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of taks  succesful\n";
     }
    }

    void assignTasks(){
    const char* Assignd=
    " CREATE TABLE IF NOT EXISTS assignd("
     "task_num INT NOT NULL,"
    " regist_num INT PRIMARY KEY,"
    "FOREIGN KEY (regist_num) REFERENCES Users(registration_id) "
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num) "
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE"
    ");";
     char *errMSG=nullptr;
     if(sqlite3_exec(DATACENTER::DB,Assignd,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at assiging tasks:"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of Assignd succesful\n";
     }
    }

    void ScheduleTasks(){
    const char* Scheduler=
    "CREATE TABLE IF NOT EXISTS Scheduler("
    " task_num INT NOT NULL,"
    "due_date DATE,"
    "time  TIME,"
    "nodl INT ,"
    "lw DATE,"
    "status VARCHAR(20),"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num) "
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE "
    ");";
    char *errMSG=nullptr;
    if(sqlite3_exec(DATACENTER::DB,Scheduler,0,nullptr,&errMSG)!=SQLITE_OK){
         std::cout<<"error occurred at scheduling tasks:"<< errMSG<<"\n";
        sqlite3_free(errMSG);
     }
    else{
        std::cout<<"table creation of Scheduler succesful\n";
    }
    }


    void toolbox(){
    const char* Inventory=
    "CREATE TABLE IF NOT EXISTS Inventory("
    "tool_num INT PRIMARY KEY ,"
    "tool_name VARCHAR(30) NOT NULL,"
    "nt INT ,"
    "price INT CHECK(PRICE>0),"
    "YOU INT);";
     char *errMSG=nullptr;
     if(sqlite3_exec(DATACENTER::DB,Inventory,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creating inventory table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of inventory  succesful\n";}
    }

    void tbuser(){
    const char* Tracker=
    "CREATE TABLE IF NOT EXISTS Tracker("
    "tool_num INT PRIMARY KEY ,"
    "registration_number INT NOT NULL"
    ");";
         char *errMSG=nullptr;
         if(sqlite3_exec(DATACENTER::DB,Tracker,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creating inventory tracker table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
        else{
          std::cout<<"table creation of inventory tracker  succesful\n";}
    }

    void costTracker(){
    const char* Cost_TRACKER=
    "CREATE TABLE IF NOT EXISTS Cost_TRACKER("
    "tool_NUMBER INT PRIMARY KEY,"
    "TOTAL_COST INT NOT NULL);";
    char *errMSG=nullptr;
    if(sqlite3_exec(DATACENTER::DB,Cost_TRACKER,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at cost tracker table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of cost tracker  succesful\n";}
    }

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
    "FOREIGN KEY (TOOL_NUMBER) REFERENCES Inventory(tool_num) "
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (WORKER_ID) REFERENCES Users(registration_id) "
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num) "
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE"";";
    char *errMSG=nullptr;
    if(sqlite3_exec(DATACENTER::DB,Water_task,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at water task table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of water task succesful\n";}
    }

     void Grasstrimtask(){
     const char* Grasstrim_task=
    "CREATE TABLE IF NOT EXISTS Grasstrim_task("
    "Task_num INT PRIMARY KEY ,"
    "time_done INT NOT NULL,"
    "DATE INT ,"
    "TOOL_NUMBER INT,"
    "WORKER_ID INT,"
    "STATUS VARCHAR(10),"
    "FOREIGN KEY (TOOL_NUMBER) REFERENCES Inventory(tool_num) "
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (WORKER_ID) REFERENCES Users(registration_id) "
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num) "
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE"";";
    char *errMSG=nullptr;
    if(sqlite3_exec(DATACENTER::DB,Grasstrim_task,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at grasstrim task table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of grasstrim task succesful\n";}
     }

     void Deweedtask(){
     const char* Deweed_task=
    "CREATE TABLE IF NOT EXISTS Deweed_task("
    "Task_num INT PRIMARY KEY ,"
    "time_done INT NOT NULL,"
    "DATE INT ,"
    "TOOL_NUMBER INT,"
    "WORKER_ID INT,"
    "STATUS VARCHAR(10),"
    "FOREIGN KEY (TOOL_NUMBER) REFERENCES Inventory(tool_num) "
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (WORKER_ID) REFERENCES Users(registration_id) "
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num) "
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE"";";
    char *errMSG=nullptr;
    if(sqlite3_exec(DATACENTER::DB,Deweed_task,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at deweed task table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of deweed task succesful\n";}
     }

     void Treeshapetask(){
     const char* Treeshape_task=
    "CREATE TABLE IF NOT EXISTS Treeshape_task("
    "Task_num INT PRIMARY KEY ,"
    "time_done INT NOT NULL,"
    "DATE INT ,"
    "TOOL_NUMBER INT,"
    "WORKER_ID INT,"
    "STATUS VARCHAR(10),"
    "FOREIGN KEY (TOOL_NUMBER) REFERENCES Inventory(tool_num) "
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (WORKER_ID) REFERENCES Users(registration_id) "
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE,"
    "FOREIGN KEY (task_num) REFERENCES Tasks(task_num) "
    "ON DELETE CASCADE "
    "ON UPDATE CASCADE"";";
    char *errMSG=nullptr;
    if(sqlite3_exec(DATACENTER::DB,Treeshape_task,0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at treeshape task table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of treeshape task succesful\n";}
     }

     void load(string tbnm){
         if(tbnm.empty())
            {
                throw std::invalid_argument("load(): table name cannot be empty");
            }
         sqlite3_stmt *stmt;
         string sql="Select * from " + tbnm + ";";
         sqlite3_prepare_v2(DATACENTER::DB,sql.c_str(),-1,&stmt,nullptr);
         while(sqlite3_step(stmt)==SQLITE_ROW){
         int cols = sqlite3_column_count(stmt);
         for(int i=0;i<cols;i++){
         const char* colname =
            sqlite3_column_name(stmt,i);

         const unsigned char* val =
            sqlite3_column_text(stmt,i);

        std::cout << colname << ": " << val << "  ";
        }
        std::cout<<"\n";
    }
    sqlite3_finalize(stmt);
      }

     void database(){
      DataStorage ds;
     ds.load("Users");
     ds.load("Zones");
     ds.load( "Tasks");
     ds.load( "Assignd");
     ds.load("Scheduler");
     ds.load("Inventory");
     ds.load("Tracker");
     ds.load("Cost_TRACKER");
     ds.load("Water_task");
     ds.load( "Grasstrimtask");
     ds.load("Deweedtask");
     ds.load("Treeshape_task");}

    void reclog( string table_name ){
     const std::string logs=
     "CREATE TABLE IF NOT EXISTS LOGS("
     "  log_id INTEGER PRIMARY KEY AUTOINCREMENT,"
     "table_name VARCHAR(20),"
     "action VARCHAR(30),"
      "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP"
      ");";
    char *errMSG=nullptr;
    if(sqlite3_exec(DATACENTER::DB,logs.c_str(),0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creation of logs table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of logs succesful\n";}

    const std::string logsin=
    "CREATE TRIGGER log_" + table_name + "_insert "
     "AFTER INSERT ON " + table_name + " "
    "BEGIN "
     "INSERT INTO logs(table_name, action) "
      "VALUES('" + table_name + "', 'INSERT');"
     "END;";
      if(sqlite3_exec(DATACENTER::DB,logsin.c_str(),0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creation of logs table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of logs succesful\n";}

    const std::string logsup=
    "CREATE TRIGGER log_" + table_name + "_update "
"AFTER UPDATE ON " + table_name + " "
"BEGIN "
    "INSERT INTO logs(table_name, action) "
    "VALUES( '" + table_name + "', 'UPDATE');"
"END;";
      if(sqlite3_exec(DATACENTER::DB,logsup.c_str(),0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creation of logs table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of logs succesful\n";}

     const std::string logsdel=
     "CREATE TRIGGER log_" + table_name + "_delete "
"AFTER DELETE ON " + table_name + " "
"BEGIN "
    "INSERT INTO logs(table_name, action) "
    "VALUES('" + table_name + "', 'DELETE');"
"END;";
      if(sqlite3_exec(DATACENTER::DB,logsdel.c_str(),0,nullptr,&errMSG)!=SQLITE_OK){
        std::cout<<"error occurred at creation of logs table :"<< errMSG<<"\n";
        sqlite3_free(errMSG);}
    else{
        std::cout<<"table creation of logs succesful\n";}
    };
    };

    class DepartmentModule{
   public:
       static string name;
       static int regid;
   virtual void execute()=0;
   };

    class registration:public DepartmentModule{
    public :
        static string course;
        static int sem_number;
        static int zone_num,nop_zone,density_zone,not_zone;
        static string zone_name;
        string local_name;
        string local_course;
        int local_regid;
        int local_sem;
        registration() {
          local_name   = "";
          local_course = "";
          local_regid  = 0;
          local_sem    = 0;
        }
        registration(const registration& other) {
            this->local_name   = other.local_name;
            this->local_course = other.local_course;
            this->local_regid  = other.local_regid;
            this->local_sem    = other.local_sem;
            std::cout << "[Backup Created] name=" << this->local_name
                      << " | course=" << this->local_course
                      << " | regid=" << this->local_regid
                      << " | sem=" << this->local_sem << "\n";
            }

        void execute(){
        std::cout<<"Enter your name:\n";
        std::getline(std::cin,name,'\n');
        local_name = name;
        std::cout<<"Enter your registration id:\n";
        std::cin>>regid;
        local_regid = regid;
   }
        void registerUser(){
        std::cout<<"Enter your course:\n";
        std::cin>>course;
        local_course = course;
        std::cout<<"Enter the semester number:\n";
        std::cin>>sem_number;
        local_sem = sem_number;
        if(name.empty())
            throw std::invalid_argument("registerUser(): name cannot be empty");
        if(course.empty())
            throw std::invalid_argument("registerUser(): course cannot be empty");
         if(sem_number < 1 || sem_number > 8)
            throw std::out_of_range("registerUser(): semester must be between 1 and 8, got: " + std::to_string(sem_number));
    DataStorage ds;
    ds.registerUsers();
    registration backup = *this;
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO users (registration_id,name,course,sem_number) VALUES (?, ?,?,?);";
    sqlite3_prepare_v2(
    DATACENTER::DB,         // database handle
    sql,        // SQL with ? placeholders
    -1,         // length of sql (-1 = auto-detect)
    &stmt,      // prepared statement written here
    nullptr     // pointer to unused portion of sql (usually nullptr)
    );
    sqlite3_bind_int(stmt,1,regid);
    sqlite3_bind_text(stmt,2,name.c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,3,course.c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt,4,sem_number);
    if(sqlite3_step(stmt) != SQLITE_DONE){
          sqlite3_reset(stmt);
          sqlite3_bind_int(stmt,1,local_regid);
          sqlite3_bind_text(stmt,2,local_name.c_str(),-1,SQLITE_TRANSIENT);
          sqlite3_bind_text(stmt,3,local_course.c_str(),-1,SQLITE_TRANSIENT);
          sqlite3_bind_int(stmt,4,local_sem);
          sqlite3_step(stmt);
        }
    sqlite3_finalize(stmt);
    }
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
        std::cin.ignore();
        std::getline(std::cin, zone_name);
        if(nop_zone < 0)
            throw std::out_of_range("Zone_process(): number of plants cannot be negative");
        if(not_zone < 0)
            throw std::out_of_range("Zone_process(): number of trees cannot be negative");
         DataStorage ds1;
         ds1.registerZones();
        sqlite3_stmt* stmt;
        const char* sql = "INSERT INTO Zones (zone_name,zone_num,nop_zone,density_zone,not_zone) VALUES (?, ?,?,?,?);";
        sqlite3_prepare_v2(
        DATACENTER::DB,         // database handle
        sql,        // SQL with ? placeholders
        -1,         // length of sql (-1 = auto-detect)
        &stmt,      // prepared statement written here
        nullptr     // pointer to unused portion of sql (usually nullptr)
        );
         sqlite3_bind_int(stmt,1,zone_num);
         sqlite3_bind_text(stmt,2,zone_name.c_str(),-1,SQLITE_TRANSIENT);
         sqlite3_bind_int(stmt,3,nop_zone);
         sqlite3_bind_int(stmt,4,density_zone);
         sqlite3_bind_int(stmt,5,not_zone);
         sqlite3_step(stmt);
         sqlite3_finalize(stmt);
        }
     void usersshow(){
     DataStorage ds;
     ds.load("Users");}

     void zonesshow(){
          DataStorage ds;
     ds.load("Zones");
     }
    };
    class TaskManager:public DepartmentModule{
    public:
        static int task_num,zone_num;
        static string task_dscrptn;
        int a,b;
        void execute(){
        std::cout<<"YOU HAVE ENETERED TASK MANAGER\n";}

        void createTask(){
        std::cout<<"Enter task number:\n";
        std::cin>>task_num;
        std::cout<<"Enter the zone number:\n";
        std::cin>>zone_num;
        std::cout<<"Enter description of the task:\n";
         std::cin.ignore();
        std::getline(std::cin,task_dscrptn);
         if(task_num <= 0)
            throw std::out_of_range("createTask(): task_num must be positive, got: " + std::to_string(task_num));
        if(zone_num <= 0)
            throw std::out_of_range("createTask(): zone_num must be positive, got: " + std::to_string(zone_num));
        DataStorage ds;
        ds.registerTasks();
        sqlite3_stmt* stmt;
        const char* sql = "INSERT INTO tasks (task_num,zone_num,task_dscrptn) VALUES (?,?,?);";
        sqlite3_prepare_v2(
        DATACENTER::DB,         // database handle
        sql,        // SQL with ? placeholders
        -1,         // length of sql (-1 = auto-detect)
        &stmt,      // prepared statement written here
        nullptr     // pointer to unused portion of sql (usually nullptr)
        );
        sqlite3_bind_int(stmt,1,task_num);
        sqlite3_bind_int(stmt,2,zone_num);
        sqlite3_bind_text(stmt,3,task_dscrptn.c_str(),-1,SQLITE_TRANSIENT);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        }

       void assignTask(){
       std::cout<<"You have opted to assign task to a member\n";
       std::cout<<"Enter the registration id of member to whom task is to be assigned:\n";
       std::cin>>a;
       std::cout<<"Enter the task number:\n";
       std::cin>>b;
       if(a <= 0)
            throw std::out_of_range("assignTask(): registration_id must be positive, got: " + std::to_string(a));
       if(b <= 0)
            throw std::out_of_range("assignTask(): task_num must be positive, got: " + std::to_string(b));
       DataStorage ds;
       ds.assignTasks();
       sqlite3_stmt* stmt;
       const char* sql = "INSERT INTO Assignd(task_num,regist_num) VALUES (?, ?);";
       sqlite3_prepare_v2(
       DATACENTER::DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
       sqlite3_bind_int(stmt,1,b);
       sqlite3_bind_int(stmt,2,a);
       sqlite3_step(stmt);
       sqlite3_finalize(stmt);
       }
     void tasklistshow(){
     DataStorage ds;
     ds.load("Zones");
         }
    };

    class Scheduler:public DepartmentModule{
    public:
       void execute(){
        std::cout<<"YOU HAVE ENETERED SCHEDULER\n";}
       static string date,time;
       static int nodl,lw;
       static string status;
      void scheduleWork(){
       int k;
        DataStorage ds;
        ds.ScheduleTasks();
       std::cout<<"Enter the task number:\n";
       std::cin>>k;
         if(k <= 0)
            throw std::out_of_range("scheduleWork(): task_num must be positive, got: " + std::to_string(k));
       std::cout<<"Enter the due date:\n";
       std::cin>>date;
       if(date.empty())
         throw std::invalid_argument("scheduleWork(): due date cannot be empty");
       std::cout<<"Enter number of days left(enter 0):\n";
       std::cin>>nodl;
       std::cout<<"Enter the time you wish to do work in next session:\n";
       std::cin>>time;
       std::cout<<"enter the last date worked on(0 if not yet started):\n";
       std::cin>>lw;
       std::cout<<"Enter the status of the task:\n";
        std::cin.ignore();
        std::getline(std::cin,status);
       sqlite3_stmt* stmt;
       const char* sql = "INSERT INTO Scheduler (task_num,due_date,time,nodl,lw,status) VALUES (?, ?,?,?,?,?);";
       sqlite3_prepare_v2(
       DATACENTER::DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
       sqlite3_bind_int(stmt,1,k);
       sqlite3_bind_text(stmt,2,date.c_str(),-1,SQLITE_TRANSIENT);
       sqlite3_bind_text(stmt,3,time.c_str(),-1,SQLITE_TRANSIENT);
       sqlite3_bind_int(stmt,4,nodl);
       sqlite3_bind_int(stmt,5,lw);
       sqlite3_bind_text(stmt,6,status.c_str(),-1,SQLITE_TRANSIENT);
       sqlite3_step(stmt);
       sqlite3_finalize(stmt);
    }
    void check_status(){
      int a;
      std::cout<<"Enter task number:\n";
      std::cin>>a;
      sqlite3_stmt* stmt;
      const std::string sql = "select task_num ,status from Scheduler where task_num=" + std::to_string(a) + ";";

      sqlite3_prepare_v2(
       DATACENTER::DB,         // database handle
       sql.c_str(),
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
       while(sqlite3_step(stmt)==SQLITE_ROW){
        std::cout<<"TASK NUM:"<<sqlite3_column_int(stmt, 0);
        std::cout<<"STATUS:"<<sqlite3_column_text(stmt,1);
       }
      }
     void showworkSchedule(){
     DataStorage ds;
     ds.load("Scheduler");
     }
 };
    class ResourceTracker:public DepartmentModule{
     private :
        int h,g;
     public:
          void execute(){
        std::cout<<"YOU HAVE ENETERED ResourceTracker\n";}
         static int tool_num,you,price,nt;
            static string tool_name;
        void updateinventory(){
            std::cout<<"Enter the tool number:\n";
            std::cin>>tool_num;
            std::cout<<"Enter the tool name:\n";
             std::cin.ignore();
            std::getline(std::cin,tool_name);
            std::cout<<"Enter the number of tools:\n";
            std::cin>>nt;
            std::cout<<"Enter the price of tool(in rs) at time of buying:\n";
            std::cin>>price;
            std::cout<<"Enter the number of years the tool had been used:\n";
            std::cin>>you;
             if(price <= 0)
                throw std::out_of_range("updateinventory(): price must be positive, got: " + std::to_string(price));
            if(nt <= 0)
                throw std::out_of_range("updateinventory(): number of tools must be positive, got: " + std::to_string(nt));
       DataStorage ds;
       ds.toolbox();
       sqlite3_stmt* stmt;
       const char *sql="Insert into Inventory (tool_num,tool_name,price,you,nt) VALUES(?,?,?,?,?);";
       sqlite3_prepare_v2(
       DATACENTER::DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
       sqlite3_bind_int(stmt,1,tool_num);
       sqlite3_bind_text(stmt,2,tool_name.c_str(),-1,SQLITE_TRANSIENT);
       sqlite3_bind_int(stmt,3,price);
       sqlite3_bind_int(stmt,4,you);
       sqlite3_bind_int(stmt,5,nt);
       sqlite3_step(stmt);
       sqlite3_finalize(stmt);
        }

     void Inventory_tracker(){
      std::cout<<"Enter the tool number being used:\n";
      std::cin>>h;
      std::cout<<"Enter the task number:\n";
      std::cin>>g;
       DataStorage ds;
       ds. tbuser();
      sqlite3_stmt* stmt;
      const char* sql="INSERT INTO tbuser (tool_num,task_num) VALUES(?,?);";
      sqlite3_prepare_v2(
       DATACENTER::DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
       sqlite3_bind_int(stmt,1,h);
       sqlite3_bind_int(stmt,2,g);
       sqlite3_step(stmt);
       sqlite3_finalize(stmt);
        }

      void Inventory_calculation(){
      DataStorage ds;
      ds.costTracker();
      sqlite3_stmt* stmt;
      sqlite3_stmt* stmt1;
      int a,b;
      const char *sql="Select tool_num,tool_name,nt,price,nt*price AS TOTAL_COST FROM Inventory;";
      sqlite3_prepare_v2(
       DATACENTER::DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
       const char* sql1="INSERT INTO Cost_TRACKER (tool_NUMBER, TOTAL_COST) VALUES(?,?);";
       sqlite3_prepare_v2(
       DATACENTER::DB,         // database handle
       sql1,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt1,      // prepared statement written here
       nullptr );
       while(sqlite3_step(stmt)==SQLITE_ROW){
        std::cout<<"TOOL NAME:"<<sqlite3_column_text(stmt, 0);
        std::cout<<"TOOL NUMBER:"<<sqlite3_column_int(stmt,1);
        a=sqlite3_column_int(stmt,1);
        sqlite3_bind_int(stmt1,1,a);
        std::cout<<"No of tools:"<<sqlite3_column_int(stmt,2);
        std::cout<<"PRICE OF EACH TOOL:"<<sqlite3_column_int(stmt,3);
        std::cout<<"TOTAL COST:"<<sqlite3_column_int(stmt,4);
        b=sqlite3_column_int(stmt,4);
        sqlite3_bind_int(stmt1,2,b);
        sqlite3_step(stmt1);
        sqlite3_reset(stmt1);
       }
       sqlite3_finalize(stmt);
       sqlite3_finalize(stmt1);
       }
     void Inventoryshow(){
     DataStorage ds;
     ds.load("Inventory");
     }
    };

     class ActivityTask:public TaskManager,public Scheduler{
    public:
        int zone_id;
        int actn;
        int a;
        virtual ~ActivityTask() {}
        void execute(){
       std::cout<<"Enter the task num:\n";
       std::cin>>actn;
       sqlite3_stmt *stmt;
       const char *c="Select zone_num from tasks where task_num = (?);";
       if(sqlite3_prepare_v2(DATACENTER::DB,c,-1,&stmt,nullptr) != SQLITE_OK)
           throw std::runtime_error("ActivityTask: DB prepare failed: " + string(sqlite3_errmsg(DATACENTER::DB)));
       sqlite3_bind_int(stmt,1,actn);
       sqlite3_step(stmt);
       zone_id=sqlite3_column_int(stmt,0);
       sqlite3_finalize(stmt);
       std::cout<<"Select from the following tasks :\n";
       std::cout<<"1.WaterTask\n"<<"2.GrassTrimTask\n"<<"3.DeWeedTask\n"<<"4.TreeShapeTask\n";
       std::cin>>a;
       if(a < 1 || a > 4)
          throw std::invalid_argument("ActivityTask: invalid task type, choose 1-4, got: " + std::to_string(a));
      }
    };

    class WaterTask: public ActivityTask{
    sqlite3_stmt* stmt;
    sqlite3_stmt* stmt1;
    public:
    int b,c,e,g,f,h;
    string d;
    virtual ~WaterTask() {}
    void execute(){
    std::cout<<"Enter time of task being done(starting):\n";
    std::cin>>b;
    std::cout<<"Enter the status\n";
     std::cin.ignore();
     std::getline(std::cin,d);
    std::cout<<"Enter the date of task being done:\n";
    std::cin>>e;
    std::cout<<"Enter the tool number:\n";
    std::cin>>g;
    std::cout<<"Enter the registration ID:\n";
    std::cin>>h;
     f = zone_id;
     DataStorage ds;
     ds.Watertask();
    const char *sql="INSERT INTO Water_task (Task_num,time_done,DATE,WATER_USAGE,TOOL_NUMBER,WORKER_ID,STATUS) VALUES(?,?,?,?,?,?,?);";
    sqlite3_prepare_v2(
       DATACENTER::DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );
     const char *sql1="SELECT zone_num,(nop_zone*0.5+not_zone*10)*(1+density_zone*0.2) AS WATER_USAGE FROM Zones;";
     sqlite3_prepare_v2(
       DATACENTER::DB,         // database handle
       sql1,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt1,      // prepared statement written here
       nullptr );
      while(sqlite3_step(stmt1)==SQLITE_ROW){
            if(f==sqlite3_column_int(stmt1,0)){
                c=sqlite3_column_int(stmt1,1);
            }
      };
     sqlite3_bind_int(stmt,1,actn);
     sqlite3_bind_int(stmt,2,b);
     sqlite3_bind_int(stmt,3,e);
     sqlite3_bind_int(stmt,4,c);
     sqlite3_bind_int(stmt,5,g);
     sqlite3_bind_int(stmt,6,h);
     sqlite3_bind_text(stmt,7,d.c_str(),-1,SQLITE_TRANSIENT);
     std::cout<<"The task "<<actn<<"aassigned at zone "<<ActivityTask::zone_id<<"has been completed\n";
     sqlite3_finalize(stmt);
     sqlite3_finalize(stmt1);
    }
    };

    class GrassTrimTask:public ActivityTask{
    sqlite3_stmt *stmt;
    public:
    int b,c,e,g,h;
    string d;
    virtual ~GrassTrimTask() {}
    void execute(){
    std::cout<<"Enter time of task being done(starting):\n";
    std::cin>>b;
    std::cout<<"Enter the status\n";
    std::cin.ignore();
     std::getline(std::cin,d);
    std::cout<<"Enter the date of task being done:\n";
    std::cin>>e;
    std::cout<<"Enter the tool number:\n";
    std::cin>>g;
    std::cout<<"Enter the registration ID:\n";
    std::cin>>h;
    DataStorage ds;
    ds.Grasstrimtask();
    const char *sql="INSERT INTO Grasstrim_task (Task_num,time_done,DATE,TOOL_NUMBER,WORKER_ID,STATUS) VALUES(?,?,?,?,?,?);";
     if(sqlite3_prepare_v2(DATACENTER::DB,sql,-1,&stmt,nullptr) != SQLITE_OK)
        throw std::runtime_error("GrassTrimTask: DB prepare failed: " + string(sqlite3_errmsg(DATACENTER::DB)));

     sqlite3_bind_int(stmt,1,task_num);
     sqlite3_bind_int(stmt,2,b);
     sqlite3_bind_int(stmt,3,e);
     sqlite3_bind_int(stmt,4,g);
     sqlite3_bind_int(stmt,5,h);
     sqlite3_bind_text(stmt,6,d.c_str(),-1,SQLITE_TRANSIENT);
     std::cout<<"The task "<<actn<<"aassigned at zone "<<ActivityTask::zone_id<<"has been completed\n";
     sqlite3_finalize(stmt);
    }
    };

    class DeWeedTask:public ActivityTask{
    public:
    sqlite3_stmt *stmt;
    virtual ~DeWeedTask() {}
    void execute(){
    int b,e,g,h;
    string d;
    std::cout<<"Enter time of task being done(starting):\n";
    std::cin>>b;
    std::cout<<"Enter the status\n";
    std::cin.ignore();
     std::getline(std::cin,d);
    std::cout<<"Enter the date of task being done:\n";
    std::cin>>e;
    std::cout<<"Enter the tool number:\n";
    std::cin>>g;
    std::cout<<"Enter the registration ID:\n";
    std::cin>>h;
     DataStorage ds;
     ds.Deweedtask();
    const char *sql="INSERT INTO Deweed_task (Task_num,time_done,DATE,TOOL_NUMBER,WORKER_ID,STATUS) VALUES(?,?,?,?,?,?);";
    sqlite3_prepare_v2(
       DATACENTER::DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );

     sqlite3_bind_int(stmt,1,actn);
     sqlite3_bind_int(stmt,2,b);
     sqlite3_bind_int(stmt,3,e);
     sqlite3_bind_int(stmt,4,g);
     sqlite3_bind_int(stmt,5,h);
     sqlite3_bind_text(stmt,6,d.c_str(),-1,SQLITE_TRANSIENT);
     std::cout<<"The task "<<actn<<"aassigned at zone "<<ActivityTask::zone_id<<"has been completed\n";
     sqlite3_finalize(stmt);
    }
    };

    class TreeShapeTask:public ActivityTask{
    sqlite3_stmt *stmt;
    public:
    virtual ~TreeShapeTask() {}
    void execute(){
    int b,e,g,h;
    string d;
    std::cout<<"Enter time of task being done(starting):\n";
    std::cin>>b;
    std::cout<<"Enter the status\n";
    std::cin.ignore();
     std::getline(std::cin,d);
    std::cout<<"Enter the date of task being done:\n";
    std::cin>>e;
    std::cout<<"Enter the tool number:\n";
    std::cin>>g;
    std::cout<<"Enter the registration ID:\n";
    std::cin>>h;
    DataStorage ds;
    ds.Treeshapetask();
    const char *sql="INSERT INTO Treeshape_task(Task_num,time_done,DATE,TOOL_NUMBER,WORKER_ID,STATUS) VALUES(?,?,?,?,?,?);";
    sqlite3_prepare_v2(
       DATACENTER::DB,         // database handle
       sql,        // SQL with ? placeholders
       -1,         // length of sql (-1 = auto-detect)
       &stmt,      // prepared statement written here
       nullptr );

     sqlite3_bind_int(stmt,1,actn);
     sqlite3_bind_int(stmt,2,b);
     sqlite3_bind_int(stmt,3,e);
     sqlite3_bind_int(stmt,4,g);
     sqlite3_bind_int(stmt,5,h);
     sqlite3_bind_text(stmt,6,d.c_str(),-1,SQLITE_TRANSIENT);
     std::cout<<"The task "<<actn<<"aassigned at zone "<<ActivityTask::zone_id<<"has been completed\n";
     sqlite3_finalize(stmt);
    }
    };

sqlite3* DATACENTER::DB = nullptr;
#include "loading.cpp"
#include "namalt.cpp"
string DepartmentModule::name;
int DepartmentModule::regid = 0;
string registration::course;
int registration::sem_number = 0;
int registration::zone_num = 0;
int registration::nop_zone = 0;
int registration::density_zone = 0;
int registration::not_zone = 0;
string registration::zone_name;
int TaskManager::task_num = 0;
int TaskManager::zone_num = 0;
string TaskManager::task_dscrptn;
string Scheduler::date;
string Scheduler::time;
int Scheduler::nodl=0;
int Scheduler::lw=0;
string Scheduler::status;
int ResourceTracker::tool_num=0;
int ResourceTracker::you=0;
int ResourceTracker::price=0;
int ResourceTracker::nt=0;
string ResourceTracker::tool_name;

int main(){
    DATACENTER dc;
    registration rr;
    rr.execute();

    int choice=-1;
    try{
    if(choice != 0){
        std::cout << "\n=== ANKUR SYSTEM ===\n\n\n";
        std::cout<<"[[[[[THESE ARE TABLE NAMES , USE THESE ONLY TO AVOID CASE-SENSITIVITY RELATED  ISSUES}}}}}\n";
        std::cout << "Available Tables (Case-Sensitive): \n";
        std::cout << "Users, Zones, Tasks, Assignd, Scheduler, Inventory, \n";
        std::cout << "Tracker, Cost_TRACKER, Water_task, Grasstrim_task, \n";
        std::cout << "Deweed_task, Treeshape_task, logs\n\n";
        std::cout<<"IT IS SUGGESTED STRONGLY THAT YOU SEE THE TABLES ONCE BEFORE MAKING ANY CHANGES , AS SCHEMA MAY HAVE CHANGED\n\n";
        std::cout << "1. Register user\n";
        std::cout << "2. Create zone\n";
        std::cout << "3. Create task\n";
        std::cout << "4. Assign task\n";
        std::cout << "5. Schedule task\n";
        std::cout << "6. Inventory update\n";
        std::cout << "7. Execute activity task\n";
        std::cout << "8. Show tables\n";
        std::cout<<"9.Write comments\n";
        std::cout<<"10.Show user comments\n";
        std::cout<<"11.ALTER TABLES\n";
        std::cout<<"12.SIGNIFICANT CALCULATIONS \n";
        std::cout << "0. Exit\n";
        std::cout << "Enter the Choice: ";
        std::cin >> choice;
        std::cin.ignore();
        if(choice == 1){
            registration r;
            r.execute();
            r.registerUser();
        }
        else if(choice == 2){
            registration r;
            r.Zone_process();
        }
        else if(choice == 3){
            TaskManager t;
            t.execute();
            t.createTask();
        }
        else if(choice == 4){
            TaskManager t;
            t.assignTask();
        }
        else if(choice == 5){
            Scheduler s;
            s.execute();
            s.scheduleWork();
        }
        else if(choice == 6){
            ResourceTracker rt;
            rt.execute();
            rt.updateinventory();
        }
        else if(choice == 7){
            ActivityTask at;
       if(at.a==1)
        {
           WaterTask* wt = new WaterTask();
           wt->execute();
           delete wt;
           wt = nullptr;
        }
      else if(at.a==2)
      {
         GrassTrimTask* gt = new GrassTrimTask();
        gt->execute();
        delete gt;
        gt = nullptr;
      }
      else if(at.a==3)
      {
        DeWeedTask* dw = new DeWeedTask();
        dw->execute();
        delete dw;
        dw = nullptr;
      }
      else if(at.a==4)
      {
           TreeShapeTask* ts = new TreeShapeTask();
           ts->execute();
           delete ts;
           ts = nullptr;
      }
      else{
        std::cout<<"NO such option available\n";
      }
        }
      else if(choice == 8){
    DataStorage ds;
    int opt;
    std::cout<<"1. Show all tables\n";
    std::cout<<"2. Show specific table\n";
    std::cin>>opt;

    if(opt == 1){
        ds.database();
    }
    else if(opt == 2){
        std::string tname;
        std::cout<<"Enter table name:\n";
        std::cin>>tname;
        ds.load(tname);
    }
    else{
        std::cout<<"Invalid option\n";
    }
   }
   else if(choice==9){
    std::ofstream f("comments.txt",std::ios::app);
    string name,comment;
    int regnn;
    std::cout<<"Enter name: \n";
    std::cin>>name;
    f << name <<",";
    std::cout<<"Enter regn no: \n";
    std::cin>>regnn;
    f<< regnn<<",";
    std::cout<<"Enter your comment: \n";
    std::cin>>comment;
    f<< comment << "\n";
    f.close();
   }
   else if(choice==10){
    std::ifstream f("comments.txt");
    string fulline;
     while(getline(f, fulline)) {
    std::cout << fulline << "\n";
   }
    f.close();
  }
 else if(choice==11){
    int alopt;
    std::cout<<"---CAUTION----THIS WILL DO CHANGES THAT WILL ALTER SCHEMA DESIGN POTENTIALLY---CAUTION---\n";
    std::cout<<"The following are the options:\n";
    std::cout<<"1.DELETE ROW\n";
    std::cout<<"2.DROP COLUMN\n";
    std::cout<<"3.DROP TABLE\n";
    std::cout<<"4.UPDATE TABLE\n";
    std::cout<<"5.RENAME COLUMN\n";
    std::cout<<"6.RENAME TABLE NAME\n";
    std::cout<<"ENTER YOUR DESIRED OPTION:";
    std::cin>>alopt;

    if(alopt==1){
        string tbname, parameter;
        int rowval;
        std::cout<<"Enter table name: ";
        std::cin>>tbname;
        std::cout<<"Enter column (parameter) to match: ";
        std::cin>>parameter;
        std::cout<<"Enter the row value to delete: ";
        std::cin>>rowval;
        try{
            ALTER::del_row(tbname, parameter, rowval);
            std::cout<<"Row deleted successfully.\n";
        } catch(std::exception& e){
            std::cout<<"Error: "<<e.what()<<"\n";
        }
    }
    else if(alopt==2){
        string tbname, colname;
        std::cout<<"Enter table name: ";
        std::cin>>tbname;
        std::cout<<"Enter column name to drop: ";
        std::cin>>colname;
        try{
            ALTER::drop_col(tbname, colname);
            std::cout<<"Column dropped successfully.\n";
        } catch(std::exception& e){
            std::cout<<"Error: "<<e.what()<<"\n";
        }
    }
    else if(alopt==3){
        string tbname;
        std::cout<<"Enter table name to drop: ";
        std::cin>>tbname;
        try{
            ALTER::drop_table(tbname);
            std::cout<<"Table dropped successfully.\n";
        } catch(std::exception& e){
            std::cout<<"Error: "<<e.what()<<"\n";
        }
    }
    else if(alopt==4){
        string tbname, parameter;
        int newval;
        std::cout<<"Enter table name: ";
        std::cin>>tbname;
        std::cout<<"Enter column to update: ";
        std::cin>>parameter;
        std::cout<<"Enter new value: ";
        std::cin>>newval;
        try{
            ALTER::ADDITION obj;
            obj.update(tbname, parameter, newval);
            std::cout<<"Table updated successfully.\n";
        } catch(std::exception& e){
            std::cout<<"Error: "<<e.what()<<"\n";
        }
    }
    else if(alopt==5){
        string tbname, oldcol, newcol;
        std::cout<<"Enter table name: ";
        std::cin>>tbname;
        std::cout<<"Enter current column name: ";
        std::cin>>oldcol;
        std::cout<<"Enter new column name: ";
        std::cin>>newcol;
        try{
            ALTER::ADDITION obj;
            obj.rename_clnnm(tbname, oldcol, newcol);
            std::cout<<"Column renamed successfully.\n";
        } catch(std::exception& e){
            std::cout<<"Error: "<<e.what()<<"\n";
        }
    }
    else if(alopt==6){
        string tbname, newtbname;
        std::cout<<"Enter current table name: ";
        std::cin>>tbname;
        std::cout<<"Enter new table name: ";
        std::cin>>newtbname;
        try{
            ALTER::ADDITION obj;
            obj.rename_tbn(tbname, newtbname);
            std::cout<<"Table renamed successfully.\n";
        } catch(std::exception& e){
            std::cout<<"Error: "<<e.what()<<"\n";
        }
    }
    else{
        std::cout<<"Invalid option.\n";
    }
}
    else if(choice==12){
    int calopt;
    std::cout<<"Enter what item's total usage you want to calculate:\n";
    std::cout<<"1.TOOLS\n";
    std::cout<<"2.WATER\n";
    std::cin>>calopt;

    if(calopt == 1){
        // Calls Calculation_Usage<int>("Tools") — sums all TOTAL_COST from Cost_TRACKER
        try{
            int result = Calculation_Usage<int>("Tools");
            std::cout<<"Total Tools Cost Usage: "<<result<<"\n";
        } catch(std::exception& e){
            std::cerr<<"[Calc Error] "<<e.what()<<"\n";
        }
    }
    else if(calopt == 2){
        // Two sub-options: total water usage OR usage for a specific task+date
        int wateropt;
        std::cout<<"1. Total WATER usage (all tasks)\n";
        std::cout<<"2. WATER usage for a specific task and date\n";
        std::cin>>wateropt;

        if(wateropt == 1){
            // Calls Calculation_Usage<int>("Water") — sums all WATER_USAGE from Water_task
            try{
                int result = Calculation_Usage<int>("Water");
                std::cout<<"Total Water Usage: "<<result<<"\n";
            } catch(std::exception& e){
                std::cerr<<"[Calc Error] "<<e.what()<<"\n";
            }
        }
        else if(wateropt == 2){
            // Calls Calculation_Usage<int>(task_id, date) — fetches WATER_USAGE for one row
            int task_id, date;
            std::cout<<"Enter Task ID: ";
            std::cin>>task_id;
            std::cout<<"Enter Date (integer): ";
            std::cin>>date;
            try{
                int result = Calculation_Usage<int>(task_id, date);
                std::cout<<"Water Usage for Task "<<task_id<<" on Date "<<date<<": "<<result<<"\n";
            } catch(std::exception& e){
                std::cerr<<"[Calc Error] "<<e.what()<<"\n";
            }
        }
        else{
            std::cout<<"Invalid water option.\n";
        }
    }
    else{
        std::cout<<"Invalid option.\n";
    }
}

  }
   } catch (const std::invalid_argument& e) {
            std::cerr << "\n[Input Error]  " << e.what() << "\n";
        } catch (const std::out_of_range& e) {
            std::cerr << "\n[Range Error]  " << e.what() << "\n";
        } catch (const std::runtime_error& e) {
            std::cerr << "\n[DB Error]     " << e.what() << "\n";
        } catch (const std::exception& e) {
            std::cerr << "\n[Unknown Error] " << e.what() << "\n";
        }
}
