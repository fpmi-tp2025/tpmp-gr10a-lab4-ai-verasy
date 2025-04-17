#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>

extern sqlite3 *db;  // Глобальное подключение к БД

// Инициализация БД
int init_database();

// Закрытие БД
void close_database();

// Выполнение SQL-запроса
int execute_sql(const char *sql, int (*callback)(void*, int, char**, char**));

#endif
