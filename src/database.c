#include <sqlite3.h>
#include <stdio.h>

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
    
    char *sql = "SELECT name FROM sqlite_master WHERE type='table' AND name='farms';";
    sqlite3_stmt *stmt;
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        // Если таблиц нет - создаем
        system("sqlite3 auction.db < ../database/init_db.sql");
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
