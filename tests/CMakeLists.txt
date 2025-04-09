include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

# Явно указываем исходные файлы для тестового исполняемого файла
add_executable(test_database 
    test_database.cpp
    ../src/database.c  # Добавляем исходный файл с реализациями
)

target_link_libraries(test_database
    SQLite::SQLite3
    Catch2::Catch2WithMain
)

# Добавляем include-директории
target_include_directories(test_database PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../includes
)
