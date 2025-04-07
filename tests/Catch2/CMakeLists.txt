# Вариант 1: Используем Catch2 как header-only библиотеку
add_library(Catch2 INTERFACE)
target_include_directories(Catch2 INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Catch2/single_include
)

add_executable(test_database test_database.cpp)
target_link_libraries(test_database 
    database_lib 
    SQLite::SQLite3 
    Catch2
)
