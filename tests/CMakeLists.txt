# Автоматическая загрузка Catch2
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

# Объекты для тестов
add_library(database_objects OBJECT ../src/database.c)
target_include_directories(database_objects PRIVATE ../includes)

# Исполняемый файл тестов
add_executable(test_database
    test_database.cpp
    $<TARGET_OBJECTS:database_objects>
)

# Настройки линковки
target_link_libraries(test_database
    PRIVATE
    SQLite::SQLite3
    Catch2::Catch2WithMain
    gcov  # Важно: добавляем gcov явно
)

# Добавляем тест в CTest
add_test(NAME database_tests COMMAND test_database)
