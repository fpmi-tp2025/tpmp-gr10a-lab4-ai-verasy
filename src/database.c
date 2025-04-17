#include "database.h"
#include <stdio.h>

sqlite3 *db;

int init_database() {
    int rc = sqlite3_open("auction.db", &db);
    if (rc) {
        fprintf(stderr, "Не удается открыть БД: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    return 1;
}

void close_database() {
    sqlite3_close(db);
}

int execute_sql(const char *sql, int (*callback)(void*,int,char**,char**)) {
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL ошибка: %s\n", err_msg);
        sqlite3_free(err_msg);
        return 0;
    }
    return 1;
}
