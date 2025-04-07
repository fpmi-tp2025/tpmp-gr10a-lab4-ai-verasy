
#define CATCH_CONFIG_MAIN
#include "Catch2/single_include/catch2/catch.hpp"
#include "../../includes/database.h"

TEST_CASE("Database connection", "[db]") {
    sqlite3* db = db_connect();
    REQUIRE(db != nullptr);
    REQUIRE(db_close(db) == SQLITE_OK);
}

TEST_CASE("Database initialization", "[db]") {
    // Тестовая БД
    system("cp auction.db auction_backup.db 2>/dev/null || true");
    remove("auction.db");
    
    db_init();
    
    sqlite3* db = db_connect();
    REQUIRE(db != nullptr);
    
    // Проверяем существование таблиц
    int table_count = 0;
    auto callback = [](void* data, int argc, char** argv, char** colNames) -> int {
        (*(int*)data)++;
        return 0;
    };
    
    REQUIRE(db_execute_query("SELECT name FROM sqlite_master WHERE type='table';", 
                           callback, &table_count) == SQLITE_OK);
    REQUIRE(table_count >= 3); // farms, fur_products, auction_results
    
    db_close(db);
    system("mv auction_backup.db auction.db 2>/dev/null || true");
}

TEST_CASE("Query execution", "[db]") {
    db_init(); // Инициализируем тестовые данные
    
    sqlite3* db = db_connect();
    REQUIRE(db != nullptr);
    
    int row_count = 0;
    auto callback = [](void* data, int argc, char** argv, char** colNames) -> int {
        (*(int*)data)++;
        return 0;
    };
    
    REQUIRE(db_execute_query("SELECT * FROM farms;", callback, &row_count) == SQLITE_OK);
    REQUIRE(row_count == 3); // 3 тестовые фермы из init_db.sql
    
    db_close(db);
}
