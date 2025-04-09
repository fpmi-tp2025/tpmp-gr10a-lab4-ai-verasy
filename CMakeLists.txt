cmake_minimum_required(VERSION 3.10)
project(FurAuction)

# Опция для включения coverage (по умолчанию ON)
option(ENABLE_COVERAGE "Enable code coverage reporting" ON)

# Настройки компилятора
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Настройки coverage (только если включено)
if(ENABLE_COVERAGE)
    message(STATUS "Enabling code coverage instrumentation")
    # Для C файлов
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
    # Для C++ файлов
    add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fprofile-arcs -ftest-coverage>)
    # Библиотека для coverage
    link_libraries(gcov)
endif()

# Поиск зависимостей
find_package(SQLite3 REQUIRED)

# Основная библиотека
add_library(database_lib src/database.c)
target_include_directories(database_lib PUBLIC includes)
target_link_libraries(database_lib PRIVATE SQLite::SQLite3)

# Тесты
enable_testing()
add_subdirectory(tests)
