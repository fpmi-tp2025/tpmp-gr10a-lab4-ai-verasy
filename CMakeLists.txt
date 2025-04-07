cmake_minimum_required(VERSION 3.10)
project(FurAuction)

# Настройки компиляции
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")

# Поиск SQLite3
find_package(SQLite3 REQUIRED)

# Основная библиотека
add_library(database_lib src/database.c)
target_link_libraries(database_lib SQLite::SQLite3)

# Тесты
enable_testing()
add_subdirectory(tests)
