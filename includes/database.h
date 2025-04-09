#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Устанавливает соединение с базой данных SQLite
 * @return Указатель на объект базы данных или NULL при ошибке
 * @note Функция автоматически создает файл БД, если он не существует
 */
sqlite3* db_connect(void);

/**
 * @brief Инициализирует структуру базы данных (создает таблицы)
 * @note Вызывает db_connect() внутри себя
 */
void db_init(void);

/**
 * @brief Выполняет SQL-запрос к базе данных
 * @param query Строка с SQL-запросом
 * @param callback Функция обратного вызова для обработки результатов
 * @param data Пользовательские данные, передаваемые в callback
 * @return Код результата SQLite (SQLITE_OK при успехе)
 */
int db_execute_query(const char* query, 
                    int (*callback)(void*, int, char**, char**), 
                    void* data);

/**
 * @brief Закрывает соединение с базой данных
 * @param db Указатель на объект базы данных
 * @return Код результата SQLite (SQLITE_OK при успехе)
 */
int db_close(sqlite3* db);

#ifdef __cplusplus
}
#endif

#endif /* DATABASE_H */
