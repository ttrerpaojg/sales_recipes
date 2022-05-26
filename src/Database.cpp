#include "include/Database.hpp"
#include <stdexcept>
#include <iostream>


sqlite3* Database::ConnectToDataBase(char* dbName){
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open(dbName, &DB);

    if (exit){
        throw std::runtime_error("Error while opening Database connection.");
    }
    else{
        std::cout << "Database " << dbName << " opened." << std::endl;
    }

    return DB;
  
};

int Database::CloseDatabaseConnection(sqlite3* db){
    int close = sqlite3_close(db);

    return close;
};