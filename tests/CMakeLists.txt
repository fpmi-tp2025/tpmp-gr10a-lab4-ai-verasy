# Указываем явный путь к исходникам
add_executable(test_database 
    ${CMAKE_CURRENT_SOURCE_DIR}/test_database.cpp
)

target_link_libraries(test_database 
    database_lib 
    SQLite::SQLite3 
    Catch2
)

add_test(
    NAME database_tests
    COMMAND test_database
)
