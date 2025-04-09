#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>

#ifdef __cplusplus
extern "C" {
#endif

sqlite3* db_connect(void);
void db_init(void);
int db_execute_query(const char* query, 
                    int (*callback)(void*, int, char**, char**), 
                    void* data);
int db_close(sqlite3* db);

#ifdef __cplusplus
}
#endif

#endif // DATABASE_H
