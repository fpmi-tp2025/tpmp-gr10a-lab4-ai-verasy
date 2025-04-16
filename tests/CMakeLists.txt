# Удаляем объекты и используем готовую библиотеку
add_executable(test_database
    test_database.cpp
)

# Линкуем с нашей библиотекой и зависимостями
target_link_libraries(test_database
    PRIVATE
    database_lib  # Добавляем нашу библиотеку
    SQLite::SQLite3
    Catch2::Catch2WithMain
    gcov
)

# Добавляем путь к заголовочным файлам
target_include_directories(test_database PRIVATE ${CMAKE_SOURCE_DIR}/includes)
