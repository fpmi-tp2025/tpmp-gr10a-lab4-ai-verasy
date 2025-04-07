#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/database.h"

sqlite3* db_connect() {
    sqlite3 *db;
    int rc = sqlite3_open("auction.db", &db);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return NULL;
    }
    return db;
}

void db_init() {
    sqlite3 *db = db_connect();
    if (!db) return;
    
    char *check_tables = "SELECT name FROM sqlite_master WHERE type='table' AND name='farms';";
    sqlite3_stmt *stmt;
    
    if (sqlite3_prepare_v2(db, check_tables, -1, &stmt, NULL) != SQLITE_OK || 
        sqlite3_step(stmt) != SQLITE_ROW) {
        system("sqlite3 auction.db < ../database/init_db.sql");
    }
    
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int db_execute_query(const char* query, 
                    int (*callback)(void*, int, char**, char**), 
                    void* data) {
    sqlite3 *db = db_connect();
    if (!db) return SQLITE_ERROR;
    
    char *err_msg = 0;
    int rc = sqlite3_exec(db, query, callback, data, &err_msg);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    
    sqlite3_close(db);
    return rc;
}

int db_close(sqlite3* db) {
    return sqlite3_close(db);
}
