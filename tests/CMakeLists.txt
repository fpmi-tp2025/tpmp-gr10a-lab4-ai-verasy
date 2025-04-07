# Добавляем исполняемый файл для тестов
add_executable(test_database test_database.cpp)

# Линкуем с нашей библиотекой и зависимостями
target_link_libraries(test_database 
    database_lib 
    SQLite::SQLite3 
    Catch2)

# Регистрируем тест для CTest
add_test(
    NAME database_tests
    COMMAND test_database
)
