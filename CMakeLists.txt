cmake_minimum_required(VERSION 3.10)
project(FurAuction LANGUAGES C)  # Явно указываем язык

# Настройки компиляции
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")

# Поиск SQLite3
find_package(SQLite3 REQUIRED)

# Основная библиотека
add_library(database_lib STATIC src/database.c)
target_include_directories(database_lib PUBLIC 
    ${CMAKE_SOURCE_DIR}/includes
)
target_link_libraries(database_lib PRIVATE SQLite::SQLite3)

# Включение тестов
enable_testing()
add_subdirectory(tests)
