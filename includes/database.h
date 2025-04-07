#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>

// Подключение к БД
sqlite3* db_connect();

// Инициализация БД
void db_init();

// Выполнение запроса
int db_execute_query(const char* query, 
                    int (*callback)(void*, int, char**, char**), 
                    void* data);

// Закрытие соединения
int db_close(sqlite3* db);

#endif
