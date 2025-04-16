# Автоматическая загрузка Catch2
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

# Исполняемый файл тестов (БЕЗ повторной компиляции database.c)
add_executable(test_database
    test_database.cpp
)

# Линкуем с нашей библиотекой и зависимостями
target_link_libraries(test_database
    PRIVATE
    database_lib       # Используем уже скомпилированную библиотеку
    SQLite::SQLite3    # SQLite3 уже есть в database_lib, но можно оставить для явности
    Catch2::Catch2WithMain
    gcov
)

# Добавляем путь к заголовочным файлам
target_include_directories(test_database PRIVATE ${CMAKE_SOURCE_DIR}/includes)

# Добавляем тест в CTest
add_test(NAME database_tests COMMAND test_database)
