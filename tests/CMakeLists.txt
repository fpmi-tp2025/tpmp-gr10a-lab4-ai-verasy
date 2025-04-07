# Добавляем подмодуль Catch2
add_subdirectory(Catch2)

add_executable(test_database test_database.cpp)

# Подключаем директорию с заголовками Catch2
target_include_directories(test_database PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Catch2/single_include
)

target_link_libraries(test_database 
    database_lib 
    SQLite::SQLite3
)
